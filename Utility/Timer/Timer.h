#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H

#include <chrono>
#include <iostream>

class Timer {

    std::chrono::high_resolution_clock::time_point operationStart;
    std::chrono::high_resolution_clock::time_point operationEnd;

public:

    Timer() = default;

    void stopTimer();
    void startTimer();

    double getDuration(){
        return std::chrono::duration<double, std::nano>(this->operationEnd - this->operationStart).count();
    }

};


#endif
