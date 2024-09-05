#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List{
    public:

    //constructor
    List();
    //destructor
    ~List();

    //takes in value to be inserted into the list
    //calls recurseInsert to navigate to end of list recursively
    void insert(int val);

    //checks if list has any nodes in it
    //returns true if it is empty, otherwise false
    bool isEmpty();

    //erases the node that holds the value from the list
    //calls recurseErase to recursively navigate to node before the
    //to be deleted node
    void erase(int val);

    //prints the list iteratively
    void print();

    //checks if the value exists in the list
    //returns nullptr if it is not, otherwise returns the node
    Node* find(int val);

    //takes in value to be inserted into the list
    //calls recurseInsert to navigate to end of list recursively
    Node* recurseInsert(Node* node);

    //recursively navigates to node before the val
    Node* recurseErase(Node* node, int val);

    private:

    //start of the list
    Node* head;
};
#endif
