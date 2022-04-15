#ifndef SDIZO_1_DOUBLYLINKEDLIST_HPP
#define SDIZO_1_DOUBLYLINKEDLIST_HPP

#include "../DataStructure.hpp"

#include <cstdlib>
#include <iostream>
#include <chrono>

template<typename T>
    class ListElement{
        T value {0};

        ListElement* previous {nullptr};
        ListElement* next {nullptr};

    public:
        ListElement();
        ListElement(T, ListElement*, ListElement*);



        [[nodiscard]] T getValue() const{
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

    template<typename T>
    class DoublyLinkedList : public DataStructure<T> {

        int size = 0;
        ListElement<T>* head {nullptr};
        ListElement<T>* tail {nullptr};

    public:

        T& operator[](int);

        void addFront(T);
        void addMiddle(int, T);
        void addEnd(T);

        void deleteFront();
        void deleteMiddle(int);
        void deleteEnd();

        int search(T);

        void displayList();

        DoublyLinkedList();
    };








#endif
