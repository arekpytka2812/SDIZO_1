#ifndef SDIZO_1_DYNAMICTABLE_H
#define SDIZO_1_DYNAMICTABLE_H

#include <cstdlib>
#include <iostream>
#include <chrono>


namespace DT{

    class DynamicTable {

        int* table = {nullptr};
        int size = {0};

        int amountOfSamples = 10;

        long long addFront(int*);
        long long addMiddle(int, int);
        long long addEnd(int*);

        long long deleteFront(int);
        long long deleteMiddle(int);
        long long deleteEnd(int);

        int* prepareSamples();

        void addElement();
        void deleteElement();
        void searchElement();

        void drawTable();

    public:

        DynamicTable();
        explicit DynamicTable(int);
        ~DynamicTable();

        void menu();



    };

}



#endif //SDIZO_1_DYNAMICTABLE_H
