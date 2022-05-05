#include "FileManager.hpp"

template<typename T>
bool FileManager<T>::isDirectoryCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::is_directory(autoDataPath);
        case 1:
            return std::experimental::filesystem::is_directory(logFilePath);
        default:
            return false;

    }
}

template<typename T>
bool FileManager<T>::isFileCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::exists(autoDataPath);
            break;
        case 1:
            return std::experimental::filesystem::exists(logFilePath);
            break;
        default:
            break;
    }
}

template<typename T>
void FileManager<T>::autoPrepareSamples() {

    while(amountCounter < 5) {

        autoDataFile << FileManager::amountOfData[amountCounter] << "\n";

        for (int i = 0; i < FileManager::amountOfData[amountCounter]; i++) {
            autoDataFile << rand() << "\n";
        }

        amountCounter++;
        autoDataFile.flush();
    }
}

template<typename T>
FileManager<T>::FileManager(std::string dataType_){

    this->dataType = dataType_;

    autoDataPath = "../Files/DataToTest";
    logFilePath = "../Files/LogFiles";

    if(not isDirectoryCreated(0))
        std::experimental::filesystem::create_directory(autoDataPath);

    if(not isDirectoryCreated(1))
        std::experimental::filesystem::create_directory(logFilePath);



    autoDataPath = "../Files/DataToTest/" + dataType + "Data.txt";
    logFilePath = "../Files/LogFiles/" + dataType + "Log.txt";

    autoDataFile.open(autoDataPath.c_str(), std::fstream::out | std::fstream::trunc | std::fstream::in);
    logFile.open(logFilePath.c_str(), std::fstream::out | std::fstream::trunc);

    autoPrepareSamples();

    autoDataFile.clear();
    autoDataFile.seekg(0);

    logFile.clear();
    logFile.seekg(0);

    manualDataFile.clear();
    manualDataFile.seekg(0);

}

template<typename T>
FileManager<T>::~FileManager() {

    if(autoDataFile.is_open()) {
        autoDataFile.flush();
        autoDataFile.close();
    }

    if(logFile.is_open()){
        logFile.flush();
        logFile.close();
    }

    if(manualDataFile.is_open()){
        manualDataFile.close();
    }
}

template<typename T>
void FileManager<T>::autoWriteToFile(int operation, double timeValue, int amountData) {

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
    if(autoDataFile.good()) {
        T tempValue;
        autoDataFile >> tempValue;
        return tempValue;
    }
    return -1;
}

template<typename T>
void FileManager<T>::openManualData() {

    std::cout << "Type file name:\n";
    std::cin >> manualDataPath;

    manualDataFile.open(manualDataPath.c_str());

    manualDataFile.seekg(0);
}

template<typename T>
T FileManager<T>::readManualData() {

    if(manualDataFile.is_open()) {
        T element;
        manualDataFile >> element;
        return element;
    }
    return -1;
}

template<typename T>
void FileManager<T>::setPointer() {
    manualDataFile.clear();
    manualDataFile.seekg(0);
}