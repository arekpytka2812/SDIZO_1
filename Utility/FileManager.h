#ifndef SDIZO_1_FILEMANAGER_H
#define SDIZO_1_FILEMANAGER_H


#include <fstream>
#include <iostream>
#include <experimental/filesystem>

class FileManager {

    std::string dataType;
    std::fstream file;

    std::experimental::filesystem::path* dataPath {nullptr};
    std::experimental::filesystem::path* logFilePath {nullptr};

    int amountOfData;

    bool isFileExisted();

public:
    FileManager(std::string);



};


#endif
