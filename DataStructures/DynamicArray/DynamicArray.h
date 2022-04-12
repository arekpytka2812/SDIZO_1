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

        int amountOfSamples = 3;

        int& operator[](int);

        long long addFront(int*);
        long long addMiddle(int, int);
        long long addEnd(int*);

        long long deleteFront();
        long long deleteMiddle(int);
        long long deleteEnd();

        int* prepareSamples();

        void addElement();
        void deleteElement();
        void searchElement();

        void drawTable();

    public:

        DynamicArray();
        explicit DynamicArray(int);
        ~DynamicArray();

        void menu();
    };





#endif
