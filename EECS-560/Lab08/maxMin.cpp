#include <iostream>
#include <fstream>
#include <math.h>
#include "maxMin.h"

//constructor
maxMin::maxMin(){
    size = 500;
    lastIdx = 1;
    heap = new int[size];
    for(int i = 0; i < size; i++){
        heap[i] = -1;
    }
}

//destructor
maxMin::~maxMin(){
    delete [] heap;
}

//takes in data file to populate array
void maxMin::buildHeap(){
    int data;
    std::ifstream file;
    file.open("data.txt");
    while(file >> data){
        insert(data);
    }
}

//inserts value at last+1
void maxMin::insert(int val){
    if(heap[1] == -1){
        heap[1] = val;
    }else{
        heap[lastIdx+1] = val;
        lastIdx++;

        bool finished = false;
        int parentIdx = floor(lastIdx / 2);
        int index = lastIdx;
        int temp;

        if(heap[index] > heap[parentIdx]){
            while(!finished && index != 1){
                if((int)floor(log2(parentIdx)) % 2 == 0){
                    temp = heap[parentIdx];
                    heap[parentIdx] = heap[index];
                    heap[index] = temp;
                    index = parentIdx;
                    finished = true;
                }else{ //odd, parent is a max node
                    int gpIdx = floor(index / 4);
                    if(heap[index] > heap[gpIdx]){
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
        }else if(heap[index] < heap[parentIdx]){
            while(!finished && index != 1){
                if((int)floor(log2(parentIdx)) % 2 == 0){
                    if(parentIdx == 1){
                        finished = true;
                    }else{
                        int gpIdx = floor(index / 4);
                        if(heap[index] < heap[gpIdx]){
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

//deletes min value, replaces with last
void maxMin::deleteMin(){
    if(heap[2] == -1){
        heap[1] = -1;
    }else if(heap[3] == -1){
        heap[2] = -1;
        lastIdx--;
    }else{
        int minIdx;
        if(heap[3] < heap[2]){
            minIdx = 3;
        }else{
            minIdx = 2;
        }
        heap[minIdx] = heap[lastIdx];
        heap[lastIdx] = -1;
        lastIdx--;
    }
}

//returns one of the children of the root
int maxMin::findMin(){
    if(heap[2] == -1){
        return heap[1];
    }else if(heap[3] == -1){
        return heap[2];
    }else if(heap[3] < heap[2]){
        return heap[3];
    }else{
        return heap[2];
    }
}

//returns the root
int maxMin::findMax(){
    return heap[1];
}

//deletes max value, replaces with last
void maxMin::deleteMax(){
    heap[1] = heap[lastIdx];
    heap[lastIdx] = -1;
    lastIdx--;
}

//prints out array in order
void maxMin::levelOrder(){
    std::cout << "\n";
    for(int i = 1; i <= lastIdx; i++){
        std::cout << heap[i] << " ";
    }
    std::cout << "\n";
}
