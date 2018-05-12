struct BSTNode;

class BinSearchTree {
    BSTNode *m_pRoot {nullptr};
    int m_elemCount {0};
    bool m_isIncr {true};

    BSTNode* insertRecur(int elem, BSTNode *pCurrRoot);
    std::string toStringRecur(BSTNode *pCurrRoot) const;
    BSTNode* mirrorRecur(BSTNode *pCurrRoot) const;
    int depthRecur(BSTNode *pCurrRoot) const;
    bool containsRecur(int elem, BSTNode *pCurrRoot) const;
    BSTNode* newBSTNode(int elem) const;
    void deleteElems(BSTNode *pCurrRoot);

public:
    static BinSearchTree* fromArray(int const arr[], int size);
    //BinSearchTree(int const arr[], int size);
    BinSearchTree() {}
    ~BinSearchTree();
    void insert(int value);
    std::string toString();
    bool contains(int elem) const;
    void mirror();
    int depth() const;
};


void runBinSearchTreeMethods();
