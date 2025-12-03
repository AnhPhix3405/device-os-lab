#define DYNALIB_IMPORT
#include "rt_dynalib.h"
#include <pthread.h>

static pthread_mutex_t dynalib_mutex = PTHREAD_MUTEX_INITIALIZER;

void thread_safe_function() {
    pthread_mutex_lock(&dynalib_mutex);
    // Critical section code
    pthread_mutex_unlock(&dynalib_mutex);
}
