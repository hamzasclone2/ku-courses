#include <iostream>
#include <fstream>
#include "leftistHeap.h"

leftistHeap::leftistHeap(){
    root = nullptr;
}

leftistHeap::~leftistHeap(){
    while(root != nullptr){
        deleteMin();
    }
}

void leftistHeap::buildHeap(){
    std::ifstream file;
    file.open("data.txt");
    int data;
    while(file >> data){
        insert(data);
    }
}

void leftistHeap::insert(int val){
    Node* temp = new Node();
    temp -> key = val;
    temp -> rank = 0;
    temp -> left = nullptr;
    temp -> right = nullptr;
    root = concate(temp, root);
}

void leftistHeap::deleteMin(){
    if(root != nullptr){
        Node* temp = root;
        root = concate(root -> left, root -> right);
        delete temp;
    }else{
        std::cout << "The tree is empty!\n";
    }
}

int leftistHeap::findMin(){
    if(root != nullptr){
        return root -> key;
    }
}

leftistHeap::Node* leftistHeap::concate(Node* h1, Node* h2){
    if(h1 == nullptr){
        return h2;
    }else if(h2 == nullptr){
        return h1;
    }else{
        if(h1 -> key < h2 -> key){
            return concateHelper(h1, h2);
        }else{
            return concateHelper(h2, h1);
        }
    }
}

leftistHeap::Node* leftistHeap::concateHelper(Node* h1, Node* h2){
    if(h1 -> left == nullptr){
        h1 -> left = h2;
    }else{
        h1 -> right = concate(h1 -> right, h2);
        if(h1 -> left -> rank < h1 -> right -> rank){
            Node* temp = h1 -> left;
            h1 -> left = h1 -> right;
            h1 -> right =  temp;
        }
        h1 -> rank = h1 -> right -> rank + 1;
    }
    return h1;
}

void leftistHeap::preOrder(Node* node){
    if(node != nullptr){
        std::cout << node -> key << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void leftistHeap::inOrder(Node* node){
    if(node != nullptr){
        inOrder(node -> left);
        std::cout << node -> key << " ";
        inOrder(node -> right);
    }
}

int leftistHeap::height(Node* node){
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

void leftistHeap::printLevel(Node* node, int level){
    if(node != nullptr){
        if(level == 1){
            std::cout << node -> key << " ";
        }else if(level > 1){
            printLevel(node -> left, level - 1);
            printLevel(node -> right, level - 1);
        }
    }
}

void leftistHeap::levelOrder(){
    int h = height(root);
    for(int i = 0; i <= h; i++){
        printLevel(root, i);
        std::cout << "\n";
    }
}

void leftistHeap::print(std::string order){
    if(order == "pre"){
        preOrder(root);
    }else if(order == "in"){
        inOrder(root);
    }else if(order == "level"){
        levelOrder();
    }
}
