#include "shared_resource.h"

void SharedResource::increment(bool use_lock) {
    for (int i = 0; i < ITERATIONS; i++) {
        if (use_lock) {
            mtx.lock();
        }
        shared_value++;
        if (use_lock) {
            mtx.unlock();
        }
    }
}

void SharedResource::decrement(bool use_lock) {
    for (int i = 0; i < ITERATIONS; i++) {
        if (use_lock) {
            mtx.lock();
        }
        shared_value--;
        if (use_lock) {
            mtx.unlock();
        }
    }
}

int SharedResource::get_value() const {
    return shared_value;
}
