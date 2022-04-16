#include "main.hpp"


int main() {

    srand(time(nullptr));

    DataStructure<int> * data = new DynamicArray<int>;

    if(dynamic_cast<BinaryHeap<int>*>(data)){
        std::cout << "i hope she made lotsa spaghetti!";
    }
    else if(dynamic_cast<DynamicArray<int>*>(data)){
        std::cout << "Bracia commitowniczy";
    }

    return 0;
}

