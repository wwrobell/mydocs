#ifndef BST_H
#define BST_H
#include <string>

class BinSearchTree {
	struct BSTNode
	{
		int value;
		BSTNode *pLeft;
		BSTNode *pRight;
	};
	BSTNode *pRoot;
	
public:
	BinSearchTree();
	BinSearchTree(int const arr[], int size);
	~BinSearchTree();
	void insert(int value);
	std::string getChildren(BSTNode* parent);
	std::string toString();
	bool contains(int number);
	bool containsRec(int number, BSTNode* parent);
	//List toList();
	void swapChildren(BSTNode* parent);
	void mirror(); //L <-> R najlepiej rekurencyjnie
	// ...
};

#endif // BST_H
