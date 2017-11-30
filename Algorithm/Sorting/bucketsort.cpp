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
 * Bucket Sort Algorithm                            *
 * Like counting sort the running time of bucket    *
 * sort is O(n), but it needs extra memory to store *
 * the sorted array.				    *
 * The key idea is similar to Hash table.	    *
 * We store the value based on it largest digit and *
 * place them in 10 link list.			    *
 * Ex.   24 56 34 63 23 45 33 67 94 21 52 13        *
 *        |0| -> NULL				    *
 *	  |1| -> 13 -> NULL			    *
 *	  |2| -> 21 -> 23 -> 24 -> NULL		    *
 *	  |3| -> 33 -> 34 -> NULL		    *
 *	  |4| -> 45 -> NULL			    *
 *	  |5| -> 52 -> 56 -> NULL		    *
 *	  |6| -> 63 -> 67 -> NULL		    *
 *	  |7| -> NULL				    *
 *	  |8| -> NULL				    *
 *	  |9| -> 94 -> NULL			    *
 * Finally link each sub-list together and copy the *
 * value to array			            *
 ****************************************************/
typedef struct Arr{
    int *array;
    int size;
}arr;

typedef struct Node{
    int val;
    Node *next;
    Node *previous;
}node;
node* NewNode(int value);
//create random array
void generateRandom (arr* array){
    for(int i = 0; i < array->size; i++){
        array->array[i] = rand() % 100;
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

void PrintList(node* headList){
    node* temp = headList;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

//remember to return the list cos 
node* InsertNode (node* list, node* insertOne){
    cout << endl << "--------Inserting new node---------" << endl;
    node* temp = list;
    //cout << insertOne->val << endl;
    //conner case: nothing in list
    if(temp == NULL) {
        //cout << "first node" << endl;
        list = insertOne;
    }
    //conner case: one node
    else if(list->next == NULL){
        //cout << "second node" << endl;
        node* tempy;
        if(temp->val < insertOne->val) {
            temp->next = insertOne;
            insertOne->previous = temp;
        }
        else{
            tempy = list;
            list = insertOne;
            //link forward and backword
            insertOne->next = tempy;
            tempy->previous = insertOne;
        }
    }
    //general case
    else{
        //cout << "general node" << endl;
        bool placed = false;
        while(temp->next != NULL){
            //if insert one is smaller place in previous
            if(temp->val > insertOne->val) {
                node* tempy = NULL;
                //the head of list
                if(temp->previous == NULL) {
                    tempy = list;
                    list = insertOne;
                    insertOne->next = tempy;
                    tempy->previous = insertOne;
                    placed = true;
                }
                else{
                    temp->previous->next = insertOne;
                    insertOne->previous = temp->previous;
                    insertOne->next = temp;
                    temp->previous = insertOne;
                    placed = true;
                }
                break;
            }
            else{
                //move to next!!
                temp = temp->next;
            }
        }
        //check last node
        if(placed == false){
            cout << "-------Checking the last node-------"<< endl;
            if(temp->val > insertOne->val){
                temp->previous->next = insertOne;
                insertOne->previous = temp->previous;
                insertOne->next = temp;
                temp->previous = insertOne;
            }
            else{
                //place at tail
                insertOne->previous = temp;
                temp->next = insertOne;
            }
        }
    }
    return list;
}

node* NewNode(int value){
    node* temp = new node;
    temp->val = value;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

//place the number in the term of val mod 10
void BucketSort(node** list, arr* A){
    cout << endl << "--------Sorting array---------" << endl;
    for(int i = 0; i < A->size; i++){
        node* temp = NewNode(A->array[i]);
        list[A->array[i] / 10] = InsertNode(list[A->array[i] / 10], temp);
    }
    
    for(int i = 0; i < 10; i ++){
        cout << "[" << i << "]: ";
        PrintList(list[i]);
        cout << endl;
    }
    
    //connect all list
    node* temp = list[0];
    node* headList = temp;
    for(int i = 0; i < 9; i++){
        //conner case: the sub head is NULL
        if (temp == NULL) {
            i++;
            temp = list[i];
            headList = temp;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = list[i + 1];
    }
    PrintList(headList);
    cout << endl << "--------Complete Sorting---------" << endl;
}

int main(int argc, char** argv) {
    arr* A = new arr;
    A->size = 30;
    A->array = (int*)malloc(sizeof(int) * A->size);
    node* list[10];
    //initialize to NULL for all sub-list head
    for (int i = 0; i < 10; i++)  list[i] = NULL;
    
    generateRandom(A);
    BucketSort(list, A);
    printArr(A);   
    
    /*
    node* listy;
    node* temp;
    listy = NewNode(7);
    temp = NewNode(2);
    listy = InsertNode (listy, temp);
    PrintList(listy);
    */        
    return 0;
}

