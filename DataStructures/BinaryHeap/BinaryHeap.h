#ifndef SDIZO_1_BINARYHEAP_H
#define SDIZO_1_BINARYHEAP_H

#include "../DataStructure.h"

#include <iostream>

class BinaryHeap: public DataStructure {

    int* table { nullptr };
    int size {0};

    int& operator[](int);

    void heapify(int);
    void buildHeap();

public:
    BinaryHeap();
    ~BinaryHeap();


    void addElement(int);
    void deleteElement(int);
    int searchElement(int);

    void printHeap();


};


#endif
