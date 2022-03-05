#include "DynamicTable.h"

DT::DynamicTable::DynamicTable() {

}

DT::DynamicTable::DynamicTable(int size_):size(size_) {
    table = {new int[size]};

    for(int i = 0; i < size; i++)
        table[i] = i+1;
}

DT::DynamicTable::~DynamicTable() {
    delete(table);
    size = {0};
}

long long DT::DynamicTable::addFront(int* elements) {

        const auto start = std::chrono::steady_clock::now();

        int newSize = {size + amountOfSamples};

        auto tempTable = new int [newSize];

        for(int i = {newSize - 1}; i - amountOfSamples >= 0; i--)
            tempTable[i] = {table[i - amountOfSamples]};

        for(int i = amountOfSamples - 1, j = 0; i >= 0; i--, j++)
            tempTable[i] = {elements[j]};

        delete[] table;
        table = tempTable;
        tempTable = nullptr;

        size = {newSize};

        const auto end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::addMiddle(int element, int position) {

    const auto start = std::chrono::steady_clock::now();

    auto tempTable = new int[size + 1];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    tempTable[position - 1] = element;

    for(int i = position; i < size + 1; i++)
        tempTable[i] = table[i - 1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    size++;

    for(int i = 0; i < size; i++)
        std::cout << table[i] << " ";

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

}

long long DT::DynamicTable::addEnd(int* elements) {

    const auto start = std::chrono::steady_clock::now();

    int newSize = size + amountOfSamples;

    auto tempTable = new int[newSize];

    for(int i = 0; i < size; i++)
        tempTable[i] = table[i];

    for(int i = size, j = 0; i < newSize; i++, j++)
        tempTable[i] = elements[j];

    delete[] table;

    table = tempTable;
    tempTable = nullptr;

    size = newSize;

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::deleteFront() {

    const auto start = std::chrono::steady_clock::now();

    auto tempTable = new int[size - 1];

    for(int i = 1; i < size; i++)
        tempTable[i - 1] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    size--;

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::deleteMiddle(int position) {

    const auto start = std::chrono::steady_clock::now();

    auto tempTable = new int[size - 1];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    for(int i = position - 1; i < size - 1; i++)
        tempTable[i] = table[i+1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    size--;

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long DT::DynamicTable::deleteEnd() {

    const auto start = std::chrono::steady_clock::now();

    auto tempTable = new int[size - 1];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    size--;

    const auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int* DT::DynamicTable::prepareSamples() {

    auto tempTable = new int[amountOfSamples];

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
            duration = addFront(tempSamplesTable);
            break;

        case 2:
            duration = addMiddle(6, 3);
            break;

        case 3:
            duration = addEnd(tempSamplesTable);
            break;
    }

    amountOfSamples *= 2;

    std::cout << "duration " << duration << std::endl;

}

void DT::DynamicTable::deleteElement() {

    int tempSample = {rand() % 1024};
    int tempChoice = {0};
    long long duration = {0};

    std::cout << "Where you wanna delete element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    long long tempTime = {0};

    switch(tempChoice){

        case 1:
            duration = deleteFront();
            break;

        case 2:
            duration = deleteMiddle(3);
            break;

        case 3:
            duration = deleteEnd();
            break;
    }

    std::cout << "duration " << duration << std::endl;

}

void DT::DynamicTable::searchElement() {

    int element;

    std::cout << "Which element: \n";
    std::cin >> element;

    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < size; i++){

        if(table[i] == element) {

            std::cout << "index: " << i;

            auto end = std::chrono::steady_clock::now();

            return;
        }
    }

}

void DT::DynamicTable::drawTable(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}

void DT::DynamicTable::menu() {

    int tempChoice = 0;

    while(true){

        std::cout << "1. Add Element\n2. Delete Element\n3. Search Element\n4. Draw\n5. Exit\n";
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
            case 4:
                drawTable();
                break;
            default:
                return;
        }
    }



}





