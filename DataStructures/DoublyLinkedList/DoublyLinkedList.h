#ifndef SDIZO_1_DOUBLYLINKEDLIST_H
#define SDIZO_1_DOUBLYLINKEDLIST_H

#include "../DataStructure.h"

#include <cstdlib>
#include <iostream>
#include <chrono>

    class ListElement{
        int value {0};

        ListElement* previous {nullptr};
        ListElement* next {nullptr};

    public:
        ListElement();
        ListElement(int, ListElement*, ListElement*);
        ListElement(int, ListElement, ListElement);



        [[nodiscard]] int getValue() const{
            if(this != nullptr)
                return value;
            return -1;
        }

        [[nodiscard]] ListElement* getNext() const{
            return next;
        }

        [[nodiscard]] ListElement* getPrevious() const{
            return previous;
        }

        void setNext(ListElement* next_){
            next = next_;
        }

        void setPrevious(ListElement* previous_){
            previous = previous_;
        }

        [[nodiscard]] ListElement* getNext(){
            return next;
        }

    };

    class DoublyLinkedList : public DataStructure {

        int size = 0;
        ListElement* head {nullptr};
        ListElement* tail {nullptr};

    public:

        ListElement& operator[](int);

        void addFront(int);
        void addMiddle(int, int);
        void addEnd(int);

        void deleteFront();
        void deleteMiddle(int);
        void deleteEnd();

        int search(int);

        void displayList();

        DoublyLinkedList();
    };








#endif
