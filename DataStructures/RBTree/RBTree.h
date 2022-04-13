#ifndef SDIZO_1_RBTREE_H
#define SDIZO_1_RBTREE_H

#include "../DataStructure.h"

class TreeElement{

    int value {0};

    TreeElement* left {nullptr};
    TreeElement* right {nullptr};
    TreeElement* parent {nullptr};


public:

    enum Color{
        RED, BLACK
    };

    Color color;

    TreeElement();
    TreeElement(int, Color);
    ~TreeElement();

};

class RBTree : public DataStructure{

    TreeElement* root {nullptr};

    void rotateLeft();
    void rotateRight();

public:

    TreeElement& operator[](int);
};


#endif
