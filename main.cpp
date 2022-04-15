#include "main.h"


int main() {

    srand(time(nullptr));

    DynamicArray dynamicArray;
    BinaryHeap binaryHeap;

    binaryHeap.addElement(12);
    binaryHeap.printHeap();
    std::cout << "\n";


    binaryHeap.addElement(124);
    binaryHeap.printHeap();
    std::cout << "\n";

    binaryHeap.addElement(112);
    binaryHeap.printHeap();
    std::cout << "\n";

    binaryHeap.addElement(542);
    binaryHeap.printHeap();
    std::cout << "\n";

    binaryHeap.addElement(998);
    binaryHeap.printHeap();
    std::cout << "\n";

    binaryHeap.addElement(1);
    binaryHeap.printHeap();
    std::cout << "\n";

    return 0;
}

