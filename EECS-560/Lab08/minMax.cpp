#include <iostream>
#include <fstream>
#include <math.h>
#include "minMax.h"

//constructor
minMax::minMax(){
    size = 500;
    lastIdx = 1;
    heap = new int[size];
    for(int i = 0; i < size; i++){
        heap[i] = -1;
    }
}

//destructor
minMax::~minMax(){
    delete [] heap;
}

//takes in values from data file to populate array
void minMax::buildHeap(){
    int data;
    std::ifstream file;
    file.open("data.txt");
    while(file >> data){
        insert(data);
    }
}

//inserts value at last+1
void minMax::insert(int val){
    if(heap[1] == -1){
        heap[1] = val;
    }else{
        heap[lastIdx+1] = val;
        lastIdx++;

        bool finished = false;
        int parentIdx = floor(lastIdx / 2);
        int index = lastIdx;
        int temp;

        if(heap[index] < heap[parentIdx]){
            while(!finished && index != 1){
                if((int)floor(log2(parentIdx)) % 2 == 0){ //even, parent is a min node
                    temp = heap[parentIdx];
                    heap[parentIdx] = heap[index];
                    heap[index] = temp;
                    index = parentIdx;
                    finished = true;
                }else{ //odd, parent is a max node
                    int gpIdx = floor(index / 4);
                    if(heap[index] < heap[gpIdx]){
                        temp = heap[gpIdx];
                        heap[gpIdx] = heap[index];
                        heap[index] = temp;
                        index = gpIdx;
                        finished = true;
                    }else{
                        finished = true;
                    }
                }
            }
        }else if(heap[index] > heap[parentIdx]){
            while(!finished && index != 1){
                if((int)floor(log2(parentIdx)) % 2 == 0){ //parent is a min node
                    if(parentIdx == 1){
                        finished = true;
                    }else{
                        int gpIdx = floor(index / 4);
                        if(heap[index] > heap[gpIdx]){
                            int temp = heap[gpIdx];
                            heap[gpIdx] = heap[index];
                            heap[index] = temp;
                            index = gpIdx;
                            finished = true;
                        }else{
                            finished = true;
                        }
                    }
                }else{ //parent is a max node
                    int temp = heap[parentIdx];
                    heap[parentIdx] = heap[index];
                    heap[index] = temp;
                    index = parentIdx;
                    finished = true;
                }
            }
        }
    }
}

//deletes root, replaces with last
void minMax::deleteMin(){
    heap[1] = heap[lastIdx];
    heap[lastIdx] = -1;
    lastIdx--;
}

//returns root
int minMax::findMin(){
    return heap[1];
}

//returns one of the roots children
int minMax::findMax(){
    if(heap[2] == -1){
        return heap[1];
    }else if(heap[3] == -1){
        return heap[2];
    }else if(heap[3] > heap[2]){
        return heap[3];
    }else{
        return heap[2];
    }
}

//deletes max, replaces with last
void minMax::deleteMax(){
    if(heap[2] == -1){
        heap[1] = -1;
    }else if(heap[3] == -1){
        heap[2] = -1;
        lastIdx--;
    }else{
        int maxIdx;
        if(heap[3] > heap[2]){
            maxIdx = 3;;
        }else{
            maxIdx = 2;
        }
        heap[maxIdx] = heap[lastIdx];
        heap[lastIdx] = -1;
        lastIdx--;
    }
}

//prints out array in order
void minMax::levelOrder(){
    std::cout << "\n";
    for(int i = 1; i <= lastIdx; i++){
        std::cout << heap[i] << " ";
    }
    std::cout << "\n";
}
