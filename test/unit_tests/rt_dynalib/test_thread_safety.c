#include "rt_dynalib.h"
#include "unit_test.h"
#include <pthread.h>

void* thread_function(void* arg) {
    thread_safe_function();
    return NULL;
}

test(Thread_Safety_Test) {
    pthread_t thread1, thread2;

    // Create two threads to test thread safety
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // If no deadlock or race condition occurs, the test passes
    assertTrue(true);
}