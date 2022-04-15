#ifndef SDIZO_1_DYNAMICARRAY_H
#define SDIZO_1_DYNAMICARRAY_H

#include "../DataStructure.h"

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <fstream>

    class DynamicArray : public DataStructure{

        int* table = {nullptr};
        int size = {0};

        int amountOfSamples;

        int& operator[](int);


        void addFront(int);
        void addMiddle(int, int);
        void addEnd(int);

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
