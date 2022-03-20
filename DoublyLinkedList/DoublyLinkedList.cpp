#include "DoublyLinkedList.h"

//////////////////////////////
// Functions of ListElement //
//////////////////////////////
ListElement::ListElement() {

}

ListElement::ListElement(int value_, ListElement* previous_, ListElement* next_)
:value(value_), previous(previous_), next(next_) {

    if(next_ != nullptr)
        next_ ->setPrevious(this);

    if(previous_ != nullptr)
        previous_ ->setNext(this);
}

//////////////////////////////
//     Functions of DLL     //
//////////////////////////////

DoublyLinkedList::DoublyLinkedList(){

}

ListElement& DoublyLinkedList::operator[](int pos) {

    if(head == nullptr)
        throw std::invalid_argument("List is empty!");

    if(pos >= size)
        throw std::out_of_range("You are out of range!");

    if(pos >= static_cast<int>(size/2)){
        auto current = tail;

        for(int i = size - 1; i > pos; i--)
            current = current->getPrevious();

        return *current;
    }
    else{
        auto current = head;

        for(int i = 0; i < pos; i++)
            current = current->getNext();

        return *current;
    }
}

void DoublyLinkedList::addFront(int value) {

    if(size == 0) {
        head = new ListElement(value, nullptr, nullptr);
        tail = head;
    }
    else{
        head = new ListElement(value, nullptr, head);
    }
    size++;
}

void DoublyLinkedList::addMiddle(int position, int value) {

    if(position == size){
        addEnd(value);
        return;
    }
    if(position == 0){
        addFront(value);
        return;
    }

    auto tempNext = &(*this)[position], tempPrevious = &(*this)[position - 1];

    auto tempElement = new ListElement(value, tempPrevious, tempNext);

    size++;
}

void DoublyLinkedList::addEnd(int value) {

    if(size == 0) {
        tail = new ListElement(value, nullptr, nullptr);
        head = tail;
    }
    else{
        tail = new ListElement(value, tail, nullptr);
    }
    size++;
}

void DoublyLinkedList::deleteFront() {

    auto tempHead = head;

    head = &(*this)[1];
    head->setPrevious(nullptr);

    tempHead->setNext(nullptr);
    delete tempHead;

    size--;
}

void DoublyLinkedList::deleteMiddle(int position) {

    if(position == 0){
        deleteFront();
        return;
    }

    if(position == size){
        deleteEnd();
        return;
    }

    auto tempPrevious = (*this)[position].getPrevious(), tempNext = (*this)[position].getNext();

    delete &(*this)[position];

    tempPrevious->setNext(tempNext);
    tempNext->setPrevious(tempPrevious);

    size--;
}

void DoublyLinkedList::deleteEnd() {

    auto tempTail = tail;

    tail = &(*this)[size - 2];
    tail ->setNext(nullptr);

    tempTail->setPrevious(nullptr);
    delete tempTail;

    size--;
}

int DoublyLinkedList::search(int value){

    for(int i = 0; i < size; i++)
        if((*this)[i].getValue() == value)
            return i;

    return -1;
}

void DoublyLinkedList::displayList() {

    auto current = head;

    for(int i = 0; i < size; i++){
        std::cout << current->getPrevious()->getValue() << "<-" << current->getValue() << "->" << current->getNext()->getValue() << "\n";
        current = current->getNext();
    }

    std::cout << "\n";
}
