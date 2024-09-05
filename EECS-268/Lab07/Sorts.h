/*
@file: Sorts.h
@author: Hamza Hameed
@date: October 21, 2015
@brief: Header file for Sort class
        Templated even though lab only deals with ints
*/
#ifndef SORTS_H
#define SORTS_H
#include <random>
#include <ctime>
#include <cassert>
#include <functional>
#include <iostream>
#include <chrono>
template <typename T>
class Sorts{

    public:
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Bubble Sort
    @return: none
    */
    static void bubbleSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Bogo Sort
    @return: none
    */
    static void bogoSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Insertion Sort
    @return: none
    */
    static void insertionSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Selection Sort
    @return: none
    */
    static void selectionSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Merge Sort
    @return: none
    */
    static void mergeSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Quick Sort, with last value as pivot
    @return: none
    */
    static void quickSort(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array using Quick Sort, with median as pivot
    */
    static void quickSortWithMedian(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: checks if array is sorted in ascending order
    @return: true if it is, false otherwise
    */
    static bool isSorted(T arr[], int size);
    /*
    @pre: valid templated array and size for the array
    @post: shuffles array randomly
    @return: none
    */
    static void shuffle(T arr[], int size, std::default_random_engine& generator);
    /*
    @pre: valid ints size, min, and max
    @post: creates array of size with range of values between min and max
    @return: int pointer
    */
    static int* createTestArray(int size, int min, int max);
    /*
    @pre: valid templated array and size for the array
    @post: sorts array and checks time it takes
    @return: time it took to sort array
    */
    static double sortTimer(std::function<void(T[],int)>sort, T arr[], int size);

    private:
    /*
    @pre: Valid templated arrays and sizes for arrays
    @post: merges two arrays into one sorted array
    @return: none
    */
    static void merge(T* a1, T*a2, int size1, int size2);
    /*
    @pre: valid templated array, ints, and boolean
    @post: recursively Quick Sorts array
    @return: none
    */
    static void quickSortRec(T arr[], int first, int last, bool median);
    /*
    @pre: valid templated array and ints
    @post: puts median value in the last position
    @return: none
    */
    static void setMedianPivot(T arr[], int first, int last);
    /*
    @pre: valid templated array, ints, and boolean
    @post: partitions array with/without using median value as pivot
    @return: index of pivot
    */
    static int partition(T arr[], int first, int last, bool median);
};
#include "Sorts.hpp"
#endif
