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

            double time = 0;

            for(int k = 0; k < 100; k++){

                timer->startTimer();
                structure->addFront(this->getRandomData());
                time += timer->getDuration();

                structure->deleteFront();
            }

            time /= 100; // dividing by amount of iterations

            structure->getManager()->autoWriteToFile(0, time, amountOfData);

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
            structure->add(structure->getManager()->readData(), structure->getSize());
        }

        double time = 0;

        for(int k = 0; k < 100; k++){
            timer->startTimer();
            structure->add(this->getRandomData(), this->getRandomIndex(structure));
            time += timer->getDuration();
            structure->deleteFront();
        }

        time /= 100;

        structure->getManager()->autoWriteToFile(1, time, amountOfData);

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

            double time = 0;

            for(int k = 0; k < 100; k++){
                timer->startTimer();
                structure->addEnd(this->getRandomData());
                time += timer->getDuration();
                structure->deleteFront();
            }

            time /= 100;

            structure->getManager()->autoWriteToFile(2, time, amountOfData);

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

            double time = 0;

            for(int k = 0; k < 100; k++){
                timer->startTimer();
                structure->deleteFront();
                time += timer->getDuration();
                structure->addFront(getRandomData());
            }

            time /= 100;

            structure->getManager()->autoWriteToFile(3, time, amountOfData);

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
            structure->add(structure->getManager()->readData(), structure->getSize());
        }

        double time = 0;

        int successfulSamples = 0;

        for(int k = 0; k < 100; k++){

            timer->startTimer();

            if((structure->erase(this->getRandomData())) != -1) {
                time += timer->getDuration();
                successfulSamples++;
                structure->addFront(getRandomData());
            }
            else
                timer->getDuration();
        }

        time /= successfulSamples;

        structure->getManager()->autoWriteToFile(4, time, amountOfData);

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

            double time = 0;

            for(int k = 0; k < 100; k++){
                timer->startTimer();
                structure->deleteEnd();
                time += timer->getDuration();
                structure->addFront(getRandomData());
            }

            time /= 100;

            structure->getManager()->autoWriteToFile(5, time, amountOfData);

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
            structure->add(structure->getManager()->readData(), structure->getSize());
        }

        double time = 0;
        int successfulSamples = 0;

        for(int k = 0; k < 100; k++){

            timer->startTimer();
            if((structure->search(this->getRandomData())) != -1){
                time += timer->getDuration();
                successfulSamples++;
                structure->addFront(getRandomData());
            }
            else
                timer->getDuration();

        }

        time /= successfulSamples;

        structure->getManager()->autoWriteToFile(6, time, amountOfData);

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

