#include "executor.h"

#include <thread>


void Executor::calculateMultithread() {
    std::jthread t1(&Executor::findMax, this);
    std::jthread t2(&Executor::findSum, this);
};
