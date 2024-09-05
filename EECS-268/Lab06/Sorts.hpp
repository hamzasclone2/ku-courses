/*
@file: Sorts.hpp
@author: Hamza Hameed
@date: October 21, 2015
@brief: All of the algorithms for the different sorts
        Plus shuffling arrays, timing sorts, and creating arrays
*/
template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
    T temp;
    bool isSort=false;
    while(!isSort){
        isSort=true;
        for(int i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                isSort=false;
            }
        }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size){
    std::default_random_engine generator(time(nullptr));
    while(!isSorted(arr, size)){
        shuffle(arr, size, generator);
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size){
    int j=0;
    int temp=0;
    for(int i=0; i<size; i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size){
    int min=0;
    int temp=0;
    for(int i=0; i<size-1; i++){
        min=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min != i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size){
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator){
    std::uniform_int_distribution<int> distribution(0, size-1);
    int randomIndex;
    int temp;
    for(int i=0; i<size-1; i++){
        randomIndex=distribution(generator);
        temp=arr[i];
        arr[i]=arr[randomIndex];
        arr[randomIndex]=temp;
    }
}

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max){
    int randomNumber;
    int* array=new int[size];
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min,max);
    for(int i=0; i<size; i++){
        randomNumber=distribution(generator);
        array[i]=randomNumber;
    }
    return array;
}

template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size){
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;
    start=std::chrono::system_clock::now();
    sort(arr, size);
    end=std::chrono::system_clock::now();
    elapsed=(end-start);
    return elapsed.count();
}
