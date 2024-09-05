#include <iostream>
#include <fstream>
#include <math.h>
#include "max5heap.h"

max5heap::max5heap(){
    size = 10000000;
    lastIdx = 0;
    heap = new int[size];
    for(int i = 0; i < size; i++){
        heap[i] = -1;
    }
}

//destructor
max5heap::~max5heap(){
    delete [] heap;
}

//builds heap from data file using bottom-up approach
void max5heap::buildHeap(int arraySize, int* array){
    /*int data;
    std::ifstream file;
    file.open("data.txt");
    while(file >> data){
        heap[lastIdx] = data;
        lastIdx++;
    }
    lastIdx--;*/
    int i = 0;
    while(i < arraySize){
        heap[lastIdx] = array[i];
        i++;
        lastIdx++;
    }
    int startIdx = floor((lastIdx - 1) / 5);
    for(int i = startIdx; i >= 0; i--){
        heapify(i);
    }
}

//checks to see if value in index needs to be swapped and swaps
void max5heap::heapify(int index){
    int swapped = false;
    int temp;
    int max;
    int maxIdx;
    int end = floor((lastIdx - 1) / 5);
    do{
        if(index <= end){
            max = heap[index];
            for(int j = 1; j <= 5; j++){
                temp = heap[5*index+j];
                if(temp > max && temp != -1){
                    max = temp;
                    maxIdx = 5*index+j;
                }
            }
            if(max != heap[index]){
                temp = heap[maxIdx];
                heap[maxIdx] = heap[index];
                heap[index] = temp;
                swapped = true;
                index = maxIdx;
            }else{
                swapped = false;
            }
        }else{
            swapped = false;
        }
    }while(swapped);
}
//inserts value at end of array then swaps if necessary
void max5heap::insert(int val){
    int temp;
    bool isRoot = false;
    heap[lastIdx+1] = val;
    lastIdx++;
    int index = lastIdx;
    int parent = floor((lastIdx-1)/5);
    while(!isRoot){
        if(heap[index] > heap[parent]){
            temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
            parent = floor((index-1)/5);
        }else{
            isRoot = true;
        }
    }
}

//replaces min with last
void max5heap::deleteMin(){
    heap[findMin()] = heap[lastIdx];
    heap[lastIdx] = -1;
    lastIdx--;
}

//finds min index from all the leaves
int max5heap::findMin(){
    int startIdx = floor((lastIdx - 1) / 5) + 1;
    int min = heap[startIdx];
    int minIdx = startIdx;
    for(int i = startIdx; i <= lastIdx; i++){
        if(heap[i] < min){
            min = heap[i];
            minIdx = i;
        }
    }
    return minIdx;
}

//returns root
int max5heap::findMax(){
    return heap[0];
}

//replaces root with last then swaps if necessary
void max5heap::deleteMax(){
    heap[0] = heap[lastIdx];
    lastIdx--;
    heapify(0);
}

//prints out array
void max5heap::levelOrder(){
    std::cout << "\n";
    for(int i = 0; i < lastIdx + 1; i++){
        if(i == 0 || i == 5 || i == 25 || i == 125){ //powers of 5 > 500
            std::cout << heap[i] << "\n";
        }else if(i%5 == 0 && i != lastIdx){
            std::cout << heap[i] << "-";
        }else{
            std::cout << heap[i] << " ";
        }
    }
    std::cout << "\n";
}
