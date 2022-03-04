#include "DynamicTable.h"

DT::DynamicTable::DynamicTable() {

}

DT::DynamicTable::DynamicTable(int size_):size(size_) {
    table = {new int[size]};
    table[0] = 23;
    table[1] = 45;
}

DT::DynamicTable::~DynamicTable() {
    delete(table);
    size = {0};
}

long long DT::DynamicTable::addFront(int* elements) {

        const auto start = std::chrono::steady_clock::now();

        int newSize = {size + amountOfSamples};

        int* tempTable = new int [newSize];

        for(int i = {newSize - 1}; i - amountOfSamples >= 0; i--)
            tempTable[i] = {table[i - amountOfSamples]};

        for(int i = amountOfSamples - 1, j = 0; i >= 0; i--, j++)
            tempTable[i] = {elements[j]};


        delete[] table;
        table = new int[newSize];
        table = tempTable;
        delete[] tempTable;

        size = {newSize};

        const auto end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::addMiddle(int element, int position) {
    return 0;
}

long long DT::DynamicTable::addEnd(int* elements) {

    const auto start = std::chrono::steady_clock::now();

    int newSize = size + amountOfSamples;

    int* tempTable = new int[newSize];

    for(int i = 0; i < size; i++)
        tempTable[i] = table[i];

    for(int i = size, j = 0; i < newSize; i++, j++)
        tempTable[i] = elements[j];

    delete[] table;
    table = new int[newSize];
    table = tempTable;
    delete[] tempTable;

    size = newSize;

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::deleteFront(int) {
    return 0;
}

long long DT::DynamicTable::deleteMiddle( int position) {
    return 0;
}

long long DT::DynamicTable::deleteEnd(int) {
    return 0;
}

int* DT::DynamicTable::prepareSamples() {

    int * tempTable = new int[amountOfSamples];

    for(int i = 0; i < amountOfSamples; i++) {
        tempTable[i] = rand() % 1024;
        std::cout << std::endl << tempTable[i] << std::endl;
    }

    return tempTable;
}

void DT::DynamicTable::addElement() {

    int* tempSamplesTable = {prepareSamples()};
    int tempChoice = {0};
    long long duration = {0};

    std::cout << "Where you wanna add element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    long long tempTime = {0};

    switch(tempChoice){

        case 1:
            duration += addFront(tempSamplesTable);
            break;

        case 2:
            for(int i = 0; i < amountOfSamples; i++)
                duration += addMiddle(tempSamplesTable[i], 3);
            break;

        case 3:
            duration += addEnd(tempSamplesTable);
            break;
    }

    amountOfSamples *= 2;

    std::cout << "duration " << duration << std::endl;

}

void DT::DynamicTable::deleteElement() {

}

void DT::DynamicTable::searchElement() {

    int element;

    std::cout << "Which element: \n";
    std::cin >> element;

    for(int i = 0; i < size; i++){

        if(table[i] == element) {

            std::cout << "index: " << i;
            return;
        }
    }

}

void DT::DynamicTable::drawTable(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}

void DT::DynamicTable::menu() {

    int tempChoice;

    std::cout << "1. Add Element\n2. Delete Element\n3. Search Element\n4. Exit";
    std::cin >> tempChoice;

    switch (tempChoice) {

        case 1:
            addElement();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            searchElement();
            break;
        default:
            return;
    }

}





