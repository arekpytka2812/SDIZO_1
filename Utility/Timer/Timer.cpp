#include "Timer.h"

void Timer::stopTimer() {
    this->operationEnd = std::chrono::high_resolution_clock::now();
}

void Timer::startTimer() {
    this->operationStart = std::chrono::high_resolution_clock::now();

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}