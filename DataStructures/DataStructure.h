#ifndef SDIZO_1_DATASTRUCTURE_H
#define SDIZO_1_DATASTRUCTURE_H

#include "../Utility/Timer.h"
#include "../Utility/FileManager.h"


class DataStructure {

protected:

    Timer timer;
    FileManager* fileManager = nullptr;

    DataStructure();

};


#endif
