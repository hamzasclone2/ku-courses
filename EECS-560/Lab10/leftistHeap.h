#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

class leftistHeap{

    public:

    struct Node{
        int key;
        int rank;
        Node* left;
        Node* right;
    };

    leftistHeap();
    ~leftistHeap();
    void buildHeap();
    void insert(int val);
    void deleteMin();
    int findMin();
    Node* concate(Node* h1, Node* h2);
    Node* concateHelper(Node* h1, Node* h2);
    void preOrder(Node* node);
    void inOrder(Node* node);
    int height(Node* node);
    void printLevel(Node* node, int level);
    void levelOrder();
    void print(std::string order);

    private:

    Node* root;
};
#endif
