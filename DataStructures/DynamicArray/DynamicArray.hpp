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

    int amountOfSamples;

    T& operator[](int);

    void addFront(T) override;
    void add(T, int) override;
    void addEnd(T) override;

    void deleteFront() override;
    void deleteEnd() override;
    int erase(T) override;

    int search(T) override;

    void addElement();
    void deleteElement();

    void drawTable();

public:
    DynamicArray();
    ~DynamicArray();

    void menu();
};





#endif
