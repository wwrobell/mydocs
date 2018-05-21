#include <iostream>
#include "list.h"

List::List(){
    pHead = nullptr;
    std::cout << "List object created" << std::endl;

}

List::List(int const arr[], int size){
	pHead = nullptr;
	for (int i = 0; i < size; ++i) {
		insert(arr[i]);
	}
	std::cout << "List object created" << std::endl;
}

List::~List(){
    std::cout << "List object deleted" << std::endl;
}

void List::insert(int value){
	Node* node = new Node;
	node->value = value;
	node->pNext = pHead;
	pHead = node;
}

void List::print() {
	Node* it = pHead;
	while (it->pNext != nullptr) {
		std::cout << it->value <<", ";
		it = it->pNext;
	}
	std::cout << it->value <<std::endl;
}

void List::reverse() {
	Node* it = pHead;
	Node* pre = nullptr;
	Node* next;

	while (true) {
		next = it->pNext;
		it->pNext = pre;
		pre = it;
		it = next;
		if (next == nullptr) {
			pHead = pre;
			break;
		}
		//else
		//	it = next;
	}
}

bool List::contains(int i) {
	Node* it = pHead;

	while (true) {
		if (it->value == i)
			return true;
		if (it->pNext == nullptr) //the end of list
			return false;
		else
			it = it->pNext;
	}
}

std::string List::toString() {
	std::string str;
	Node* it = pHead;

	while (true) {
		int value = it->value;
		str += std::to_string(value);
		if (it->pNext == nullptr) //the end of list
			break;
		it = it->pNext;
	}
	return str;
}

