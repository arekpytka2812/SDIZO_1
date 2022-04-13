#include "RBTree.h"



TreeElement::TreeElement() {

}

TreeElement::TreeElement(int value_, std::string color_) {
    this->value = value_;
    this->color = color_;
}

TreeElement::~TreeElement() {
    this->value = 0;
    this->color = "bruh";
}

////////////////////
////// RBTree //////
////////////////////

TreeElement& RBTree::operator[](int position) {

}