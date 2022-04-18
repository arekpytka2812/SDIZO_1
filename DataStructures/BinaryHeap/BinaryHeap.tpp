#include "BinaryHeap.hpp"

template<typename T>
T& BinaryHeap<T>::operator[](int position){
    if(position < 0 or position >= this->size)
        throw std::out_of_range("You are out of range!");
    else
        return *(table + position);
}

template<typename T>
BinaryHeap<T>::BinaryHeap() {
    this->fileManager = new FileManager<T>("BinaryHeap");
    this->timer = new Timer;
}
template<typename T>
BinaryHeap<T>::~BinaryHeap(){
    delete[] table;
    table = {nullptr};
    this->size = {0};
}

template<typename T>
void BinaryHeap<T>::heapify(int i) {

    int largest {i}, left {2*i + 1}, right {2*i + 2};

    if(left < this->size && table[left] > table[largest])
        largest = left;

    if(right < this->size && table[right] > table[largest])
        largest = right;

    if(largest != i){
        std::swap(table[i], table[largest]);

        heapify(largest);
    }
}

template<typename T>
void BinaryHeap<T>::buildHeap() {

    int startIndex {(this->size / 2) - 1};

    for(int i = startIndex; i >= 0; i--)
        heapify(i);
}

template<typename T>
void BinaryHeap<T>::addFront(T element) {
    addEnd(element);
}

template<typename T>
void BinaryHeap<T>::add(T element, int position){

    if(position == -1){
        addEnd(element);
        return;
    }

    this->size++;
    auto tempTable = new T[this->size];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    tempTable[position - 1] = element;

    for(int i = position; i < this->size; i++)
        tempTable[i] = table[i - 1];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;

    buildHeap();

}

template<typename T>
void BinaryHeap<T>::deleteFront() {
    erase(table[0]);
}

template<typename T>
void BinaryHeap<T>::deleteEnd() {
    erase(table[this->size - 1]);
}


template<typename T>
void BinaryHeap<T>::addEnd(T value) {

    this->size++;
    auto tempTable = new T[this->size];

    for(int i = 0; i < this->size - 1; i++)
        tempTable[i] = table[i];

    tempTable[this->size - 1] = value;

    delete[] table;
    table = tempTable;
    buildHeap();
}

template<typename T>
int BinaryHeap<T>::erase(T value) {

    auto elementPosition = search(value);

    if(elementPosition == -1){
        return -1;
    }

    std::swap(table[elementPosition], table[this->size - 1]);

    auto tempTable = new T[this->size - 1];

    for(int i = 0; i < this->size - 1; i++)
        tempTable[i] = table[i];

    delete[] table;
    table = tempTable;
    tempTable = nullptr;
    this->size--;

    buildHeap();

    return 1;
}

template<typename T>
int BinaryHeap<T>::search(T value) {

    if(table[0] < value)
        return -1;

    for(int i = 0; i < this->size; i++){
        if(table[i] == value){
            return i;
        }
    }
    return -1;
}

template<typename T>
void BinaryHeap<T>::printHeap(){

    for(int i = 0; i < this->size; i++)
        std::cout << table[i] << "\n";
}
