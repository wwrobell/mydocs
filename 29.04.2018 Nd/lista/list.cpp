#include <iostream>
#include "list.h"

//struct Node {
//    int value;
//    Node *pNext;
//};

//Node *pHead;

List::List(){
    pHead = nullptr;
    std::cout << "List object created" << std::endl;

}

List::~List(){
    std::cout << "List object deleted" << std::endl;
}

void List::insert(int value){
    //Node *node = new Node;
    Node node;
    node.value = value;
    node.pNext = nullptr;
    *pHead = node;

    //std::cout<<"test"<<value<<std::endl;
}
