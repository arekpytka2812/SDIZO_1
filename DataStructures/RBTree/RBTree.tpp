#include "RBTree.hpp"

template<typename T>
TreeElement<T>::TreeElement() {

}

template<typename T>
TreeElement<T>::TreeElement(T value_, Color color_) {
    this->value = value_;
    this->color = color_;
}

template<typename T>
TreeElement<T>::~TreeElement() {
    this->value = 0;
    this->color = RED;
}

template<typename T>
void TreeElement<T>::setGuardian() {
    this->value = 0;
    this->color = BLACK;

    this->left = this;
    this->right = this;
    this->parent = this;
}

template<typename T>
void TreeElement<T>::setColor(Color color_){
    this->color = color_;
}

////////////////////
////// RBTree //////
////////////////////

template<typename T>
void RBTree<T>::BstInsert(int value) {

    auto tempElement = root;

    while(tempElement != &guardian){

    }

}

template<typename T>
RBTree<T>::RBTree() {

    guardian.setGuardian();

    root = &guardian;

}

template<typename T>
void RBTree<T>::rotateLeft(TreeElement<T>* node) {

}

template<typename T>
void RBTree<T>::rotateRight(TreeElement<T> * node) {

}

template<typename T>
void RBTree<T>::addElement(T value) {

}

template<typename T>
void RBTree<T>::deleteElement(T value) {

}

template<typename T>
TreeElement<T>* RBTree<T>::searchElement(T value) {

    auto tempElement = root;

    while (tempElement != &guardian){

        if(value < tempElement->getValue())
            tempElement = tempElement->getLeft();

        else if(value > tempElement->getValue())
            tempElement = tempElement->getRight();

        else
            return tempElement;
    }

    return nullptr;
}