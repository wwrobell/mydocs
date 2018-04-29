#ifndef BST_H
#define BST_H

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
    void toString();
    bool contains();
    //List toList();
    void mirror(); //L <-> R najlepiej rekurencyjnie
    // ...
};

#endif // BST_H
