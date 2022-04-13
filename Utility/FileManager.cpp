#include "FileManager.h"

FileManager::FileManager(std::string dataType_){

    this->dataType = dataType_;

 //   auto tempDataPath = "../DataToTest/" + dataType + "Data.txt";
 //   this->dataPath = new std::experimental::filesystem::path(tempDataPath);


    //auto tempLogFilePath = "../Logfiles/" + dataType +"Log.txt";
    //this->logFilePath = tempLogFilePath;

 //   std::cout << dataPath << std::endl;
   // std::cout << logFilePath << std::endl;

    if(true){
        std::string tempFileName = "LogFiles/" + dataType + "Log.txt";
        std::cout << tempFileName;
        file.open(tempFileName, std::ios::in | std::ios::out);
    }
}

bool FileManager::isFileExisted() {

    std::string tempFileName {"LogFiles/" + dataType};

    return false;
}