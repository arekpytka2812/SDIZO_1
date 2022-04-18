#ifndef SDIZO_1_FILEMANAGER_HPP
#define SDIZO_1_FILEMANAGER_HPP


#include <fstream>
#include <iostream>
#include <experimental/filesystem>

template<typename T>
class FileManager {

    std::string dataType;
    std::fstream dataFile;
    std::fstream logFile;

    std::string dataPath;
    std::string logFilePath;

    bool isDirectoryCreated(int);
    bool isFileCreated(int);

    void prepareSamples();

public:

    const int amountOfData[5] = {1000, 2000, 5000, 10000, 20000};
    int amountCounter {0};

    FileManager(std::string);
    ~FileManager();

    void writeToFile(int, double, int);
    T readData();

    void setPointer();
};


#endif
