#include "FileManager.h"

bool FileManager::isDirectoryCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::is_directory(dataPath);
            break;
        case 1:
            return std::experimental::filesystem::is_directory(logFilePath);
            break;
    }
}

bool FileManager::isFileCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::exists(dataPath);
            break;
        case 1:
            return std::experimental::filesystem::exists(logFilePath);
            break;
    }
}

void FileManager::prepareSamples() {

    while(amountCounter < 5) {
        dataFile << FileManager::amountOfData[amountCounter] << "\n";

        for (int i = 0; i < FileManager::amountOfData[amountCounter]; i++) {
            dataFile << rand() % 32255 << "\n";
        }

        amountCounter++;
        dataFile.flush();
    }
}

FileManager::FileManager(std::string dataType_){

    this->dataType = dataType_;

    dataPath = "../DataToTest";
    logFilePath = "../LogFiles";

    if(not isDirectoryCreated(0))
        std::experimental::filesystem::create_directory(dataPath);

    if(not isDirectoryCreated(1))
        std::experimental::filesystem::create_directory(logFilePath);

    dataPath = "../DataToTest/" + dataType + "Data.txt";
    logFilePath = "../LogFiles/" + dataType + "Log.txt";

    dataFile.open(dataPath.c_str(), std::fstream::out | std::fstream::trunc | std::fstream::in);
    logFile.open(logFilePath.c_str(), std::fstream::out | std::fstream::trunc);

    prepareSamples();

    dataFile.clear();
    dataFile.seekg(0);

    logFile.clear();
    logFile.seekg(0);

    readData();
}

FileManager::~FileManager() {

    if(dataFile.is_open()) {
        dataFile.flush();
        dataFile.close();
    }

    if(logFile.is_open()){
        logFile.flush();
        logFile.close();
    }
}

void FileManager::writeToFile(int operation, long long timeValue) {

    switch(operation){
        case 0: //add
            logFile << dataType <<  ", average time of add: " << timeValue << " ms.";
            break;

        case 1: //delete
            logFile << dataType <<  ", average time of delete: " << timeValue << " ms.";
            break;

        case 2: // search
            logFile << dataType <<  ", average time of search: " << timeValue << " ms.";
            break;
    }
    logFile.flush();
}

int FileManager::readData(){
    if(dataFile.good()) {
        int tempInt;
        dataFile >> tempInt;
        return tempInt;
    }
    return -1;
}