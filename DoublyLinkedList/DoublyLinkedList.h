#ifndef SDIZO_1_DOUBLYLINKEDLIST_H
#define SDIZO_1_DOUBLYLINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <chrono>

namespace DLL{

    class ListElement{
        int value {0};

        ListElement* previous {nullptr};
        ListElement* next {nullptr};

    public:
        ListElement();
        ListElement(int, ListElement*, ListElement*);

        [[nodiscard]] int getValue() const{
            return value;
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

        ListElement* getNext(){
            return next;
        }

    };

    class DoublyLinkedList {

        int size = 0;
        ListElement* head {nullptr};
        ListElement* tail {nullptr};

    public:

        void addFront(int);
        long addMiddle(int, int);
        long addEnd(int);

        long deleteFront();
        long deleteMiddle(int);
        long deleteEnd();

        ListElement* operator[](int) override;


        DoublyLinkedList();
    };



}




#endif
