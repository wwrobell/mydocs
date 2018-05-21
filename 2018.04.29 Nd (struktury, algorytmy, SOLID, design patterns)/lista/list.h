#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>

class List {
protected:
    struct Node {
        int value; //sprobowac zastosowac szablon
        Node *pNext;
    };

    Node *pHead;
public:
    List();
    List(int const arr[], int size);
    ~List();
    void insert(int value);
	void print();
    void reverse();
    std::string toString();
    bool contains(int elem);
    // ...
};

#endif // LIST_H
