#include "BinaryHeap.h"

int& BinaryHeap::operator[](int position){
    if(position < 0 or position >= size)
        throw std::out_of_range("You are out of range!");
    else
        return *(table + position);
}

BinaryHeap::BinaryHeap(){
    fileManager = new FileManager("BinaryHeap");
    timer = new Timer;
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

    timer->setTimer();

    size++;
    auto tempTable = new int[size];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    tempTable[size - 1] = value;

    delete[] table;
    table = tempTable;
    buildHeap();

    timer->setTimer();
    std::cout << "\n" << timer->getDuration();
}

void BinaryHeap::deleteElement(int value) {

    auto elementPosition = searchElement(value);

    std::swap(table[elementPosition], table[size - 1]);

    auto tempTable = new int[size - 1];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    size--;

    buildHeap();
}

int BinaryHeap::searchElement(int value) {

    for(int i = 0; i < size; i++){
        if(table[i] == value){
            return i;
        }
    }
    return -1;
}

void BinaryHeap::printHeap(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}