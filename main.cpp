#include "shared_resource.h"

int main() {
    SharedResource resource;

    auto start_time_no_lock = std::chrono::high_resolution_clock::now();
    std::thread t1(&SharedResource::increment, &resource, false);
    std::thread t2(&SharedResource::decrement, &resource, false);
    t1.join();
    t2.join();
    auto end_time_no_lock = std::chrono::high_resolution_clock::now();
    std::cout << "Без блокировки: " << resource.get_value() << " Время: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_time_no_lock - start_time_no_lock).count()
              << " мкс" << std::endl;

    auto start_time_lock = std::chrono::high_resolution_clock::now();
    std::thread t3(&SharedResource::increment, &resource, true);
    std::thread t4(&SharedResource::decrement, &resource, true);
    t3.join();
    t4.join();
    auto end_time_lock = std::chrono::high_resolution_clock::now();
    std::cout << "С блокировкой: " << resource.get_value() << " Время: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end_time_lock - start_time_lock).count()
              << " мкс" << std::endl;

    return 0;
}
