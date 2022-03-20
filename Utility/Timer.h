#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H

#include <chrono>


class Timer {

    std::chrono::high_resolution_clock::time_point operationStart;
    std::chrono::high_resolution_clock::time_point operationEnd;

    bool isTimerStarted = false;
    bool hasTimerFinished = false;

    long getDuration(){
        return std::chrono::duration_cast<std::chrono::microseconds>(operationEnd - operationStart).count();
    }

public:

    Timer();

    void setTimer(){
        if(!isTimerStarted && hasTimerFinished) {
            operationStart = std::chrono::high_resolution_clock::now();
            isTimerStarted = true;
        }
        else{
            operationEnd = std::chrono::high_resolution_clock::now();

        }
    }

};


#endif
