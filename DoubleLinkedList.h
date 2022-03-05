#ifndef SDIZO_1_DOUBLELINKEDLIST_H
#define SDIZO_1_DOUBLELINKEDLIST_H

namespace DLL{

    class ListElement{
        const int value = 0;

        ListElement* previous = nullptr;
        ListElement* next = nullptr;

    public:
        explicit ListElement(int);

        int getValue() const{
            return value;
        }
    };

    class DoubleLinkedList {

        int size = 0;
        ListElement* list = nullptr;

        long addFront(int);
        long addMiddle(int, int);
        long addEnd(int);

        long deleteFront();
        long deleteMiddle(int);
        long deleteEnd();
    };

}




#endif
