cmake_minimum_required(VERSION 3.20)
project(SDIZO_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDIZO_1 main.cpp DynamicArray/DynamicArray.cpp DynamicArray/DynamicArray.h DoublyLinkedList/DoublyLinkedList.cpp DoublyLinkedList/DoublyLinkedList.h)
