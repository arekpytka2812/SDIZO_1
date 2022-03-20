#include "DynamicArray/DynamicArray.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

int main() {

    auto list = new DoublyLinkedList;

    for(int i = 0; i < 5; i++)
        list->addMiddle(i, i);

    list->displayList();

    std::cout << list->search(2);

    return 0;
}

