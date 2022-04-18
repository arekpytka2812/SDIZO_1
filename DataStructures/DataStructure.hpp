#ifndef SDIZO_1_DATASTRUCTURE_HPP
#define SDIZO_1_DATASTRUCTURE_HPP

#include "../Utility/Timer/Timer.h"
#include "../Utility/FileManager/FileManager.hpp"

template<typename T>
class DataStructure {

protected:

    int size = 0;

    Timer* timer {nullptr};
    FileManager<T>* fileManager {nullptr};

public:

    FileManager<T>* getManager(){
        return fileManager;
    }

    int getSize(){
        return size;
    }

    virtual void addFront(T) = 0;
    virtual void add(T, int) = 0;
    virtual void addEnd(T) = 0;

    virtual void deleteFront() = 0;
    virtual void deleteEnd() = 0;
    virtual int erase(T) = 0;

    virtual int search(T) = 0;

};


#endif
