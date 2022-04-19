#ifndef SDIZO_1_DOUBLYLINKEDLIST_HPP
#define SDIZO_1_DOUBLYLINKEDLIST_HPP

#include "../DataStructure.hpp"

#include <cstdlib>
#include <iostream>
#include <chrono>

template<typename T>
    class ListElement{
        T value {0};

        ListElement<T>* previous {nullptr};
        ListElement<T>* next {nullptr};

    public:
        ListElement();
        ListElement(T, ListElement<T>*, ListElement<T>*);

        [[nodiscard]] T getValue() const{
            if(this != nullptr)
                return value;
            return -1;
        }

        [[nodiscard]] ListElement<T>* getNext() const{
            return next;
        }

        [[nodiscard]] ListElement<T>* getPrevious() const{
            return previous;
        }

        void setNext(ListElement<T>* next_){
            next = next_;
        }

        void setPrevious(ListElement<T>* previous_){
            previous = previous_;
        }
    };

    template<typename T>
    class DoublyLinkedList : public DataStructure<T> {

        ListElement<T>* head {nullptr};
        ListElement<T>* tail {nullptr};

    public:

        ListElement<T>& operator[](int);

        void addFront(T) override;
        void add(T, int) override;
        void addEnd(T) override;

        void deleteFront() override;
        void deleteEnd() override;
        int erase(T) override;

        int search(T) override;

        void displayList();

        void menu() override;

        DoublyLinkedList();
    };








#endif
