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

////////////////////
////// RBTree //////
////////////////////

TreeElement& RBTree::operator[](int position) {

}