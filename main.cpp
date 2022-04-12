#include "main.h"


int main() {

    int size = 5;
    int* tempTable = new int[size];

    tempTable[0] = 4;
    tempTable[1] = 6;
    tempTable[2] = 1;
    tempTable[3] = 8;
    tempTable[4] = 23;

    BinaryHeap heap(size, tempTable);

    heap.deleteElement(1);

    heap.addElement(345);
    heap.addElement(35);
    heap.addElement(36768);
    heap.addElement(3905);

    return 0;
}

