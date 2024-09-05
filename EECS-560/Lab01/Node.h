#ifndef NODE_H
#define NODE_H
class Node{
    public:

    //constructor
    Node();

    //sets value inside node
    void setVal(int val);

    //gets value of node
    int getVal();

    //sets next pointer
    void setNext(Node* node);

    //gets the node that this node is looking at
    Node* getNext();

    private:

    int value;
    Node* next;
};
#endif
