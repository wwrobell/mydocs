#include "bst.h"
#include <iostream>

BinSearchTree::BinSearchTree() {
	pRoot = nullptr;
	std::cout << "BST constructed!\n"; 
}

BinSearchTree::BinSearchTree(int const arr[], int size) {
	pRoot = nullptr;
	std::cout << "BST constructed!\n";
	for (int i = 0; i < size; ++i)
		insert(arr[i]);
}

BinSearchTree::~BinSearchTree() { std::cout << "BST destructed!\n"; }

void BinSearchTree::insert(int value) {
	BSTNode* pNewNode = new BSTNode;

	//initialize new node:
	pNewNode->value = value;
	pNewNode->pLeft	= nullptr;
	pNewNode->pRight = nullptr;

	if (pRoot == nullptr) {//uninitialized tree
		pRoot = pNewNode;
	}
	else {//initialized tree
		BSTNode* iterator = pRoot;

		while (true) {
			if (value < (iterator->value))
				if ((iterator->pLeft) == nullptr) { //free left BSTNode
					iterator->pLeft = pNewNode;
					break;
				}
				else
					iterator = iterator->pLeft;
			else //value >= parrent value -> go right
				if ((iterator->pRight) == nullptr) {
					iterator->pRight = pNewNode;
					break;
				}
				else
					iterator = iterator->pRight;
		}
	}
}

std::string BinSearchTree::getChildren(BSTNode* parent) {
	BSTNode* childL = parent->pLeft;
	BSTNode* childR = parent->pRight;
	std::string childrenAsString;

	if (childL != nullptr) {
		int lVal = childL->value;
		childrenAsString += std::to_string(lVal);
		childrenAsString += getChildren(childL);
	}

	if (childR != nullptr) {
		int rVal = childR->value;
		childrenAsString += std::to_string(rVal);
		childrenAsString += getChildren(childR);
	}
	return childrenAsString;
}

std::string BinSearchTree::toString() {
	int rootVal = pRoot->value;
	return std::to_string(rootVal) + getChildren(pRoot);
}

bool BinSearchTree::contains(int number) {
	BSTNode* it = pRoot;

	while (true) {
		if (it == nullptr)
			return false;
		if (number == (it->value))
			return true;
		else if (number > (it->value))
			it = it->pRight; //look right
		else
			it = it->pLeft; //look left
	}
	return false;
}

bool BinSearchTree::containsRec(int number, BSTNode* parent) {
	if (parent == nullptr)
		return false;
	if (number == (parent->value))
		return true;
	if (number < (parent->value))
		return containsRec(number, (parent->pLeft));
	else
		return containsRec(number, (parent->pRight));

}

void BinSearchTree::swapChildren(BSTNode* parent) {
	BSTNode* it = parent;
	BSTNode* lChild = it->pLeft;
	BSTNode* rChild = it->pRight;

	//swap L <-> R
	it->pLeft = rChild;
	it->pRight = lChild;

	if (lChild != nullptr)
		swapChildren(lChild);

	if (rChild != nullptr)
		swapChildren(rChild);

}

void BinSearchTree::mirror() {
	swapChildren(pRoot);
}