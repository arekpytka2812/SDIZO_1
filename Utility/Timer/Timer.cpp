#include "Timer.h"

void Timer::stopTimer() {
    this->operationEnd = std::chrono::high_resolution_clock::now();
}

void Timer::startTimer() {
    this->operationStart = std::chrono::high_resolution_clock::now();
}