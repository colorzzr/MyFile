/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on June 23, 2017, 12:43 AM
 */

#include <cstdlib>
#include <iostream>


using namespace std;
/************************************************
 * Heapsort algorithm                           *
 * the speed of heapsort is nlogn               *
 * we build the heap first it need logn time    *
 * and sort it which is n time                  *
 * friendly reminder here:                      *
 * the array is starting at 0 ending n - 1      *
 * but heap start with 1 ending with n          *
 ************************************************/
typedef struct Arr{
    int *array;
    int size;
    int heapsize;
}arr;
//create random array
void generateRandom (arr* array){
    for(int i = 0; i < array->size; i++){
        array->array[i] = rand() % 28;
        cout << array->array[i] << " ";
    }
    cout << endl << "--------Generating array----------" << endl;
}
void printArr(arr* A){
    for (int i = 0; i < A->size; i++){
        cout << A->array[i] << " ";
    }
    cout << endl;
}

//function to determine the index of left/right children and parent
int parentNode(int i) {
    return i/2;
}
//conner case for 0
int leftNode(int i) {
    if (i == 0) return 1;
    else return 2*i;
}
int rightNode(int i){
    if (i == 0) return 2;
    else return 2*i + 1;
} 

/**************************** 
 * make max heapify         *
 * parent must >= children  *
 * upper >= lower           *
 ****************************/
void maxHeapify (arr* A, int i){
    int left = leftNode(i);
    int right = rightNode(i);
    int largest = i;
    
    //check the left side
    if (i <= (A->heapsize) && left < A->heapsize){
        if(A->array[left] > A->array[i]){
            largest = left;   
        }
        else largest = i;
    }
    //check the right side
    if (i <= A->heapsize && right < A->heapsize){
        if (A->array[largest] < A->array[right]){
            largest = right;   
        }
    }
    
    //make sure the largest is parent
    if (largest != i){
        int temp = A->array[i];
        A->array[i] = A->array[largest];
        A->array[largest] = temp;
        //get down
        maxHeapify(A, largest);
    }
}

//function is to build the heap tree not sort
void buildHeap (arr* A){
    cout << "----------Building the heap-----------" << endl;
    A->heapsize = A->size;
    for (int i = (A->size) / 2; i > 0; i--){
        //but the array start from 1 to n -1;
        maxHeapify(A, i - 1);
    }
    cout << "----------End building-----------" << endl;
}

//below is the function for max priority queus
//get the max node
int maximum (arr* arr){
    return arr->array[0];
}

//get and remove the largest
int heapExtractMax (arr* arr){
    //conner case: zero node
    if(arr->heapsize < 1) {
        cout << "heap underfollow" << endl;
        return 0;
    }
    else{
        cout << "----------Extracting largest---------" << endl;
        //the roof is the largest
        int max = arr->array[0];
        arr->array[0] = arr->array[arr->heapsize - 1];
        arr->heapsize = arr->heapsize - 1;
        arr->size = arr->size - 1;
        //shrink the size
        realloc(arr->array, sizeof(int) * arr->heapsize);
        printArr(arr);
        //maxHeapify(arr, 0);
        return max;
    }
}

//move up the increase node
int heapIncreaseKey(arr* A,int index, int key){
    if (key < A->array[index]) {
        cout << "new key is smaller than current" << endl;
        return 0;
    }
    else{
        cout << "-----------Start increase value--------" << endl;
        A->array[index] = key;
        //move the node to proper layer
        while(index >= 1 && A->array[parentNode(index)] < A->array[index]){
            int temp = A->array[index];
            A->array[index] = A->array[parentNode(index)];
            A->array[parentNode(index)] = temp;
            index = parentNode(index);
        }
        return 1;
    }
}

//insertion = increase a -inf value to key 
int maxHeapInsert (arr* A, int key){
    cout << "---------Start insert node-----------" << endl;
    A->heapsize = A->heapsize + 1;
    
    //realloc for new size
    realloc(A->array ,sizeof(int) * A->heapsize);
    
    A->array[A->heapsize - 1] = -32767/2;
    cout << A->array[A->heapsize - 1] << endl;
    heapIncreaseKey(A, A->heapsize - 1, key);
    A->size = A->size + 1;
    return 1;
}

int main(int argc, char** argv) {
    arr* A = new arr;
    //for initializing
    A->size = 16;
    A->array = (int*)malloc(sizeof(int) * A->size);
    
    
    generateRandom(A);
    buildHeap(A);
    printArr(A);
    
    heapExtractMax(A);
    //heapIncreaseKey(A, 9, 22);
    printArr(A);
    //maxHeapInsert(A, 13);
    //printArr(A);
    
    for (int i = A->size; i > 0; i--){
        //let largest go to bottom
        //same here the array start from 1 to n - 1
        int temp = A->array[i - 1];
        A->array[i - 1] = A->array[0];
        A->array[0] = temp;
        
        //like bubble sort potientially remove the correct one
        A->heapsize = A->heapsize - 1;
        maxHeapify(A, 0);
    }
   
    printArr(A);
            
    return 0;
}

