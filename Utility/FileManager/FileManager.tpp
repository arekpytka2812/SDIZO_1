#include "FileManager.hpp"

template<typename T>
bool FileManager<T>::isDirectoryCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::is_directory(dataPath);
            break;
        case 1:
            return std::experimental::filesystem::is_directory(logFilePath);
            break;
    }
}

template<typename T>
bool FileManager<T>::isFileCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::exists(dataPath);
            break;
        case 1:
            return std::experimental::filesystem::exists(logFilePath);
            break;
    }
}

template<typename T>
void FileManager<T>::prepareSamples() {

    while(amountCounter < 5) {
        dataFile << FileManager::amountOfData[amountCounter] << "\n";

        for (int i = 0; i < FileManager::amountOfData[amountCounter]; i++) {
            dataFile << rand() % 32255 << "\n";
        }

        amountCounter++;
        dataFile.flush();
    }
}

template<typename T>
FileManager<T>::FileManager(std::string dataType_){

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
}

template<typename T>
FileManager<T>::~FileManager() {

    if(dataFile.is_open()) {
        dataFile.flush();
        dataFile.close();
    }

    if(logFile.is_open()){
        logFile.flush();
        logFile.close();
    }
}

template<typename T>
void FileManager<T>::writeToFile(int operation, double timeValue, int amountData) {

    switch(operation){
        case 0: //add front
            logFile << dataType <<  ", average time of add at front: " <<
                timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 1: //add
            logFile << dataType <<  ", average time of add: " <<
                    timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 2: //add end
            logFile << dataType <<  ", average time of add at the end: " <<
                    timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 3: //delete front
            logFile << dataType <<  ", average time of delete at front: " <<
                timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 4: //erase
            logFile << dataType <<  ", average time of erase: " <<
                    timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 5: //delete end
            logFile << dataType <<  ", average time of delete: " <<
                    timeValue << " ms, amount of data: " << amountData << std::endl;
            break;

        case 6: // search
            logFile << dataType <<  ", average time of search: " <<
                timeValue << " ms, amount of data: " << amountData << std::endl;
            break;
    }
    logFile.flush();
}

template<typename T>
T FileManager<T>::readData(){
    if(dataFile.good()) {
        T tempValue;
        dataFile >> tempValue;
        return tempValue;
    }
    return -1;
}

template<typename T>
void FileManager<T>::setPointer() {
    dataFile.clear();
    dataFile.seekg(0);
}