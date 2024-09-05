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
void Sorts<T>::mergeSort(T arr[], int size){

}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size){

}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size){

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
    int randomNumber;
    int temp;
    for(int i=0; i<size-1; i++){
        randomNumber=distribution(generator);
        temp=arr[i];
        arr[i]=arr[randomNumber];
        arr[randomNumber]=temp;
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

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2){
    T* newArr=new T[size1+size2];
    int i=0;
    int j=0;
    int k=0;
    while(i<size1 && j<size2){
        if(a1[i]<=a2[j]){
            newArr[k]=a1[i];
            i++;
        }
        else{
            newArr[k]=a2[j];
            j++;
        }
        k++;
    }
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){

}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last){

}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median){
    return(0);
}
