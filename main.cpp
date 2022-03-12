#include "DynamicArray/DynamicArray.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

int main() {

    srand(time(nullptr));

    auto table = new DT::DynamicArray(5);

    DT::DynamicArray dynamicTable;

    table -> menu();

    delete table;

    auto list = new DLL::DoublyLinkedList;

    for(int i = 0; i < 5; i++)
        list->addFront(i);

    for(int i = 0; i < 5; i++)
        std::cout << list->getList()[i]->getValue() << std::endl;

    return 0;
}

