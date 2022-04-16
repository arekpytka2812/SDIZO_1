#ifndef SDIZO_1_TESTS_HPP
#define SDIZO_1_TESTS_HPP


template<typename T>
class Tests {

public:

    void addFront(DataStructure<T>*);
    void addMiddle(DataStructure<T>*);
    void addEnd(DataStructure<T>*);

    void search(DataStructure<T>*);

    void deleteFront(DataStructure<T>*);
    void deleteMiddle(DataStructure<T>*);
    void deleteEnd(DataStructure<T>*);

};


#endif
