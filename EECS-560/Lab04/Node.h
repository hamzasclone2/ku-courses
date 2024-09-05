#ifndef NODE_H
#define NODE_H
class Node{
    public:

    //constructor
    Node();

    //sets value inside node
    void setVal(int val);

    //returns value of node
    int getVal();

    //sets the left pointer to a node
    void setLeft(Node* node);

    //returns the node on the left
    Node* getLeft();

    //sets the right pointer to a node
    void setRight(Node* node);

    //returns the node on the right
    Node* getRight();

    private:

    int value;
    Node* left;
    Node* right;
};
#endif
