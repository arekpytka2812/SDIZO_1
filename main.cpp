#include "main.hpp"


int main() {

    srand(time(nullptr));

    DataStructure<int>* data[4];

    data[0] = new DynamicArray<int>;
    data[1] = new DoublyLinkedList<int>;
    data[2] = new BinaryHeap<int>;
    data[3] = new RBTree<int>;

    data[3]->add(12, -1);
    data[3]->add(6, -1);
    data[3]->add(6123, -1);
    data[3]->add(434, -1);
    data[3]->add(1, -1);

    data[3]->erase(434);





    return 0;
}

