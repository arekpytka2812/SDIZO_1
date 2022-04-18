#ifndef SDIZO_1_TESTS_HPP
#define SDIZO_1_TESTS_HPP


template<typename T>
class Tests {

    Timer* timer = new Timer;

    int getRandomIndex(DataStructure<T>*);
    T getRandomData();

public:

    void addFront(DataStructure<T>*);
    void add(DataStructure<T>*);
    void addEnd(DataStructure<T>*);

    void deleteFront(DataStructure<T>*);
    void erase(DataStructure<T>*);
    void deleteEnd(DataStructure<T>*);

    void search(DataStructure<T>*);

    void allTests(DataStructure<T>*);

};


#endif
