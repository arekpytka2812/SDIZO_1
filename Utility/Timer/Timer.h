#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H

#include <chrono>
#include <iostream>
#include <windows.h>

class Timer {

    std::chrono::high_resolution_clock::time_point operationStart;
    std::chrono::high_resolution_clock::time_point operationEnd;

    double PCFreq = 0.0;
    __int64 CounterStart = 0;

public:

    Timer() = default;

    void startTimer();

    double getDuration(){
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return double(li.QuadPart-CounterStart)/PCFreq;
    }

};


#endif
