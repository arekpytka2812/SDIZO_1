#include "RBTree.hpp"

template<typename T>
TreeElement<T>::TreeElement() {

}

template<typename T>
TreeElement<T>::TreeElement(T value_, Color color_, TreeElement<T>* left_, TreeElement<T>* right_, TreeElement<T>* parent_)
: value(value_), color(color_), left(left_), right(right_), parent(parent_) {

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
void TreeElement<T>::setElement(char whichOne, TreeElement<T>* node) {

    switch(whichOne){
        case 'l':
            left = node;
            break;
        case 'r':
            right = node;
            break;
        case 'p':
            parent = node;
            break;
    }
}

////////////////////
////// RBTree //////
////////////////////

template<typename T>
void RBTree<T>::bstInsert(TreeElement<T>* node) {

    if(size == 0){
        root = node;
        size++;
        return;
    }

    while(true){

        if(node->getValue() > node->getParent()->getValue()) {

            if(node->getParent()->getRight() == &guardian){

                node->getParent()->setElement('r', node);
                break;
            }
            node->setElement('p', node->getParent()->getRight());
        }
        else {
            if(node->getParent()->getLeft() == &guardian){

                node->getParent()->setElement('l', node);
                break;
            }
            node->setElement('p', node->getParent()->getLeft());
        }
    }
    size++;
}

template<typename T>
TreeElement<T>* RBTree<T>::findMIN(TreeElement<T>* node){

    auto tempElement = node;

    while(tempElement->getLeft() != &guardian)
        tempElement = tempElement->getLeft();


    return tempElement;
}

template<typename T>
TreeElement<T>* RBTree<T>::findMAX(TreeElement<T> * node) {

    auto tempElement = node;

    while(tempElement->getRight() != &guardian)
        tempElement = tempElement->getRight();

    return tempElement;
}

template<typename T>
TreeElement<T>* RBTree<T>::treeSuccessor(TreeElement<T> * node) {

    if (node->getRight() != &guardian)
        return findMIN(node->getRight());

    auto tempParent = node->getParent();

    while(tempParent != &guardian && node == tempParent->getRight()){
        node = tempParent;
        tempParent = tempParent->getParent();
    }
    return tempParent;
}

template<typename T>
void RBTree<T>::deleteFix(TreeElement<T> * node) {

    while(node != this->root && node->color == TreeElement<T>::Color::BLACK){

        if(node == node->getParent()->getLeft()){

            auto tempBrother = node->getParent()->getRight();

            if(tempBrother->color == TreeElement<T>::Color::RED){

                tempBrother->color = TreeElement<T>::Color::BLACK;
                node->getParent()->color = TreeElement<T>::Color::RED;

                this->rotateLeft(node->getParent());

                tempBrother = node->getParent()->getRight();
            }

            if(tempBrother->getLeft()->color == TreeElement<T>::Color::BLACK
                && tempBrother->getRight()->color == TreeElement<T>::Color::BLACK){

                tempBrother->color = TreeElement<T>::Color::RED;

                node = node->getParent();
            }
            else{

                if(tempBrother->getRight()->color == TreeElement<T>::Color::BLACK){
                    tempBrother->getLeft()->color = TreeElement<T>::Color::BLACK;
                    tempBrother->color = TreeElement<T>::Color::RED;

                    this->rotateRight(tempBrother);

                    tempBrother = node->getRight();
                }

                tempBrother->color = node->getParent()->color;
                node->getParent()->color = TreeElement<T>::Color::BLACK;
                tempBrother->getRight()->color = TreeElement<T>::Color::BLACK;

                this->rotateLeft(node->getParent());

                node = this->root;
            }
        }
        else{
            auto tempBrother = node->getParent()->getLeft();

            if(tempBrother->color == TreeElement<T>::Color::RED){

                tempBrother->color = TreeElement<T>::Color::BLACK;
                node->getParent()->color = TreeElement<T>::Color::RED;

                this->rotateRight(node->getParent());

                tempBrother = node->getParent()->getLeft();
            }

            if(tempBrother->getRight()->color == TreeElement<T>::Color::BLACK
               && tempBrother->getLeft()->color == TreeElement<T>::Color::BLACK){

                tempBrother->color = TreeElement<T>::Color::RED;

                node = node->getParent();
            }
            else{

                if(tempBrother->getLeft()->color == TreeElement<T>::Color::BLACK){
                    tempBrother->getRight()->color = TreeElement<T>::Color::BLACK;
                    tempBrother->color = TreeElement<T>::Color::RED;

                    this->rotateLeft(tempBrother);

                    tempBrother = node->getLeft();
                }

                tempBrother->color = node->getParent()->color;
                node->getParent()->color = TreeElement<T>::Color::BLACK;
                tempBrother->getLeft()->color = TreeElement<T>::Color::BLACK;

                this->rotateRight(node->getParent());

                node = this->root;
            }
        }
    }

    node->color = TreeElement<T>::Color::BLACK;
}

template<typename T>
RBTree<T>::RBTree() {

    this->fileManager = new FileManager("RBTree");
    this->timer = new Timer;

    guardian.setGuardian();

    root = &guardian;

    size = 0;
}

template<typename T>
void RBTree<T>::rotateLeft(TreeElement<T>* node) {

    auto tempRightSon = node->getRight();
    TreeElement<T>* tempParent;

    if(tempRightSon != &guardian){

        tempParent = node->getParent();
        node->setElement('r', tempRightSon->getLeft());

        if(node->getRight() != &guardian)
            node->getRight()->setElement('p', node);

        tempRightSon->setElement('l', node);
        tempRightSon->setElement('p', tempParent);
        node->setElement('p', tempRightSon);

        if(tempParent != &guardian){
            if(tempParent->getLeft() == node)
                tempParent->setElement('l', tempRightSon);
            else
                tempParent->setElement('r', tempRightSon);
        }
        else
            root = tempRightSon;
    }
}

template<typename T>
void RBTree<T>::rotateRight(TreeElement<T> * node) {

    auto tempLeftSon = node->getLeft();
    TreeElement<T>* tempParent;

    if(tempLeftSon != &guardian){

        tempParent = node->getParent();
        node->setElement('l', tempLeftSon->getRight());

        if(node->getLeft() != &guardian)
            node->getLeft()->setElement('p', node);

        tempLeftSon->setElement('r', node);
        tempLeftSon->setElement('p', tempParent);
        node->setElement('p', tempLeftSon);

        if(tempParent != &guardian){
            if(tempParent->getLeft() == node)
                tempParent->setElement('l', tempLeftSon);
            else
                tempParent->setElement('r', tempLeftSon);
        }
        else
            root = tempLeftSon;
    }
}

template<typename T>
void RBTree<T>::addFront(T value) {
    add(value, -1);
}

template<typename T>
void RBTree<T>::add(T value, int position) {

    auto newNode = new TreeElement<T>(value, TreeElement<T>::Color::RED, &guardian, &guardian, this->root);

    bstInsert(newNode);

    while(newNode != this->root
          and newNode->getParent()->color == TreeElement<T>::Color::RED){

        if(newNode->getParent() == newNode->getParent()->getParent()->getLeft()){

            TreeElement<T>* uncle = newNode->getParent()->getParent()->getRight();

            if(uncle->color == TreeElement<T>::Color::RED){

                newNode->getParent()->color = TreeElement<T>::Color::BLACK;
                uncle->color = TreeElement<T>::Color::BLACK;
                newNode->getParent()->getParent()->color = TreeElement<T>::Color::RED;
                newNode = newNode->getParent()->getParent();
            }
            else if(newNode == newNode->getParent()->getRight()){

                newNode = newNode->getParent();
                this->rotateLeft(newNode);
            }

            newNode->getParent()->color = TreeElement<T>::Color::BLACK;
            newNode->getParent()->getParent()->color = TreeElement<T>::Color::RED;

            this->rotateRight(newNode->getParent()->getParent());
            break;
        }
        else{

            auto uncle = newNode->getParent()->getParent()->getLeft();

            if(uncle->color == TreeElement<T>::Color::RED){

                newNode->getParent()->color = TreeElement<T>::Color::BLACK;
                uncle->color = TreeElement<T>::Color::BLACK;
                newNode->getParent()->getParent()->color = TreeElement<T>::Color::RED;
                newNode = newNode->getParent()->getParent();
            }
            else if(newNode == newNode->getParent()->getLeft()){

                newNode = newNode->getParent();
                this->rotateRight(newNode);
            }

            newNode->getParent()->color = TreeElement<T>::Color::BLACK;
            newNode->getParent()->getParent()->color = TreeElement<T>::Color::RED;

            this->rotateLeft(newNode->getParent()->getParent());
        }
    }
    this->root->color = TreeElement<T>::Color::BLACK;
}

template<typename T>
void RBTree<T>::addEnd(T value) {
    add(value,0);
}

template<typename T>
void RBTree<T>::deleteFront() {
    erase(root->getValue());
}

template<typename T>
void RBTree<T>::deleteEnd() {
    deleteFront();
}

template<typename T>
void RBTree<T>::erase(T value) {

    TreeElement<T>* firstHelper = nullptr;
    TreeElement<T>* secondHelper = nullptr;
    auto elementToRemove = this->searchElement(value);

    if(elementToRemove->getLeft() == &guardian
        || elementToRemove->getRight() == &guardian)
            firstHelper = elementToRemove;
    else
        firstHelper = this->treeSuccessor(elementToRemove);

    if(firstHelper->getLeft() != &guardian)
        secondHelper = firstHelper->getLeft();
    else
        secondHelper = firstHelper->getRight();

    secondHelper->setElement('p', firstHelper->getParent());

    if(firstHelper->getParent() == &guardian)
        this->root = secondHelper;

    else{
        if(firstHelper == firstHelper->getParent()->getLeft())
            firstHelper->getParent()->setElement('l', secondHelper);
        else
            firstHelper->getParent()->setElement('r', secondHelper);
    }

    if(firstHelper != elementToRemove)
        elementToRemove->setValue(firstHelper->getValue());

    if(firstHelper->color == TreeElement<T>::Color::BLACK)
        this->deleteFix(secondHelper);

    size--;
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

template<typename T>
void RBTree<T>::printTree() {

    auto temp = root;

    while(temp not_eq &guardian){
        std::cout << temp->getValue() << "\n";
        temp = temp->getRight();
    }
}