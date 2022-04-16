#ifndef SDIZO_1_DATASTRUCTURE_HPP
#define SDIZO_1_DATASTRUCTURE_HPP

#include "../Utility/Timer/Timer.h"
#include "../Utility/FileManager/FileManager.h"

template<typename T>
class DataStructure {

protected:

    Timer* timer {nullptr};
    FileManager* fileManager {nullptr};

    std::vector<double> measurements;

public:

    FileManager* getManager(){
        return fileManager;
    }

    virtual void addFront(T) = 0;
    virtual void add(T, int) = 0;
    virtual void addEnd(T) = 0;

    virtual void deleteFront() = 0;
    virtual void deleteEnd() = 0;
    virtual void erase(T) = 0;


};


#endif
