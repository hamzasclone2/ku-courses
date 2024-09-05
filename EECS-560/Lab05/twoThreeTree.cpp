#include "twoThreeTree.h"

//constructor
twoThreeTree::twoThreeTree(){
    root = nullptr;
}

//destructor
twoThreeTree::~twoThreeTree(){
    delete root;
}

//inserts val into tree, rearranging tree if needed
void twoThreeTree::insert(int val){
    Node* newNode = new Node();
    newNode -> key = val;
    newNode -> isLeaf = true;
    newNode -> isTwoNode = false;
    newNode -> minSecond = -1;
    newNode -> minThird = -1;
    newNode -> parent = nullptr;
    newNode -> first = nullptr;
    newNode -> second = nullptr;
    newNode -> third = nullptr;

    if(root == nullptr){ //if tree is empty
        root = newNode;
    }else if(root -> isLeaf){ //if there is only one node
        Node* temp = nullptr;
        temp = root;
        root = new Node();
        if(val < root -> key){
            root -> first = newNode;
            root -> second = temp;
            root -> minSecond = temp -> key;
        }else if(val > root -> key){
            root -> first = temp;
            root -> second = newNode;
        }
        root -> isLeaf = false;
        root -> isTwoNode = true;
        temp -> parent = root;
        temp -> isLeaf = true;
        temp -> isTwoNode = false;
    }else if(root -> isTwoNode){ //if there are two leaves
        twoNodeHelper(val, root, newNode);
        root -> isTwoNode = false;
    }else{
        Node* traverse = root;
        while(traverse != nullptr){
            if(traverse -> isTwoNode){
                twoNodeHelper(val, traverse, newNode);
            }else{
                //not implemented
            }
            traverse = nullptr;
        }
    }
}

//adds a third value into a 2-node
void twoThreeTree::twoNodeHelper(int val, Node* node, Node* newNode){
    if(val < node -> first -> key){
        Node* temp = node -> first;
        Node* temp2 = node -> second;
        node -> second = temp;
        node -> third = temp2;
        node -> minSecond = temp -> key;
        node -> minThird = temp2 -> key;
        node -> first = newNode;
        node -> first -> parent = node;
    }else if(val > node -> first -> key && val < node -> second -> key){
        Node* temp = node -> second;
        node -> third = temp;
        node -> second = newNode;
        node -> second -> parent = node;
        node -> minSecond = newNode -> key;
        node -> minThird = temp -> key;
    }else if(val > node -> second -> key){
        node -> third = newNode;
        node -> minThird = newNode -> key;
        newNode -> parent = node;
    }
}

//finds val in tree and deletes it, rearranging tree if needed
void twoThreeTree::erase(int val){

}

//deletes the absolute min val of entire tree
void twoThreeTree::deleteMin(){
    if(root -> isLeaf){
        root = nullptr;
    }else{
        Node* traverse = root;
        while(traverse != nullptr){
            if(traverse -> isLeaf){
                delete traverse;
                traverse = nullptr;
            }else{
                traverse = traverse -> first;
            }
        }
    }
}

//deletes the absolute max val of entire tree
void twoThreeTree::deleteMax(){
    if(root -> isLeaf){
        root = nullptr;
    }else{
        Node* traverse = root;
        while(traverse != nullptr){
            if(traverse -> isLeaf){
                delete traverse;
                traverse = nullptr;
            }else{
                if(traverse -> third == nullptr){
                    traverse = traverse -> second;
                }else{
                    traverse = traverse -> third;
                }
            }
        }
    }
}

//finds the min value of tree
int twoThreeTree::findMin(){
    Node* traverse = root;
    while(traverse != nullptr){
        if(traverse -> isLeaf){
            return traverse -> key;
        }else{
            traverse = traverse -> first;
        }
    }
    return -1;
}

//find the max value of tree
int twoThreeTree::findMax(){
    Node* traverse = root;
    while(traverse != nullptr){
        if(traverse -> isLeaf){
            return traverse -> key;
        }else{
            if(traverse -> third == nullptr){
                traverse = traverse -> second;
            }else{
                traverse = traverse -> third;
            }
        }
    }
    return -1;
}

//finds the val in the tree, true if found
bool twoThreeTree::find(int val){
    if(root == nullptr){
        return false;
    }else if(root -> isLeaf){
        if(root -> key == val){
            return true;
        }else{
            return false;
        }
    }
    Node* traverse = root;
    while(traverse != nullptr){
        if(traverse -> isLeaf){
            if(val == traverse -> key){
                return true;
            }else{
                return false;
            }
        }else if(val < traverse -> minSecond){
            traverse = traverse -> first;
        }else if(val > traverse -> minSecond && val < traverse -> minThird){
            traverse = traverse -> second;
        }else{
            traverse = traverse -> third;
        }
    }
    return false;
}

//prints out tree using list
void twoThreeTree::levelOrder(){
    if(root == nullptr){
        std::cout << "[empty]";
    }else if(root -> isLeaf){
        std::cout << "[" << root -> key << "]";
    }else if(root -> first != nullptr && root -> third == nullptr){
        std::cout << "[";
        std::cout << root -> first -> key << ", " << root -> second -> key;
        std::cout << "]";
    }else if(root -> third != nullptr){
        std::cout << "[";
        std::cout << root -> first -> key << ", "
                  << root -> second -> key << ", "
                  << root -> third -> key;
        std::cout << "]";
    }
}
