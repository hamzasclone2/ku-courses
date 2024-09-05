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
};
#include "Sorts.hpp"
#endif
