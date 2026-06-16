#pragma once

#include <thread>
#include <vector>
#include <iostream>


class Executor {
    private:
        const std::vector<int>& list;
        long long sum;
        int max;

        void findMax() {
            if (list.empty()) {
                max = 0;
                return;
            }

            max = list[0];

            for (int i = 0; i < list.size(); i++) {
                std::cout << "Process: findMax, index: " << i;
                std::cout << "\nMax: " << max << std::endl;
                if (list[i] > max) {
                    max = list[i];
                }
            }
        };
        void findSum() {
            sum = 0;

            for (int i = 0; i < list.size(); i++) {
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
