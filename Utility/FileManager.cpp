

#include "FileManager.h"

FileManager::FileManager(std::string dataType_){

    this->dataType = dataType_;

    if(true){
        std::string tempFileName = "LogFiles/" + dataType + "Log.txt";
        std::cout << tempFileName;
        file.open(tempFileName, std::ios::in | std::ios::out);
    }
}

bool FileManager::isFileExisted() {

    std::string tempFileName {"LogFiles/" + dataType};

    return std::filesystem::exists(tempFileName);
}