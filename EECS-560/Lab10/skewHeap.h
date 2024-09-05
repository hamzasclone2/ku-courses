#ifndef SKEWHEAP_H
#define SKEWHEAP_H

class skewHeap{

    public:

    struct Node{
        int key;
        Node* left;
        Node* right;
    };

    skewHeap();
    ~skewHeap();
    void buildHeap();
    void insert(int val);
    void deleteMin();
    int findMin();
    Node* concate(Node* h1, Node* h2);
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
