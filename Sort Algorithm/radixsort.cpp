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
#include <cmath>

using namespace std;
/****************************************************
 * Radix Sort Algorithm                             *
 * Radix Sort is some kind of different version of  *
 * bucket sort.(bucket sort is stable sort)         *
 * it sorts from lowest digit to highest digit      *
 * Ex.                                              *
 *      356     44|5|   1|2|8   |1|28   128         *
 *      445     35|6|   4|4|5   |2|56   256         *
 *      128     77|7|   3|5|6   |4|45   445         *
 *      777     12|8|   7|7|7   |7|77   777         *
 *                                                  *
 * But the problem is we need stable sort O(n)      *
 * Or the running time of bucket sort is higher     *
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
        array->array[i] = rand() % 200;
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

void CopyValToA(arr* A, node* headList){
    for(int i = 0; headList != NULL; i++, headList = headList->next){
        A->array[i] = headList->val;
    }
}

//place the number in the term of val mod 10
void BucketSort(node** list, arr* A){
    cout << endl << "--------Sorting array---------" << endl;
    //assume we have 3-digit number
    for(int j = 0; j < 3; j++){
        //initialize to NULL for all sub-list head
        for (int i = 0; i < 10; i++)  list[i] = NULL;
        //use bucket sort here to sort by every digit
        for(int i = 0; i < A->size; i++){
            node* temp = NewNode(A->array[i]);
            int power = pow(10.0,j);
            list[(A->array[i] / power) % 10] = InsertNode(list[(A->array[i] / power) % 10], temp);
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
        CopyValToA(A, headList);
        //PrintList(headList);
        cout << endl << "--------Complete Sorting---------" << endl;
    }
}

int main(int argc, char** argv) {
    arr* A = new arr;
    A->size = 20;
    A->array = (int*)malloc(sizeof(int) * A->size);
    node* list[10];
    
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

