#include "RBTree.hpp"

template<typename T>
TreeElement<T>::TreeElement() {

}

template<typename T>
TreeElement<T>::TreeElement(T value_, Color color_, TreeElement<T>* left_, TreeElement<T>* right_)
: value(value_), color(color_), left(left_), right(right_) {

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
void RBTree<T>::bstInsert(const T value) {

    auto tempElement = root;

    if(size == 0){
        root = new TreeElement<T>(value, TreeElement<T>::BLACK, guardian, guardian);
        return;
    }

    while(tempElement != &guardian){
        if(value < tempElement->getValue())
            tempElement = tempElement->getLeft();
        if(value > tempElement->getValue())
            tempElement = tempElement->getRight();
    }

    tempElement = new TreeElement<T>(value, TreeElement<T>::BLACK, guardian, guardian);
    size++;
}

template<typename T>
RBTree<T>::RBTree() {

    this->fileManager = new FileManager("RBTree");
    this->timer = new Timer;

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
