#ifndef SDIZO_1_DYNAMICARRAY_TPP
#define SDIZO_1_DYNAMICARRAY_TPP

#include "DynamicArray.hpp"

template<typename T>
DynamicArray<T>::DynamicArray() {
    this->fileManager = new FileManager<T>("DynamicArray");
    this->timer = new Timer;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] table;
    this->size = {0};
}

template<typename T>
T& DynamicArray<T>::operator[](int position) {

    if(position < 0 && position >= this->size)
        throw std::out_of_range("You are out of range!");

    else{
        return *(table+position);
    }

}

template<typename T>
void DynamicArray<T>::addFront(T element) {

        this->timer->startTimer();

        this->size++;

        auto tempTable = new T [this->size];

        tempTable[0] = element;

        for(int i = 1; i < this->size; i++)
            tempTable[i] = table[i - 1];

        delete[] table;
        table = tempTable;
        tempTable = nullptr;

        this->timer->stopTimer();
}

template<typename T>
void DynamicArray<T>::add(T element, int position) {

    if(position == -1){
        addFront(element);
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

    std::cout << "Where you wanna add element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    switch(tempChoice){

        case 1:
          addFront(rand());
            break;

        case 2:
            add(rand(), getRandomIndex());
            break;

        case 3:
          addEnd(rand());
            break;
    }
}

template<typename T>
void DynamicArray<T>::deleteElement() {
    int tempChoice;
    std::cout << "Where you wanna delete element?\n1. Front\n2. Middle\n3. End\n";
    std::cin >> tempChoice;

    switch(tempChoice){

        case 1:
            deleteFront();
            break;

        case 2:
            erase(getRandomValue());
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
        std::cout << table[i] << "\n";
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
                search(getRandomValue());
                break;
            case 4:
                drawTable();
                break;
            default:
                return;
        }
    }
}

#endif



