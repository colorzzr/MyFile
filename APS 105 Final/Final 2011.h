/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Final 2011.h
 * Author: user
 *
 * Created on April 14, 2017, 8:59 AM
 */

#ifndef FINAL_2011_H
#define FINAL_2011_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FINAL_2011_H */

/************************************
 * 2011 Final Question 2            *
 * rotate array to left             *
 * Ex. 1230 -> 2301 for 1 rotate    *
 ************************************/
void Final2011Q2(int a[], int length, int rotate){
    
    for(int times = 0; times < rotate; times++){
        int temp = a[0];
        for (int pos = 0; pos < (length - 1); pos++) a[pos] = a[pos + 1];
        a[length - 1] = temp;
    }
    return;
}

/****************************************
 * 2011 Final question 3                *
 * change string"123" to integer 123    *
 ****************************************/
int Final2011Q3 (char *str){
    int integer = 0;
    while(*str != '\0'){
        integer = integer * 10 + (*str - 48);
        str++;
    }
    return integer;
}

/**************************************************
 * 2011 final question 4                          *
 * use recursion to print number in reverse way   *
 * cannot use array                               *
 **************************************************/
void Final2011Q4(){
    int input;
    printf("Enter a positive integer or 0 to exit:");
    scanf("%d", &input);
    //use if here cause it only run one time
    if (input != 0) Final2011Q4();
    printf("%d ", input);
}

void Final2011Q6 (int input[], int n, int count[], int k){
    //for count cause it only range 0 - k
    for (int j = 0; j <= k; j++){
        //for count how many in input is below j
        for (int i = 0; i < n; i++){
            if (input[i] <= j) {
                count[j] = count[j] + 1;
            }
        } 
    }
    return;
}

/********************************************************
 * 2011 final question 7                                *
 * to write a function same as strchr                   *
 * which return the address of first occurrence at s1   *
 ********************************************************/
char* Final2011Q7 (char* s1, char* s2){
    char* pos1 = s1;
    
    while(*pos1 != '\0'){
        char* pos2 = pos1;
        char* x = s2;
        bool found = true;
        
        while((*x) != '\0' && found == true){
            if(*x == *pos2){
                found = true;
                x++;
                pos2++;
            }
            else found = false;
        }
        
        if(found == true) return pos1;
        pos1++;
    }
    
    return NULL;
}

/********************************************************
 * 2011 final question 8                                *
 * print out the duplicate number in the link list      *
 ********************************************************/
typedef struct node{
    int info;
    struct node* link;
}Node;

void Final2011Q8(Node* head){
    Node* current1 = head;
    while(current1->link != NULL){
        Node* current2 = current1->link;
        int num = current1->info;
        int count = 0;
        //question assume number appear only twice
        while(current2 != NULL){
            if (num == current2->info){
                count++;
            }
            current2 = current2->link;
        }
        //if appear twice print it and this would not show the deplicate
        if (count == 1) printf("%d ", current1->info);
        current1 = current1->link;
    }
    return;
}

/****************************************************
 * 2011 Final question 9                            * 
 * sort the link list                               *
 * and put the even number in front of odd number   *
 * Ex. 123456 -> 246135 or 642135 (any order)       *
 ****************************************************/
Node* Final2011Q9 (Node* head){
    Node* temp;
    Node* previous = head;
    
    //conner case there no node
    if (head == NULL) return NULL;
    Node* current = head->link;
    //general case
    while(current != NULL){
        if (current->info % 2 == 0){
            //just move the even to the head
            temp = head;
            previous->link = current->link;
            head = current;
            current->link = temp;
            current = previous->link;
        }
        else {
            current = current->link;
            previous = previous->link;
        }
    }
    return head;
}

