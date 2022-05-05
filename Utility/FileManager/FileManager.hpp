#ifndef SDIZO_1_FILEMANAGER_HPP
#define SDIZO_1_FILEMANAGER_HPP


#include <fstream>
#include <iostream>
#include <experimental/filesystem>

template<typename T>
class FileManager {

    std::string dataType;

    std::fstream autoDataFile;
    std::fstream logFile;
    std::ifstream manualDataFile;

    std::string autoDataPath;
    std::string logFilePath;
    std::string manualDataPath;

    bool isDirectoryCreated(int);
    bool isFileCreated(int);

    void autoPrepareSamples();

public:

    const int amountOfData[5] = {1000, 2000, 5000, 10000, 20000};
    int amountCounter {0};

    explicit FileManager(std::string);
    ~FileManager();

    void autoWriteToFile(int, double, int);
    T readData();

    void openManualData();
    T readManualData();

    void setPointer();
};


#endif
