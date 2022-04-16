#include "Tests.hpp"

template<typename T>
void Tests<T>::addFront(DataStructure<T> *structure) {

    int amountOfData = structure->getManager()->readData();

    if(dynamic_cast<BinaryHeap<T>*>(structure) or dynamic_cast<RBTree<T>*>(structure)){
        return;
    }
    else{

    }

}