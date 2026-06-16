#include "executor.h"

#include <thread>


void Executor::calculateMultithread() {
    findMaxThread = std::jthread(&Executor::findMax, this);
    findSumThread = std::jthread(&Executor::findSum, this);

    findMaxThread.join();
    findSumThread.join();
};
