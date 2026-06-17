#pragma once

#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <atomic>
#include <condition_variable>


class Executor {
    private:
        const std::vector<int>& list;
        std::atomic<long long> sum;
        int max;
        std::mutex mtx;

        std::condition_variable cv;
        bool maxCalculated = false;

        std::jthread findMaxThread;
        std::jthread findSumThread;

        void findMax() {
            if (list.empty()) {
                max = 0;
                return;
            }

            int local_max = list[0];

            for (int i = 0; i < list.size(); i++) {
                if (list[i] > local_max) {
                    local_max = list[i];
                }
            }

            max = local_max;

            {
                std::lock_guard<std::mutex> lock(mtx);
                maxCalculated = true;
            }
            cv.notify_one();
        };

        void findSum() {
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return maxCalculated; });
            }

            long long local_sum1 = 0;
            long long local_sum2 = 0;

            // Делим список на две части и вычисляем сумму в двух потоках
            auto mid = list.size() / 2;
            std::jthread sumThread1([this, mid, &local_sum1]() {
                for (size_t i = 0; i < mid; ++i) {
                    local_sum1 += list[i];
                }
            });
            std::jthread sumThread2([this, mid, &local_sum2]() {
                for (size_t i = mid; i < list.size(); ++i) {
                    local_sum2 += list[i];
                }
            });

            sumThread1.join();
            sumThread2.join();
            sum = local_sum1 + local_sum2;
        };

    public:
        Executor(const std::vector<int>& list) : list(list), sum(0), max(0) {};
        
        void calculateMultithread();

        long long getSum() const {
            return sum;
        };
        int getMax() const {
            return max;
        };
};
