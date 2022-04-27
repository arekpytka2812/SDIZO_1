#ifndef SDIZO_1_BINARYHEAP_HPP
#define SDIZO_1_BINARYHEAP_HPP

#include "../DataStructure.hpp"

#include <iostream>

template<typename T>
class BinaryHeap: public DataStructure<T> {

    T* table { nullptr };

    T& operator[](int);

    void heapify(int);
    void buildHeap();

    T getRandomValue();

public:
    BinaryHeap();
    ~BinaryHeap();

    void addFront(T) override;
    void add(T, int) override;
    void addEnd(T) override;

    void deleteFront() override;
    void deleteEnd() override;
    int erase(T) override;

    int search(T) override;

    void printHeap();

    void menu() override;

    void createStructure() override;


};

#endif
