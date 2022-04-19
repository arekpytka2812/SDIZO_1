cmake_minimum_required(VERSION 3.20)
project(SDIZO_1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

link_libraries(stdc++fs)

add_executable(SDIZO_1          main.cpp

                                DataStructures/DynamicArray/DynamicArray.tpp
                                DataStructures/DynamicArray/DynamicArray.hpp

                                DataStructures/DoublyLinkedList/DoublyLinkedList.tpp
                                DataStructures/DoublyLinkedList/DoublyLinkedList.hpp

                                Utility/Timer/Timer.cpp
                                Utility/Timer/Timer.h

                                Utility/FileManager/FileManager.tpp
                                Utility/FileManager/FileManager.hpp

                                DataStructures/BinaryHeap/BinaryHeap.tpp
                                DataStructures/BinaryHeap/BinaryHeap.hpp

                                main.hpp

                                DataStructures/DataStructure.tpp
                                DataStructures/DataStructure.hpp

                                DataStructures/RBTree/RBTree.tpp
                                DataStructures/RBTree/RBTree.hpp

                                Utility/Tests/Tests.tpp
                                Utility/Tests/Tests.hpp Utility/Menu.tpp Utility/Menu.hpp)
