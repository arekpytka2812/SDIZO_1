#include "RBTree.h"

TreeElement::TreeElement() {

}

TreeElement::TreeElement(int value_, Color color_ = BLACK) {
    this->value = value_;
    this->color = color_;
}

TreeElement::~TreeElement() {
    this->value = 0;
    this->color = RED;
}

void TreeElement::setGuard() {
    this->value = 0;
    this->color = BLACK;

    this->left = this;
    this->right = this;
    this->parent = this;
}

////////////////////
////// RBTree //////
////////////////////

RBTree::RBTree() {

    guard.setGuard();

    root = &guard;

}