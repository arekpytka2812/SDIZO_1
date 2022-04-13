#ifndef SDIZO_1_FILEMANAGER_H
#define SDIZO_1_FILEMANAGER_H


#include <fstream>
#include <iostream>
#include <experimental/filesystem>

class FileManager {

    std::string dataType;
    std::fstream dataFile;
    std::fstream logFile;

    std::string dataPath;
    std::string logFilePath;

    int amountOfData[5] = {1000, 2000, 5000, 10000, 20000};
    int amountCounter {0};

    bool isDirectoryCreated(int);
    bool isFileCreated(int);

    void prepareSamples();

public:
    FileManager(std::string);
    ~FileManager();

    void writeToFile(int, long long);
    int readData();

};


#endif
