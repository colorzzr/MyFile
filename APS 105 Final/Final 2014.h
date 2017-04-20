/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Final 2014.h
 * Author: user
 *
 * Created on April 14, 2017, 3:05 PM
 */

#ifndef FINAL_2014_H
#define FINAL_2014_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FINAL_2014_H */

/****************************************************
 * 2014 Final question 9                            *
 * use newton method to calculate the square root   *
 * error with in 0.001                              *
 ****************************************************/
double Final2014Q9 (double x){
    double old = x, new = x/2.0;
    double gap = old - new;
    
    while (gap > 0.001){
        double temp = new;
        new = old - (old * old - x)/((2 * old));
        old = temp;
        gap = fabs(old - new);
    }
    return new;
}

/****************************************
 * 2014 Final question 10               *
 * insert new NOde at particular node   *
 * in the doubly link list              *
 ****************************************/
typedef struct dNodeDS{
    int value;
    struct dNodeDS *left, *right;
}DNode;

DNode* Final2014Q10(DNode* head, DNode* placeNode, DNode* newNode){
    //conner case; insert at head
    if (placeNode == head){
        DNode* temp = head;
        head = newNode;
        newNode->right = temp;
        temp->left = newNode;
    }
    //general case
    else{
        DNode* tem = placeNode->left;
        newNode->right = placeNode;
        placeNode->left = newNode;
        tem->right = newNode;
        newNode->left = tem;
    }
    return head;
}

/****************************************
 * 2014 Final question 11               *
 * use sieve algorithm start at p = 2   *
 * eliminate 2p 3p....                  *
 ****************************************/
void Final2014Q11(){
    int list[100];
    int primePos = 1;
    //int i;
    //create 1 - 100
    for(int j = 1; j <= 100; j++) list[j - 1] = j;
    
    //potentially eliminate non-prime number set to -1;
    while(list[primePos]*list[primePos] < 100){
        //start at next number
        for(int i = primePos + 1; i < 100; i++){
            if (list[i] % list[primePos] == 0){
                list[i] = 1;
            }
        }
        primePos++;
        while(list[primePos] == 1){
            primePos++;
        }
    }
    
    for(int i = 0; i < 100; i++) {
        if (list[i] != 1) printf("%d ", list[i]);
    }
}

/************************************************
 * 2014 Final question 11                       *
 * count number of value between min and Max    *
 * in binary tree                               *
 ************************************************/

typedef struct bTree{
    int value;
    struct bTree* left;
    struct bTree* right;
}treeNode;

int CountBew(treeNode* root, int min, int max){
    treeNode* tree = root;
    //base case: there is no child
    if(tree->left == NULL && tree->right == NULL){
        if(tree->value < max && tree->value > min) return 1;
        else return 0;
    }
    
    //inter base there is one child
    else if(tree->left != NULL && tree->right == NULL){
        if(tree->value < max && tree->value > min) return 1 + CountBew(tree->left, min, max);
        else if(tree->value >= max) return 0 + CountBew(tree->left, min, max);
        //left is smaller than this node
        else if(tree->value <= min) return 0;
    }
    
    //right is always greater than parent value
    else if(tree->left == NULL && tree->right != NULL){
        if(tree->value < max && tree->value > min) return 1 + CountBew(tree->right, min, max);
        else if(tree->value <= min) return 0 + CountBew(tree->right, min, max);
        //left is smaller than this node
        else if(tree->value >= max ) return 0;
    }
    //general case have two children
    else if (tree->left != NULL && tree->right != NULL){
        if(tree->value < max && tree->value > min){
            return 1 + CountBew(tree->left, min, max) + CountBew(tree->right, min, max);
        }
        else if(tree->value >= max ) return 0 + CountBew(tree->left, min, max);
        else if(tree->value <= min) return 0 + CountBew(tree->right, min, max);
    }
}

/********************************
 * 2014 Final question 13       *
 * sort the coin 1 5 10 25      *
 * without compare each other   *
 ********************************/
void Final2014Q13 (int array[], int size){
    int lastPos = 0;
    //for 1
    for(int i = lastPos; i < size ; i++){
        if (array[i] == 1){
            int temp = array[lastPos];
            array[lastPos] = array[i];
            array[i] = temp;
            lastPos++;
        }
    }
    
    //for 5
    for(int i = lastPos; i < size ; i++){
        if (array[i] == 5){
            int temp = array[lastPos];
            array[lastPos] = array[i];
            array[i] = temp;
            lastPos++;
        }
    }
    
    //for 10
    for(int i = lastPos; i < size ; i++){
        if (array[i] == 10){
            int temp = array[lastPos];
            array[lastPos] = array[i];
            array[i] = temp;
            lastPos++;
        }
    }
    
    //
    for(int i = lastPos; i < size ; i++){
        if (array[i] == 25){
            int temp = array[lastPos];
            array[lastPos] = array[i];
            array[i] = temp;
            lastPos++;
        }
    }
    
    return;
}

/************************************************
 * 2014 Final question 14                       *
 * transfer the name to the last with initial   *
 * Ex. Color Zhan -> Zhan, C.                   *
 ************************************************/
void getStringFromUserInput(char s[], int maxStrLength) {
    int i = 0;
    char c = 'g';

    while (i < maxStrLength && ((c = getchar()) != '\n'))
      s[i++] = c;

    s[i] = '\0';
    return;
}
void Final2014Q14(){
    char name[50];
    do {
        getStringFromUserInput(name, 50);
        //get the last name;
        int firstPos = 0;
        int lastPos, endPos;
        for (lastPos = 0; name[lastPos] != '\0'; lastPos++){
            if (name[lastPos] == ' '){
                firstPos = lastPos;
            }
        }
        //print the last name
        for(int i = firstPos; i < lastPos; i++) {
            //conner case: the first is not start with space
            if (firstPos == 0) printf("%c",name[firstPos]);
            else printf("%c", name[i]);
        }
        printf(", ");
        
        //find initial
        for(lastPos = 0; lastPos < firstPos; lastPos++){
                if(lastPos == 0) printf("%c. ", name[lastPos]);
                else if(name[lastPos] == ' ') printf("%c. ", name[lastPos + 1]);
        }
        
    }while(name != "ZZZ\0");
    
    
    return;
}

/************************************
 * 2014 Final question15            *
 * to find the cross in the array   *
 * Ex.                              *
 *  0 1 0                           *
 *  1 1 1   -> found at 1,1         *
 *  0 1 0                           *
 ************************************/  
void Final2014Q15(){
    int array[3][3] = { {0, 1, 1},
                        {1, 1, 1},
                        {0, 1, 0}};
    int n = 5;
    int size = 3;
    
    for(int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            //the cross region is depended on n
            if(array[row][col] == 1 && row >= ((n - 1)/2) && row <= (size - (n - 1)/2) && col >= ((n - 1)/2) && col <= (size - (n - 1)/2)){
                bool found = false;
                for(int x = row - (n - 1)/2, xEnd = row + (n - 1)/2; x <= xEnd; x++){
                    if (array[x][col] == 1 ) found = true;
                    else found = false;
                }
                for(int y = col - (n - 1)/2, yEnd = col + (n - 1)/2; y <= yEnd; y++){
                    if (array[row][y] == 1) found = true;
                    else found = false;
                }
                if(found == true) printf("Cross %d is found at (%d, %d)\n", n, row, col);
            }
        }
    }
    
}