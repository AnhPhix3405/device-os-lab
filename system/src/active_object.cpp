/**
 ******************************************************************************
  Copyright (c) 2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "active_object.h"
#include "system_threading.h"
#include "spark_wiring_interrupts.h"
#include "debug.h"

using namespace particle;

#if PLATFORM_THREADING

#include <string.h>
#include "concurrent_hal.h"
#include "timer_hal.h"
#include "rng_hal.h"

void ActiveObjectBase::start_thread()
{
    const auto r = os_thread_create(&_thread, configuration.task_name, configuration.priority, run_active_object, this,
            configuration.stack_size);
    SPARK_ASSERT(r == 0);
    // prevent the started thread from running until the thread id has been assigned
    // so that calls to isCurrentThread() work correctly
    while (!started) {
        os_thread_yield();
    }
}


void ActiveObjectBase::run() {
    started = true;
    srand(HAL_RNG_GetRandomNumber()); // Seed random number generator

    for (;;) {
        if (!process()) {
            configuration.background_task();
        }
    }
}

bool ActiveObjectBase::process() {
    Item item = nullptr;
    if (take(item) && item) {
        (*item)(); // Execute the message
        return true;
    }
    return false;
}

void ActiveObjectBase::run_active_object(void* data)
{
    const auto that = static_cast<ActiveObjectBase*>(data);
    that->run();
}

#endif // PLATFORM_THREADING

void ISRTaskQueue::enqueue(Task* task) {
    ATOMIC_BLOCK() {
        if (task->next || task->prev || lastTask_ == task) {
            return; // Task already in queue
        }
        if (lastTask_) {
            lastTask_->next = task;
        } else {
            firstTask_ = task;
        }
        task->next = nullptr;
        task->prev = lastTask_;
        lastTask_ = task;
    }
}

void ISRTaskQueue::remove(Task* task) {
    ATOMIC_BLOCK() {
        if (task->next) {
            task->next->prev = task->prev;
        } else if (lastTask_ == task) {
            lastTask_ = task->prev;
        }
        if (task->prev) {
            task->prev->next = task->next;
        } else if (firstTask_ == task) {
            firstTask_ = task->next;
        }
        task->next = nullptr;
        task->prev = nullptr;
    }
}

bool ISRTaskQueue::process() {
    if (!firstTask_) {
        return false;
    }
    Task* task = nullptr;
    ATOMIC_BLOCK() {
        if (!firstTask_) {
            return false;
        }
        // Take task object from the queue
        task = firstTask_;
        firstTask_ = task->next;
        if (firstTask_) {
            firstTask_->prev = nullptr;
            task->next = nullptr;
        } else {
            lastTask_ = nullptr;
        }
    }
    // Invoke task function
    task->func(task);
    return true;
}
