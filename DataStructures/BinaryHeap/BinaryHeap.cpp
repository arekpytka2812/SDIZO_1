#include "BinaryHeap.h"



BinaryHeap::BinaryHeap(){

}

BinaryHeap::BinaryHeap(int size_, int* table_) {
    this->size = size_;
    this->table = table_;

    buildHeap();
}

BinaryHeap::~BinaryHeap(){
    delete[] table;
    table = {nullptr};
    size = {0};
}

void BinaryHeap::heapify(int i) {

    int largest {i}, left {2*i + 1}, right {2*i + 2};

    if(left < size && table[left] > table[largest])
        largest = left;

    if(right < size && table[right] > table[largest])
        largest = right;

    if(largest != i){
        std::swap(table[i], table[largest]);

        heapify(largest);
    }
}

void BinaryHeap::buildHeap() {

    int startIndex {(size / 2) - 1};

    for(int i = startIndex; i >= 0; i--)
        heapify(i);
}

void BinaryHeap::addElement(int value) {

    size++;
    auto tempTable = new int[size];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    tempTable[size - 1] = value;

    delete[] table;
    table = tempTable;
    buildHeap();
}

void BinaryHeap::deleteElement(int value) {

    auto elementPosition = searchElement(value);

    std::swap(table[elementPosition], table[size - 1]);

    size--;

    buildHeap();
}

int BinaryHeap::searchElement(int value) {

    for(int i = 0; i < size; i++){
        if(table[i] == value)
            return i;
    }
}

void BinaryHeap::printHeap(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}