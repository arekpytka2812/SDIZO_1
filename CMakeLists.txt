cmake_minimum_required(VERSION 3.20)
project(SDIZO_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDIZO_1 main.cpp DataStructures/DynamicArray/DynamicArray.cpp DataStructures/DynamicArray/DynamicArray.h DataStructures/DoublyLinkedList/DoublyLinkedList.cpp DataStructures/DoublyLinkedList/DoublyLinkedList.h Utility/Timer.cpp Utility/Timer.h Utility/FileManager.cpp Utility/FileManager.h DataStructures/BinaryHeap/BinaryHeap.cpp DataStructures/BinaryHeap/BinaryHeap.h main.h DataStructures/DataStructure.cpp DataStructures/DataStructure.h DataStructures/RBTree/RBTree.cpp DataStructures/RBTree/RBTree.h)
