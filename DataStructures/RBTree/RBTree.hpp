#ifndef SDIZO_1_RBTREE_HPP
#define SDIZO_1_RBTREE_HPP

#include "../DataStructure.hpp"

template<typename T>
class TreeElement{

    T value {0};

    TreeElement* left {nullptr};
    TreeElement* right {nullptr};
    TreeElement* parent {nullptr};

public:

    enum Color{
        RED, BLACK
    };

    Color color;

    TreeElement();
    TreeElement(T, Color,TreeElement<T>*, TreeElement<T>*);
    ~TreeElement();

    void setGuardian();
    void setColor(Color);

    TreeElement* getLeft(){
        return left;
    }
    TreeElement* getRight(){
        return right;
    }
    TreeElement* getParent(){
        return parent;
    }

    T getValue(){
        return value;
    }
};

template<typename T>
class RBTree : public DataStructure<T>{

    TreeElement<T> guardian;
    TreeElement<T>* root {nullptr};
    int size {0};

public:

    void bstInsert(T);

    RBTree();

    TreeElement<T>& operator[](int);

    void rotateLeft(TreeElement<T>*);
    void rotateRight(TreeElement<T>*);

    void addElement(T);
    void deleteElement(T);
    TreeElement<T>* searchElement(T);

    void printTree();
};


#endif
