#include "Tests.hpp"

template<typename T>
int Tests<T>::getRandomIndex(DataStructure<T>* structure){
    return rand() % (structure->getSize() - 3) + 2;
}

template<typename T>
T Tests<T>::getRandomData() {
    return rand();
}

template<typename T>
void Tests<T>::addFront(DataStructure<T> *structure) {

    if(dynamic_cast<BinaryHeap<T>*>(structure) or dynamic_cast<RBTree<T>*>(structure)){
        return;
    }
    else{
        for(int i = 0; i < 5; i++){

            auto amountOfData = structure->getManager()->readData();

            for(int j = 0; j < amountOfData; j++){
                    // filling structure with samples
                    structure->add(structure->getManager()->readData(), -1);
            }

            timer->startTimer();

            for(int k = 0; k < 100; k++){
                structure->addFront(this->getRandomData());
            }

            auto time = timer->getDuration()/100;

            structure->getManager()->writeToFile(0, time, amountOfData);

            while(structure->getSize() != 0)
                structure->deleteFront();
        }

        structure->getManager()->setPointer();

    }

}

template<typename T>
void Tests<T>::add(DataStructure<T>* structure){

    for(int i = 0; i < 5; i++){

        auto amountOfData = structure->getManager()->readData();

        for(int j = 0; j < amountOfData; j++){
            structure->add(structure->getManager()->readData(), -1);
        }

        timer->startTimer();

        for(int k = 0; k < 100; k++){
            structure->add(this->getRandomData(), this->getRandomIndex(structure));
        }

        auto time = timer->getDuration()/100;

        structure->getManager()->writeToFile(1, time, amountOfData);

        while(structure->getSize() != 0)
            structure->deleteFront();
    }

    structure->getManager()->setPointer();
}

template<typename T>
void Tests<T>::addEnd(DataStructure<T>* structure){

    if(dynamic_cast<BinaryHeap<T>*>(structure) or dynamic_cast<RBTree<T>*>(structure)){
        return;
    }
    else{
        for(int i = 0; i < 5; i++){

            auto amountOfData = structure->getManager()->readData();

            for(int j = 0; j < amountOfData; j++){

                // filling structure with samples
                structure->add(structure->getManager()->readData(), -1);
            }

            timer->startTimer();

            for(int k = 0; k < 100; k++){
                structure->addEnd(this->getRandomData());
            }

            auto time = timer->getDuration()/100;

            structure->getManager()->writeToFile(2, time, amountOfData);

            while(structure->getSize() != 0)
                structure->deleteFront();
        }

        structure->getManager()->setPointer();

    }

}

template<typename T>
void Tests<T>::deleteFront(DataStructure<T>* structure){

    if(dynamic_cast<BinaryHeap<T>*>(structure) or dynamic_cast<RBTree<T>*>(structure)){
        return;
    }
    else{
        for(int i = 0; i < 5; i++){

            auto amountOfData = structure->getManager()->readData();

            for(int j = 0; j < amountOfData; j++){
                // filling structure with samples
                structure->add(structure->getManager()->readData(), -1);
            }

            timer->startTimer();

            for(int k = 0; k < 100; k++){
                structure->deleteFront();
            }

            auto time = timer->getDuration()/100;

            structure->getManager()->writeToFile(3, time, amountOfData);

            while(structure->getSize() != 0)
                structure->deleteFront();
        }

        structure->getManager()->setPointer();

    }
}

template<typename T>
void Tests<T>::erase(DataStructure<T>* structure){

    for(int i = 0; i < 5; i++){

        auto amountOfData = structure->getManager()->readData();

        for(int j = 0; j < amountOfData; j++){
            structure->add(structure->getManager()->readData(), -1);
        }

        timer->startTimer();

        int successfulSamples = 0;

        for(int k = 0; k < 100; k++){
            if((structure->erase(this->getRandomData())) != -1) {
                successfulSamples++;
            }
        }

        auto time = timer->getDuration()/successfulSamples;

        structure->getManager()->writeToFile(4, time, amountOfData);

        while(structure->getSize() != 0)
            structure->deleteFront();
    }

    structure->getManager()->setPointer();


}

template<typename T>
void Tests<T>::deleteEnd(DataStructure<T>* structure){

    if(dynamic_cast<BinaryHeap<T>*>(structure) or dynamic_cast<RBTree<T>*>(structure)){
        return;
    }
    else{
        for(int i = 0; i < 5; i++){

            auto amountOfData = structure->getManager()->readData();

            for(int j = 0; j < amountOfData; j++){
                // filling structure with samples
                structure->add(structure->getManager()->readData(), -1);
            }

            timer->startTimer();

            for(int k = 0; k < 100; k++){
                structure->deleteEnd();
            }

            auto time = timer->getDuration()/100;

            structure->getManager()->writeToFile(5, time, amountOfData);

            while(structure->getSize() != 0)
                structure->deleteFront();
        }

        structure->getManager()->setPointer();

    }
}

template<typename T>
void Tests<T>::search(DataStructure<T>* structure){

    for(int i = 0; i < 5; i++){

        auto amountOfData = structure->getManager()->readData();

        for(int j = 0; j < amountOfData; j++){
            structure->add(structure->getManager()->readData(), -1);
        }

        timer->startTimer();

        int successfulSamples = 0;

        for(int k = 0; k < 100; k++){

            if((structure->search(this->getRandomData())) != -1){
                successfulSamples++;
            }

        }

        auto time = timer->getDuration()/successfulSamples;

        structure->getManager()->writeToFile(6, time, amountOfData);

        while(structure->getSize() != 0)
            structure->deleteFront();
    }

    structure->getManager()->setPointer();

}

template<typename T>
void Tests<T>::allTests(DataStructure<T> * structure) {

    this->addFront(structure);
    this->add(structure);
    this->addEnd(structure);

    this->deleteFront(structure);
    this->erase(structure);
    this->deleteEnd(structure);

    this->search(structure);
}

