#include "main.hpp"


int main() {

    srand(time(nullptr));

    DataStructure<int>* data[4];

    data[0] = new DynamicArray<int>;
    data[1] = new DoublyLinkedList<int>;
    data[2] = new BinaryHeap<int>;
    data[3] = new RBTree<int>;

    Tests<int>* tests = new Tests<int>;

    tests->allTests(data[0]);
    tests->allTests(data[1]);
    tests->allTests(data[2]);
    tests->allTests(data[3]);


    return 0;
}

