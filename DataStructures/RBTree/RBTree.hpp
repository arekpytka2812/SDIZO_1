#ifndef SDIZO_1_RBTREE_HPP
#define SDIZO_1_RBTREE_HPP

#include "../DataStructure.hpp"

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
    int size {0};

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
    void erase(T) override;

    void addElement(T);
    TreeElement<T>* searchElement(T);

    void printTree();
};


#endif
