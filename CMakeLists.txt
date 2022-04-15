cmake_minimum_required(VERSION 3.20)
project(SDIZO_1)

set(CMAKE_CXX_STANDARD 23)

link_libraries(stdc++fs)

add_executable(SDIZO_1 main.cpp DataStructures/DynamicArray/DynamicArray.tpp DataStructures/DynamicArray/DynamicArray.hpp DataStructures/DoublyLinkedList/DoublyLinkedList.tpp DataStructures/DoublyLinkedList/DoublyLinkedList.hpp Utility/Timer.cpp Utility/Timer.h Utility/FileManager.cpp Utility/FileManager.h DataStructures/BinaryHeap/BinaryHeap.tpp DataStructures/BinaryHeap/BinaryHeap.hpp main.hpp DataStructures/DataStructure.tpp DataStructures/DataStructure.hpp DataStructures/RBTree/RBTree.tpp DataStructures/RBTree/RBTree.hpp)
