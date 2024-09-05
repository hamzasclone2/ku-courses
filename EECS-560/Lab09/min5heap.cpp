#include <iostream>
#include <fstream>
#include <math.h>
#include "min5heap.h"

//constructor
min5heap::min5heap(){
    size = 10000000;;
    lastIdx = 0;
    heap = new int[size];
    for(int i = 0; i < size; i++){
        heap[i] = -1;
    }
}

//destructor
min5heap::~min5heap(){
    delete [] heap;
}

//builds heap from data file using bottom-up approach
void min5heap::buildHeap(int arraySize, int* array){
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
void min5heap::heapify(int index){
    int swapped = false;
    int temp;
    int min;
    int minIdx;
    int end = floor((lastIdx - 1) / 5);
    do{
        if(index <= end){
            min = heap[index];
            for(int j = 1; j <= 5; j++){
                temp = heap[5*index+j];
                if(temp < min && temp != -1){
                    min = temp;
                    minIdx = 5*index+j;
                }
            }
            if(min != heap[index]){
                temp = heap[minIdx];
                heap[minIdx] = heap[index];
                heap[index] = temp;
                swapped = true;
                index = minIdx;
            }else{
                swapped = false;
            }
        }else{
            swapped = false;
        }
    }while(swapped);
}
//inserts value at end of array then swaps if necessary
void min5heap::insert(int val){
    int temp;
    bool isRoot = false;
    heap[lastIdx+1] = val;
    lastIdx++;
    int index = lastIdx;
    int parent = floor((lastIdx-1)/5);
    while(!isRoot){
        if(heap[index] < heap[parent]){
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

//replaces root with last, then swaps if necessary
void min5heap::deleteMin(){
    heap[0] = heap[lastIdx];
    lastIdx--;
    heapify(0);
}

//returns root
int min5heap::findMin(){
    return heap[0];
}

//finds max from all the leaves
int min5heap::findMax(){
    int startIdx = floor((lastIdx - 1) / 5) + 1;
    int max = heap[startIdx];
    int maxIdx = startIdx;
    for(int i = startIdx; i <= lastIdx; i++){
        if(heap[i] > max){
            max = heap[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

//replaces max with last then swaps if necessary
void min5heap::deleteMax(){
    heap[findMax()] = heap[lastIdx];
    heap[lastIdx] = -1;
    lastIdx--;
}

//prints out array
void min5heap::levelOrder(){
    std::cout << "\n";
    for(int i = 0; i < lastIdx + 1; i++){
        if(i == 0 || i == 5 || i == 25 || i == 125){
            std::cout << heap[i] << "\n";
        }else if(i%5 == 0 && i != lastIdx){
            std::cout << heap[i] << "-";
        }else{
            std::cout << heap[i] << " ";
        }
    }
    std::cout << "\n";
}
