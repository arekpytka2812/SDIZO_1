#ifndef SDIZO_1_BINARYHEAP_HPP
#define SDIZO_1_BINARYHEAP_HPP

#include "../DataStructure.hpp"

#include <iostream>

template<typename T>
class BinaryHeap: public DataStructure<T> {

    T* table { nullptr };
    int size {0};

    T& operator[](int);

    void heapify(int);
    void buildHeap();

public:
    BinaryHeap();
    ~BinaryHeap();


    void addElement(T);
    void deleteElement(T);
    int searchElement(T);

    void printHeap();


};

#endif
