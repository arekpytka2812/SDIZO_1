#ifndef SDIZO_1_DATASTRUCTURE_HPP
#define SDIZO_1_DATASTRUCTURE_HPP

#include "../Utility/Timer.h"
#include "../Utility/FileManager.h"

template<typename T>
class DataStructure {

protected:

    Timer* timer {nullptr};
    FileManager* fileManager {nullptr};

    std::vector<double> measurements;

};


#endif
