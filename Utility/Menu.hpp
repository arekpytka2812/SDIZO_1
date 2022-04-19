#ifndef SDIZO_1_MENU_HPP
#define SDIZO_1_MENU_HPP

#include "../DataStructures/DataStructure.hpp"
#include "../DataStructures/DynamicArray/DynamicArray.hpp"
#include "../DataStructures/DynamicArray/DynamicArray.tpp"
#include "../DataStructures/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../DataStructures/DoublyLinkedList/DoublyLinkedList.tpp"
#include "../DataStructures/BinaryHeap/BinaryHeap.hpp"
#include "../DataStructures/BinaryHeap/BinaryHeap.tpp"
#include "../DataStructures/RBTree/RBTree.hpp"
#include "../DataStructures/RBTree/RBTree.tpp"
#include "FileManager/FileManager.hpp"
#include "FileManager/FileManager.tpp"
#include "Timer/Timer.h"
#include "Tests/Tests.hpp"
#include "Tests/Tests.tpp"

template<typename T>
class Menu {

    DataStructure<T>* data[4];

    std::string listOfStructures;

    void manualTests();
    void automaticTests();

public:

    Menu();
    ~Menu();

    void mainMenu();


};


#endif