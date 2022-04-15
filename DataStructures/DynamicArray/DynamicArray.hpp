#ifndef SDIZO_1_DYNAMICARRAY_HPP
#define SDIZO_1_DYNAMICARRAY_HPP

#include "../DataStructure.hpp"

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <fstream>

template<typename T>
class DynamicArray : public DataStructure<T>{

    T* table = {nullptr};
    int size = {0};

    int amountOfSamples;

    T& operator[](int);

    void addFront(T);
    void addMiddle(T, int);
    void addEnd(T);

    void deleteFront();
    void deleteMiddle(int);
    void deleteEnd();

    void addElement();
    void deleteElement();
    void searchElement();

    void drawTable();

public:
    DynamicArray();
    ~DynamicArray();

    void menu();
};





#endif