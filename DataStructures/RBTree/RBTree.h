#ifndef SDIZO_1_RBTREE_H
#define SDIZO_1_RBTREE_H

#include "../DataStructure.h"

class TreeElement{

    int value {0};
    std::string color;

    TreeElement* left {nullptr};
    TreeElement* right {nullptr};
    TreeElement* parent {nullptr};


public:

    TreeElement();
    TreeElement(int, std::string);
    ~TreeElement();

};

class RBTree : public DataStructure{

public:

    TreeElement& operator[](int);

};


#endif
