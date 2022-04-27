#include "BinaryHeap.hpp"

template<typename T>
T& BinaryHeap<T>::operator[](int position){

    // overloaded operator[] to check if provided position is in range

    if(position < 0 or position >= this->size)
        throw std::out_of_range("You are out of range!");
    else
        return *(table + position);
}

template<typename T>
BinaryHeap<T>::BinaryHeap() {
    this->fileManager = new FileManager<T>("BinaryHeap");
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

    // function to build Heap

    int startIndex {(this->size / 2) - 1};

    for(int i = startIndex; i >= 0; i--)
        heapify(i);
}

template<typename T>
void BinaryHeap<T>::addFront(T element) {
    add(element, 1);
}

template<typename T>
void BinaryHeap<T>::add(T element, int position){

    if(this->size == 0){
        this->size++;
        this->table = new T;
        table[0] = element;
        return;
    }

    if(position == -1){
        addEnd(element);
        return;
    }

    // allocating new amount of memory for new table

    this->size++;
    auto tempTable = new T[this->size];

    for(int i = 0; i < position - 1; i++)
        tempTable[i] = table[i];

    tempTable[position - 1] = element;

    for(int i = position; i < this->size; i++)
        tempTable[i] = table[i - 1];

    // deleting old table and setting main pointer to tempTable

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
    erase(table[this->size]);
}


template<typename T>
void BinaryHeap<T>::addEnd(T value) {

    add(value, this->size - 1);
}

template<typename T>
int BinaryHeap<T>::erase(T value) {

    // searching element position of provided value
    auto elementPosition = search(value);

    if(elementPosition == -1){
        return -1;
    }

    //swapping root with element to erase

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

    // linear searching function

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

template<typename T>
void BinaryHeap<T>::menu() {

    int tempChoice;
    T element;

    while(true) {

        std::cout << "1. Add Element\n2. Delete Element\n3. Search Element\n4. Draw\n"
            << "5. Write data to file\n6. Create structure from file\n7. Exit\n";
        std::cin >> tempChoice;

        switch (tempChoice) {

            case 1:
                std::cout << "Type value to add: \n";
                std::cin >> element;
                addEnd(element);
                break;
            case 2:
                std::cout << "Type value to erase: \n";
                std::cin >> element;

                if(erase(element) == -1)
                    std::cout << "Element not found! Couldn't erase.\n";

                else
                    std::cout << "Element erased successfully!\n";

                break;
            case 3:
                std::cout << "Type value to search: \n";
                std::cin >> element;

                if(search(element) == -1)
                    std::cout << "Element not found!\n";

                else
                    std::cout << "Element found!\n";
                break;
            case 4:
                printHeap();
                break;
            case 5:
                this->fileManager->manualWriteToFile();
                break;
            case 6:
                this->createStructure();
                break;
            case 7:
                exit(0);
            default:
                return;
        }
    }
}

template<typename T>
void BinaryHeap<T>::createStructure() {

    T element;
    int dataSize = this->fileManager->readManualData();

    for(int i = 0; i < dataSize; i++){
        element = this->fileManager->readManualData();
        this->addFront(element);
    }
}

template<typename T>
T BinaryHeap<T>::getRandomValue() {
    return table[rand() % ((this->size - 3) + 1)];
}
