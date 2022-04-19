#include "Menu.hpp"

template<typename T>
void Menu<T>::manualTests() {

    int choice = -1;

    while(choice != 5){

        std::cout << listOfStructures;
        std::cin >> choice;

        switch(choice){
            case 1:
                data[0]->menu();
                break;
            case 2:
                data[1]->menu();
                break;
            case 3:
                data[2]->menu();
                break;
            case 4:
                data[3]->menu();
                break;
            case 5:
                exit(0);
            default:
                break;
        }
    }




}

template<typename T>
void Menu<T>::automaticTests() {

    Tests<T>* tests = new Tests<T>;

    std::string listOfTests = "1. Add Front\n2. Add\n3. Add at the End\n4. Delete Front\n";
    listOfTests += "5. Erase\n6. Delete at the End\n7. Search\n8. All Tests\n9. Exit\n";

    int choice = -1;
    int structure = -1;

    while(choice != 9){

        std::cout << listOfTests;
        std::cin >> choice;

        switch(choice){
            case 1: //add Front
                std::cout << "1. Dynamic Array\n2. DoublyLinkedList\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->addFront(data[0]);
                        break;
                    case 2:
                        tests->addFront(data[1]);
                        break;
                }
                break;

            case 2: // add
                std::cout << listOfStructures;
                std::cout << "5. All structures\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->add(data[0]);
                        break;
                    case 2:
                        tests->add(data[1]);
                        break;
                    case 3:
                        tests->add(data[2]);
                        break;
                    case 4:
                        tests->add(data[3]);
                        break;
                    case 5:
                        tests->add(data[0]);
                        tests->add(data[1]);
                        tests->add(data[2]);
                        tests->add(data[3]);
                        break;
                }

            case 3: // add end
                std::cout << "1. Dynamic Array\n2. DoublyLinkedList\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->addEnd(data[0]);
                        break;
                    case 2:
                        tests->addEnd(data[1]);
                        break;
                }
                break;

            case 4: // delete Front
                std::cout << "1. Dynamic Array\n2. DoublyLinkedList\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->deleteFront(data[0]);
                        break;
                    case 2:
                        tests->deleteFront(data[1]);
                        break;
                }
                break;

            case 5: // erase

                std::cout << listOfStructures;
                std::cout << "5. All structures\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->erase(data[0]);
                        break;
                    case 2:
                        tests->erase(data[1]);
                        break;
                    case 3:
                        tests->erase(data[2]);
                        break;
                    case 4:
                        tests->erase(data[3]);
                        break;
                    case 5:
                        tests->erase(data[0]);
                        tests->erase(data[1]);
                        tests->erase(data[2]);
                        tests->erase(data[3]);
                        break;
                }
                break;
            case 6: // deleteEnd

                std::cout << "1. Dynamic Array\n2. DoublyLinkedList\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->deleteEnd(data[0]);
                        break;
                    case 2:
                        tests->deleteEnd(data[1]);
                        break;
                }
                break;

            case 7: //search

                std::cout << listOfStructures;
                std::cout << "5. All structures\n";
                std::cin >> structure;

                switch(structure){
                    case 1:
                        tests->search(data[0]);
                        break;
                    case 2:
                        tests->search(data[1]);
                        break;
                    case 3:
                        tests->search(data[2]);
                        break;
                    case 4:
                        tests->search(data[3]);
                        break;
                    case 5:
                        tests->search(data[0]);
                        tests->search(data[1]);
                        tests->search(data[2]);
                        tests->search(data[3]);
                        break;
                }
                break;
            case 8: // all tests
                tests->allTests(data[0]);
                tests->allTests(data[1]);
                tests->allTests(data[2]);
                tests->allTests(data[3]);
                break;
            case 9: // system exit
                exit(0);
                break;

        }
    }

}

template<typename T>
Menu<T>::Menu() {

    data[0] = new DynamicArray<T>;
    data[1] = new DoublyLinkedList<T>;
    data[2] = new BinaryHeap<T>;
    data[3] = new RBTree<T>;

    listOfStructures = "1. Dynamic Array\n2. Doubly Linked List\n3. Binary Heap\n4. Red Black Tree\n";

}

template<typename T>
Menu<T>::~Menu() {
    delete[] data;
}

template<typename T>
void Menu<T>::mainMenu() {

    std::string whichTests = "Chooose kind of tests.\n1. Manual\n2. Automatic\n";
    int choiceOfTests = 0;

    std::cout << whichTests;
    std::cin >> choiceOfTests;

    switch(choiceOfTests){
        case 1:
            manualTests();
            break;
        case 2:
            automaticTests();
            break;
        default:
            return;
    }
}