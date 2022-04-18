#ifndef SDIZO_1_RBTREE_HPP
#define SDIZO_1_RBTREE_HPP

#include "../DataStructure.hpp"

#include <math.h>
#include <windows.h>

template<typename T>
class TreeElement{

    T value {0};

    TreeElement<T>* left {nullptr};
    TreeElement<T>* right {nullptr};
    TreeElement<T>* parent {nullptr};

public:

    enum Color{
        RED, BLACK
    };

    Color color;

    TreeElement();
    TreeElement(T, Color, TreeElement<T>*, TreeElement<T>*, TreeElement<T>*);
    ~TreeElement();

    void setGuardian();

    void setElement(char, TreeElement<T>*);

    void setValue(T value_){
        this->value = value_;
    }

    TreeElement<T>* getLeft(){
        return left;
    }
    TreeElement<T>* getRight(){
        return right;
    }
    TreeElement<T>* getParent(){
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

    void bstInsert(TreeElement<T>*);
    TreeElement<T>* findMIN(TreeElement<T>*);
    TreeElement<T>* findMAX(TreeElement<T>*);
    TreeElement<T>* treeSuccessor(TreeElement<T>*);
    void deleteFix(TreeElement<T>*);

public:

    RBTree();

    TreeElement<T>& operator[](int);

    void rotateLeft(TreeElement<T>*);
    void rotateRight(TreeElement<T>*);

    void addFront(T) override;
    void add(T, int) override;
    void addEnd(T) override;

    void deleteFront() override;
    void deleteEnd() override;
    int erase(T) override;

    int search(T) override;

    TreeElement<T>* searchElement(T);

    void print(std::ostream&);

    void calculateDepth(TreeElement<T>*, size_t&, size_t);
    void placeNodes(TreeElement<T>*, TreeElement<T>**, size_t);
};


#endif
