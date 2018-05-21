#include <iostream>
#include "bst.h"

using namespace std;

int main(int argc, char *argv[])
{
	int arr[] = {4,6,3,1,5,7,8};
	BinSearchTree myTree(arr,7);
	//myTree.mirror();
	//myTree.insert(4);
	//myTree.insert(6);
	//myTree.insert(8);
	//myTree.insert(2);

	//std::string treeAsString = myTree.toString();
	//std::cout << treeAsString <<std::endl;

	//bool isContained = myTree.contains(0);

	std::cout << "end";
    return 0;
}
