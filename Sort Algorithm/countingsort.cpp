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
/****************************************************
 * Counting Sort Algorithm                          *
 * the counting sort running time is O(n)           *
 * but it need 2 more arrays to store               *
 * one array(temp) is to store the value in         *
 * original array that is <= its index i            *
 * Ex. original = {1, 3, 2, 1, 2, 0}                *
 *     temp = {1, 3, 5, 6}                          *
 *             |  |  |  |                           *
 *  index(i) = 0  1  2  3(max val is 3 in original  *
 * there are 3 value in original is greater         *
 * or equal to 1 {0, 1, 1}                          *
 * then new array is use temp to sort original      *
 * EX. original[5] is 0.. and temp show there are   *
 * only 1 value below 0(temp[0]).. so 0 is put in   *
 * new[1 - 1] which is also new[temp[original]]     *        
 ****************************************************/
typedef struct Arr{
    int *array;
    int size;
}arr;
void CountingSort(arr* original, arr* temp);
//create random array
void generateRandom (arr* array){
    for(int i = 0; i < array->size; i++){
        array->array[i] = rand() % 6;
        cout << array->array[i] << " ";
    }
    cout << endl << "--------Generating array---------" << endl;
}
void printArr(arr* A){
    cout << endl << "--------Printing array---------" << endl;
    for (int i = 0; i < A->size; i++){
        cout << A->array[i] << " ";
    }
    cout << endl;
}

void Counting(arr* A){
    //to search the max value in A 
    cout << endl << "--------Start counting---------" << endl;
    int max = A->array[0];
    for(int i = 1; i < A->size; i++){
        if(A->array[i] > max) max = A->array[i];
    }
    
    //create temp to store the number
    Arr* temp = new arr;
    //one more than max!!!!!!!!!!!!
    temp->size = max + 1;
    temp->array = (int*)malloc(sizeof(int) * max);
    //to count the number below i value, i is the index of temp
    for(int i = 0; i < A->size; i ++){
        temp->array[A->array[i]]++;
    }
    //to cumulative the value
    for(int i = 1; i < temp->size; i ++){
        temp->array[i] = temp->array[i] + temp->array[i - 1];
    }
    CountingSort(A, temp);
    delete temp;
}

void CountingSort(arr* original, arr* temp){
    //creating a new array for sorted value
    arr* now = new arr;
    now->size = original->size;
    now->array = (int*)malloc(sizeof(int) * now->size);
    
    cout << endl << "--------Start sorting---------" << endl;
    for(int i = now->size - 1; i >= 0 ; i--){
        now->array[temp->array[original->array[i]] - 1] = original->array[i];
        temp->array[original->array[i]]--;
    }
    printArr(now);
    delete now;
}


int main(int argc, char** argv) {
    arr* A = new arr;
    //for initializing
    A->size = 16;
    A->array = (int*)malloc(sizeof(int) * A->size);
    
    
    generateRandom(A);
    Counting(A);
   
    //printArr(A);
            
    return 0;
}

