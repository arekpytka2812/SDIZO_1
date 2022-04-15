#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    fileManager = new FileManager("DynamicArray");
    timer = new Timer;
}

DynamicArray::~DynamicArray() {
    delete(table);
    size = {0};
}

int& DynamicArray::operator[](int position) {

    if(position < 0 && position >= size)
        throw std::out_of_range("You are out of range!");

    else{
        return *(table+position);
    }

}

void DynamicArray::addFront(int value) {

        timer->setTimer();

        size++;

        auto tempTable = new int [size];

        tempTable[0] = value;

        for(int i = 1; i < size; i++)
            tempTable[i] = table[i - 1];

        delete[] table;
        table = tempTable;
        tempTable = nullptr;

        timer->setTimer();
}

void DynamicArray::addMiddle(int value, int position) {

    size++;

    auto tempTable = new int[size];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    tempTable[position - 1] = value;

    for(int i = position; i < size; i++)
        tempTable[i] = table[i - 1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

}

void DynamicArray::addEnd(int value) {

    size++;

    auto tempTable = new int[size];

    for(int i = 0; i < size; i++)
        tempTable[i] = table[i];

    tempTable[size - 1] = value;

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

}

void DynamicArray::deleteFront() {

    auto tempTable = new int[size - 1];

    for(int i = 1; i < size; i++)
        tempTable[i - 1] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    size--;
}

void DynamicArray::deleteMiddle(int position) {

    auto tempTable = new int[size - 1];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    for(int i = position - 1; i < size - 1; i++)
        tempTable[i] = table[i+1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    size--;
}

void DynamicArray::deleteEnd() {

    auto tempTable = new int[size - 1];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    size--;

}

void DynamicArray::addElement() {

    int tempChoice = {0};
    long long duration = {0};

    std::cout << "Where you wanna add element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    long long tempTime = {0};

    switch(tempChoice){

        case 1:
          //  duration = addFront();
            break;

        case 2:
         //   duration = addMiddle(6, 3);
            break;

        case 3:
          //  duration = addEnd();
            break;
    }

    amountOfSamples *= 2;

    std::cout << "duration " << duration << std::endl;

}

void DynamicArray::deleteElement() {

    int tempSample = {rand() % 1024};
    int tempChoice = {0};
    long long duration = {0};

    std::cout << "Where you wanna delete element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    long long tempTime = {0};

    switch(tempChoice){

        case 1:
          //  duration = deleteFront();
            break;

        case 2:
          //  duration = deleteMiddle(3);
            break;

        case 3:
          //  duration = deleteEnd();
            break;
    }

    std::cout << "duration " << duration << std::endl;

}

void DynamicArray::searchElement() {

    int element;

    std::cout << "Which element: \n";
    std::cin >> element;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < size; i++){

        if(table[i] == element) {

            std::cout << "index: " << i;

            auto end = std::chrono::high_resolution_clock::now();

            return;
        }
    }

}

void DynamicArray::drawTable(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}

void DynamicArray::menu() {

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





