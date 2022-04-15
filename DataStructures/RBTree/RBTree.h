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

    void setGuard();

    TreeElement* getLeft(){
        return left;
    }
    TreeElement* getRight(){
        return right;
    }
    TreeElement* getParent(){
        return parent;
    }
};

class RBTree : public DataStructure{

    TreeElement guard;
    TreeElement* root {nullptr};
    int size {0};

public:

    RBTree();

    TreeElement& operator[](int);

    void rotateLeft(TreeElement*);
    void rotateRight(TreeElement*);
};


#endif
