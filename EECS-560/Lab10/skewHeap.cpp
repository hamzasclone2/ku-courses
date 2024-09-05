#include <iostream>
#include <fstream>
#include "skewHeap.h"

skewHeap::skewHeap(){
    root = nullptr;
}

skewHeap::~skewHeap(){
    while(root != nullptr){
        deleteMin();
    }
}

void skewHeap::buildHeap(){
    std::ifstream file;
    file.open("data.txt");
    int data;
    while(file >> data){
        insert(data);
    }
}

void skewHeap::insert(int val){
    Node* temp = new Node();
    temp -> key = val;
    temp -> left = nullptr;
    temp -> right = nullptr;
    root = concate(root, temp);
}

void skewHeap::deleteMin(){
    if(root != nullptr){
        Node* temp = root;
        root = concate(root -> left, root -> right);
        delete temp;
    }else{
        std::cout << "The tree is empty!\n";
    }
}

int skewHeap::findMin(){
    if(root != nullptr){
        return root -> key;
    }
}

skewHeap::Node* skewHeap::concate(Node* h1, Node* h2){
    Node* temp;
    if(h1 == nullptr){
        return h2;
    }else if(h2 == nullptr){
        return h1;
    }else{
        if(h1 -> key > h2 -> key){
            temp = h1;
            h1 = h2;
            h2 = temp;
        }
        temp = h1 -> left;
        h1 -> left = h1 -> right;
        h1 -> right = temp;
        h1 -> left = concate(h2, h1 -> left);
    }
    return h1;
}

void skewHeap::preOrder(Node* node){
    if(node != nullptr){
        std::cout << node -> key << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void skewHeap::inOrder(Node* node){
    if(node != nullptr){
        inOrder(node -> left);
        std::cout << node -> key << " ";
        inOrder(node -> right);
    }
}

int skewHeap::height(Node* node){
    if(node == nullptr){
        return 0;
    }else{
        int leftHeight = height(node -> left);
        int rightHeight = height(node -> right);
        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }else{
            return rightHeight + 1;
        }
    }
}

void skewHeap::printLevel(Node* node, int level){
    if(node != nullptr){
        if(level == 1){
            std::cout << node -> key << " ";
        }else if(level > 1){
            printLevel(node -> left, level - 1);
            printLevel(node -> right, level - 1);
        }
    }
}

void skewHeap::levelOrder(){
    int h = height(root);
    for(int i = 0; i <= h; i++){
        printLevel(root, i);
        std::cout << "\n";
    }
}

void skewHeap::print(std::string order){
    if(order == "pre"){
        preOrder(root);
    }else if(order == "in"){
        inOrder(root);
    }else if(order == "level"){
        levelOrder();
    }
}
