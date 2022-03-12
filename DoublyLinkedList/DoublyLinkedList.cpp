#include "DoublyLinkedList.h"

//////////////////////////////
// Functions of ListElement //
//////////////////////////////
DLL::ListElement::ListElement() {

}

DLL::ListElement::ListElement(int value_, ListElement* previous_, ListElement* next_)
:value(value_), previous(previous_), next(next_) {

}

//////////////////////////////
//     Functions of DLL     //
//////////////////////////////

DLL::DoublyLinkedList::DoublyLinkedList(){

}


void DLL::DoublyLinkedList::addFront(int value) {

}

long DLL::DoublyLinkedList::addMiddle(int, int) {
    return 0;
}

long DLL::DoublyLinkedList::addEnd(int) {
    return 0;
}

long DLL::DoublyLinkedList::deleteFront() {
    return 0;
}

long DLL::DoublyLinkedList::deleteMiddle(int) {
    return 0;
}

long DLL::DoublyLinkedList::deleteEnd() {
    return 0;
}

DLL::ListElement* DLL::DoublyLinkedList::operator[](int index) {

    ListElement* returnedElement {nullptr};

    if(head == nullptr) return nullptr;
    else{
        auto current {head};

        for(int i = 0; i < index; i++)
        {
            returnedElement = current->getNext();
            current = returnedElement;
        }
    }

    return returnedElement;
}
