#ifndef SDIZO_1_FILEMANAGER_H
#define SDIZO_1_FILEMANAGER_H

#include <filesystem>
#include <fstream>
#include <iostream>

class FileManager {

    std::string dataType;
    std::fstream file;

    int amountOfData;

    bool isFileExisted();

public:
    FileManager(std::string);

};


#endif
