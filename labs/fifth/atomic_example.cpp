#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <chrono>

using namespace std;
using namespace std::chrono;

void incrementWithMutex(int& counter, mutex& mtx, int increments) {
    for(int i = 0; i < increments; ++i) {
        lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

void incrementWithAtomic(atomic<int>& counter, int increments) {
    for(int i = 0; i < increments; ++i) {
        ++counter;
    }
}

int main() {
    const int numThreads = thread::hardware_concurrency();
    const int increments = 1000000;

    // С использованием mutex
    int counterMutex = 0;
    mutex mtx;
    vector<thread> threads;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < numThreads; ++i)
        threads.emplace_back(incrementWithMutex, ref(counterMutex), ref(mtx), increments);
    for(auto& t : threads) t.join();
    auto end = high_resolution_clock::now();
    auto durationMutex = duration_cast<milliseconds>(end - start).count();
    cout << "Mutex counter final value: " << counterMutex << "\n";
    cout << "Time with mutex: " << durationMutex << " ms\n";

    // С использованием atomic
    atomic<int> counterAtomic(0);
    threads.clear();
    start = high_resolution_clock::now();
    for(int i = 0; i < numThreads; ++i)
        threads.emplace_back(incrementWithAtomic, ref(counterAtomic), increments);
    for(auto& t : threads) t.join();
    end = high_resolution_clock::now();
    auto durationAtomic = duration_cast<milliseconds>(end - start).count();
    cout << "Atomic counter final value: " << counterAtomic << "\n";
    cout << "Time with atomic: " << durationAtomic << " ms\n";

    return 0;
}
