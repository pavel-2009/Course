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

            max = list[0];

            for (int i = 0; i < list.size(); i++) {
                std::lock_guard<std::mutex> lock(mtx);

                std::cout << "Process: findMax, index: " << i;
                std::cout << "\nMax: " << max << std::endl;
                if (list[i] > max) {
                    max = list[i];
                }
            }
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

            sum = 0;

            for (int i = 0; i < list.size(); i++) {
                std::lock_guard<std::mutex> lock(mtx);

                std::cout << "Process: findSum, index: " << i;
                sum += list[i];
                std::cout << "\nSum: " << sum << std::endl;
            }
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
