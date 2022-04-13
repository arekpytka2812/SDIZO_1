#include "main.h"


int main() {

    int size = 5;
    auto tempTable = new int[size];

    tempTable[0] = 4;
    tempTable[1] = 6;
    tempTable[2] = 1;
    tempTable[3] = 8;
    tempTable[4] = 23;

    BinaryHeap heap(size, tempTable);

    heap.printHeap();

    heap.deleteElement(1);

    heap.printHeap();

    return 0;
}

