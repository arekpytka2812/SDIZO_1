#include "BinaryHeap.hpp"

template<typename T>
T& BinaryHeap<T>::operator[](int position){
    if(position < 0 or position >= size)
        throw std::out_of_range("You are out of range!");
    else
        return *(table + position);
}

template<typename T>
BinaryHeap<T>::BinaryHeap() {
    this->fileManager = new FileManager("BinaryHeap");
    this->timer = new Timer;
}
template<typename T>
BinaryHeap<T>::~BinaryHeap(){
    delete[] table;
    table = {nullptr};
    size = {0};
}

template<typename T>
void BinaryHeap<T>::heapify(int i) {

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

template<typename T>
void BinaryHeap<T>::buildHeap() {

    int startIndex {(size / 2) - 1};

    for(int i = startIndex; i >= 0; i--)
        heapify(i);
}

template<typename T>
void BinaryHeap<T>::addElement(T value) {

    this->timer->startTimer();

    auto start = std::chrono::high_resolution_clock::now();

    size++;
    auto tempTable = new T[size];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    tempTable[size - 1] = value;

    delete[] table;
    table = tempTable;
    buildHeap();

    this->timer->stopTimer();
    std::cout << "\n" << this->timer->getDuration();
}

template<typename T>
void BinaryHeap<T>::deleteElement(T value) {

    auto elementPosition = searchElement(value);

    std::swap(table[elementPosition], table[size - 1]);

    auto tempTable = new T[size - 1];

    for(int i = 0; i < size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    size--;

    buildHeap();
}

template<typename T>
int BinaryHeap<T>::searchElement(T value) {

    for(int i = 0; i < size; i++){
        if(table[i] == value){
            return i;
        }
    }
    return -1;
}

template<typename T>
void BinaryHeap<T>::printHeap(){

    for(int i = 0; i < size; i++)
        std::cout << table[i] << "\n";
}
