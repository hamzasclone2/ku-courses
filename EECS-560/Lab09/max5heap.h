#ifndef MAX5HEAP_H
#define MAX5HEAP_H

class max5heap{
    public:

    max5heap(); //constructor
    ~max5heap(); //destructor
    void buildHeap(int arraySize, int* array); //builds heap from data file using bottom-up approach
    void heapify(int index);
    void insert(int val); //inserts value at end of array then swaps if necessary
    void deleteMin(); //replaces min with last
    int findMin(); //finds max index from all the leaves
    int findMax(); //returns root
    void deleteMax(); //replaces root with last then swaps if necessary
    void levelOrder(); //prints out array

    private:

    int* heap;
    int size;
    int lastIdx;
};
#endif
