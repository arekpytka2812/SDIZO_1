#include "FileManager.hpp"

template<typename T>
bool FileManager<T>::isDirectoryCreated(int whichOne) {

    switch(whichOne){
        case 0:
            return std::experimental::filesystem::is_directory(autoDataPath);
        case 1:
            return std::experimental::filesystem::is_directory(logFilePath);
        case 2:
            return std::experimental::filesystem::is_directory(manualDataPath);
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
        case 2:
            return std::experimental::filesystem::exists(manualDataPath);
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
    manualDataPath = "../Files/ManualData";

    if(not isDirectoryCreated(0))
        std::experimental::filesystem::create_directory(autoDataPath);

    if(not isDirectoryCreated(1))
        std::experimental::filesystem::create_directory(logFilePath);

    if(not isDirectoryCreated(2))
        std::experimental::filesystem::create_directory(manualDataPath);


    autoDataPath = "../Files/DataToTest/" + dataType + "Data.txt";
    logFilePath = "../Files/LogFiles/" + dataType + "Log.txt";
    manualDataPath = "../Files/ManualData/" + dataType + "ManualData.txt";

    autoDataFile.open(autoDataPath.c_str(), std::fstream::out | std::fstream::trunc | std::fstream::in);
    logFile.open(logFilePath.c_str(), std::fstream::out | std::fstream::trunc);
    manualDataFile.open(manualDataPath.c_str(), std::fstream::out | std::fstream::trunc | std::fstream::in );

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
        manualDataFile.flush();
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
void FileManager<T>::manualWriteToFile() {

    std::string valuesToFile;
    int dataSize = 0;

    std::string delimeter = " ";
    int values = 0;

    std::cout << "Write amount of data: \n";
    std::cin >> dataSize;

    manualDataFile << dataSize << std::endl;
    manualDataFile.flush();

    std::cout << "Write values: \n";

    for(int i = 0; i < dataSize; i++){

        std::cin >> values;
        manualDataFile << values << std::endl;

    }

    manualDataFile.flush();
    manualDataFile.clear();
    manualDataFile.seekg(0);

}

template<typename T>
T FileManager<T>::readManualData() {

    if(manualDataFile.good()){
        T element;
        manualDataFile >> element;
        return element;
    }
    return -1;
}

template<typename T>
void FileManager<T>::setPointer() {
    autoDataFile.clear();
    autoDataFile.seekg(0);
}