#ifndef SDIZO_1_DYNAMICARRAY_TPP
#define SDIZO_1_DYNAMICARRAY_TPP

#include "DynamicArray.hpp"

template<typename T>
DynamicArray<T>::DynamicArray() {
    this->fileManager = new FileManager<T>("DynamicArray");
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] table;
    this->size = {0};
}

template<typename T>
T& DynamicArray<T>::operator[](int position) {

    // overloaded operator to check if provided position is in range

    if(position < 0 && position >= this->size)
        throw std::out_of_range("You are out of range!\n");

    else{
        return *(table+position);
    }

}

template<typename T>
void DynamicArray<T>::addFront(T element) {

        this->size++;

        auto tempTable = new T [this->size];

        tempTable[0] = element;

        for(int i = 1; i < this->size; i++)
            tempTable[i] = table[i - 1];

        delete[] table;
        table = tempTable;
        tempTable = nullptr;
}

template<typename T>
void DynamicArray<T>::add(T element, int position) {

    if(position == -1){
        addFront(element);
        return;
    }

    if(this->size == 0){
        table = new int;
        table[0] = element;
        this->size++;
        return;
    }

    if(position > this->size + 1){
        std::cout << "You are out of range, cannot add element!\n";
        return;
    }

        this->size++;

        auto tempTable = new T[this->size];

        for(int i = 0; i < position - 1; i++)
            tempTable[i] = table[i];

        tempTable[position - 1] = element;

        for(int i = position; i < this->size; i++)
            tempTable[i] = table[i - 1];

        delete[] table;
        table = tempTable;
        tempTable = nullptr;



}

template<typename T>
void DynamicArray<T>::addEnd(T element) {

    if(this->size == 0){
        table = new T;
        table[0] = element;
        this->size++;
    }

    this->size++;

    auto tempTable = new T[this->size];

    for(int i = 0; i < this->size; i++)
        tempTable[i] = table[i];

    tempTable[this->size - 1] = element;

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

}

template<typename T>
void DynamicArray<T>::deleteFront() {

    auto tempTable = new T[this->size - 1];

    for(int i = 1; i < this->size; i++)
        tempTable[i - 1] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    this->size--;
}

template<typename T>
int DynamicArray<T>::erase(T value) {

    auto position = search(value);

    if(position == -1){
        return -1;
    }

    auto tempTable = new T[this->size - 1];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    for(int i = position - 1; i < this->size - 1; i++)
        tempTable[i] = table[i+1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    this->size--;

    return 1;
}

template<typename T>
void DynamicArray<T>::deleteEnd() {

    auto tempTable = new T[this->size - 1];

    for(int i = 0; i < this->size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    this->size--;
}

template<typename T>
void DynamicArray<T>::addElement() {

    int tempChoice = {0};
    T element;
    int pos;

    std::cout << "Where you wanna add element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;
    std::cout << "Type value: \n";
    std::cin >> element;

    switch(tempChoice){

        case 1:
          addFront(element);
            break;

        case 2:
            std::cout << "Where: \n";
            std::cin >> pos;

            add(element, pos);

            break;

        case 3:
          addEnd(element);
            break;
    }
}

template<typename T>
void DynamicArray<T>::deleteElement() {

    if(this->size == 0){
        std::cout << "Array is already empty, cannot delete\n";
        return;
    }

    int tempChoice;
    T element;

    std::cout << "Where you wanna delete element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    switch(tempChoice){

        case 1:
            deleteFront();
            break;

        case 2:
            std::cout << "Type value: \n";
            std::cin >> element;

            if(erase(element) == -1)
                std::cout << "Element not found! Couldn't delete.\n";
            else
                std::cout << "Element deleted successfully!\n";

            break;

        case 3:
            deleteEnd();
            break;
    }
}

template<typename T>
int DynamicArray<T>::search(T element) {

    for(int i = 0; i < this->size; i++){
        if(table[i] == element) {
            return i;
        }
    }
    return -1;

}

template<typename T>
void DynamicArray<T>::drawTable(){

    for(int i = 0; i < this->size; i++)
        std::cout <<"[" << i << "] - > " << table[i] << "\n";
}

template<typename T>
T DynamicArray<T>::getRandomValue() {
    return table[getRandomIndex()];
}

template<typename T>
int DynamicArray<T>::getRandomIndex() {
    return rand() %(this->size - 3) + 1;
}

template<typename T>
void DynamicArray<T>::menu() {

    int tempChoice = 0;
    T element;
    int foundIndex;

    while(true){

        std::cout << "1. Add Element\n2. Delete Element\n3. Search Element\n"
            << "4. Draw\n5. Include file\n6. Create structure from included file\n7. Exit\n";
        std::cin >> tempChoice;

        switch (tempChoice) {

            case 1:
                addElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                std::cout << "Type value: \n";
                std::cin >> element;

                foundIndex = search(element);

                if(foundIndex == -1)
                    std::cout << "Element not found!\n";
                else
                    std::cout << "Element found at index: " << foundIndex << std::endl;
                break;
            case 4:
                drawTable();
                break;
            case 5:
                this->fileManager->openManualData();
                break;
            case 6:
                this->createStructure();
                break;
            case 7:
                return;
        }
    }
}

template<typename T>
void DynamicArray<T>::createStructure() {

    T element;

    int dataSize = this->fileManager->readManualData();

    std::cout << dataSize;

    for(int i = 0; i < dataSize; i++){
        std::cout << "cipa\n";
        element = this->fileManager->readManualData();
        this->addEnd(element);
    }

    this->fileManager->setPointer();
}

#endif



