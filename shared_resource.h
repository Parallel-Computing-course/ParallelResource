#ifndef SHARED_RESOURCE_H
#define SHARED_RESOURCE_H

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

constexpr int ITERATIONS = 38000;

class SharedResource {
public:
    void increment(bool use_lock);
    void decrement(bool use_lock);
    int get_value() const;
private:
    int shared_value = 0;
    std::mutex mtx;
};

#endif
