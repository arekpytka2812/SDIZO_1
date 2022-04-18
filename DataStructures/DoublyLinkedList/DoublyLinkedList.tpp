#include "DoublyLinkedList.hpp"

//////////////////////////////
// Functions of ListElement //
//////////////////////////////
template<typename T>
ListElement<T>::ListElement() {

}

template<typename T>
ListElement<T>::ListElement(T value_, ListElement<T>* previous_, ListElement<T>* next_)
:value(value_), previous(previous_), next(next_) {

    if(next_ != nullptr)
        next_ ->setPrevious(this);

    if(previous_ != nullptr)
        previous_ ->setNext(this);


}

//////////////////////////////
//     Functions of DLL     //
//////////////////////////////

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->fileManager = new FileManager<T>("DoublyLinkedList");
    this->timer = new Timer;
}

template<typename T>
ListElement<T>& DoublyLinkedList<T>::operator[](int pos) {

    if(pos >= static_cast<int>(this->size/2)){
        auto current = tail;

        for(int i = this->size - 1; i > pos; i--)
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

template<typename T>
void DoublyLinkedList<T>::addFront(T element) {

    if(this->size == 0) {
        head = new ListElement<T>(element, nullptr, nullptr);
        tail = head;
    }
    else{
        head = new ListElement<T>(element, nullptr, head);
    }
    this->size++;
}

template<typename T>
void DoublyLinkedList<T>::add(T element, int position) {

    if(position == this->size){
        addEnd(element);
        return;
    }

    if(position == 0 || position == -1){
        addFront(element);
        return;
    }

    if(position > 0 && position < this->size - 1) {
        auto tempNext = &(*this)[position], tempPrevious = &(*this)[position - 1];

        auto tempElement = new ListElement<T>(element, tempPrevious, tempNext);

        this->size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::addEnd(T element) {

    if(this->size == 0) {
        tail = new ListElement<T>(element, nullptr, nullptr);
        head = tail;
    }
    else{
        tail = new ListElement<T>(element, tail, nullptr);
    }
    this->size++;
}

template<typename T>
void DoublyLinkedList<T>::deleteFront() {

    auto tempHead = head;

    head = &(*this)[1];
    head->setPrevious(nullptr);

    tempHead->setNext(nullptr);
    delete tempHead;

    this->size--;
}

template<typename T>
int DoublyLinkedList<T>::erase(T value) {

    auto position = search(value);

    if(position == -1){
        return -1;
    }

    if(position == 0){
        deleteFront();
        return 1;
    }

    if(position == this->size){
        deleteEnd();
        return 1;
    }


    auto tempPrevious = (*this)[position].getPrevious(), tempNext = (*this)[position].getNext();

    delete &(*this)[position];

    tempPrevious->setNext(tempNext);
    tempNext->setPrevious(tempPrevious);

    this->size--;

    return 1;
}

template<typename T>
void DoublyLinkedList<T>::deleteEnd() {

    auto tempTail = tail;

    tail = &(*this)[this->size - 2];
    tail ->setNext(nullptr);

    tempTail->setPrevious(nullptr);
    delete tempTail;

    this->size--;
}

template<typename T>
int DoublyLinkedList<T>::search(T element){

    for(int i = 0; i < this->size; i++)
        if((*this)[i].getValue() == element)
            return i;

    return -1;
}

template<typename T>
void DoublyLinkedList<T>::displayList() {

    auto current = head;

    for(int i = 0; i < this->size; i++){
        std::cout << current->getPrevious()->getValue() << "<-" << current->getValue() << "->" << current->getNext()->getValue() << "\n";
        current = current->getNext();
    }

    std::cout << "\n";
}
