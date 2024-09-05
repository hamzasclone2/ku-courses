#ifndef MIN5HEAP_H
#define MIN5HEAP_H

class min5heap{
    public:

    min5heap(); //constructor
    ~min5heap(); //destructor
    void buildHeap(); //builds heap from data file using bottom-up approach
    void heapify(int index);
    void insert(int val); //inserts value at end of array then swaps if necessary
    void deleteMin(); //replaces root with last then swaps if necessary
    int findMin(); //returns root
    int findMax(); //finds max index from all the leaves
    void deleteMax(); //replaces max with last
    void levelOrder(); //prints out array

    private:

    int* heap;
    int size;
    int lastIdx;
};
#endif
