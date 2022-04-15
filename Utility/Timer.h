#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H

#include <chrono>
#include <iostream>

class Timer {

    std::chrono::high_resolution_clock::time_point operationStart;
    std::chrono::high_resolution_clock::time_point operationEnd;

    bool isTimerStarted = false;
    bool hasTimerFinished = true;

public:

    Timer();

    void setTimer(){
        if(not isTimerStarted and hasTimerFinished) {
            std::cout << "chuj";
            operationStart = std::chrono::high_resolution_clock::now();
            isTimerStarted = true;
            hasTimerFinished = false;
        }
        else if(isTimerStarted and not hasTimerFinished){
            operationEnd = std::chrono::high_resolution_clock::now();
            isTimerStarted = false;
            hasTimerFinished = true;
        }
    }

    double getDuration(){
        return std::chrono::duration<double>(operationEnd - operationStart).count();
    }

};


#endif
