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



//to create a pack for size with array
typedef struct Arr{
    int array[16];
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
        //cout << endl << A->array[i] << " " << A->array[largest] << endl;
        int temp = A->array[i];
        A->array[i] = A->array[largest];
        A->array[largest] = temp;
        //cout << endl << A->array[i] << " " << A->array[largest] << endl;
        
        printArr(A);
        //get down
        maxHeapify(A, largest);
    }
}

//function is to build the heap tree not sort
void buildHeap (arr* A){
    A->heapsize = A->size;
    for (int i = (A->size) / 2; i > 0; i--){
        cout << "----------Building the heap " << i << "-----------" << endl;
        //but the array start from 1 to n -1;
        maxHeapify(A, i - 1);
    }
    cout << "----------End building-----------" << endl;
}

int main(int argc, char** argv) {
    arr* A = new arr;
    //for initializing
    A->size = 16;
    generateRandom(A);
    buildHeap(A);
    
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

