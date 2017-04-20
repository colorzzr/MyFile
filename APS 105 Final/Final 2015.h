/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Final 2015.h
 * Author: user
 *
 * Created on April 13, 2017, 8:38 PM
 */

#ifndef FINAL_2015_H
#define FINAL_2015_H



#endif /* FINAL_2015_H */
#include <stdbool.h>

/********************************************************
 * 2015 Final question 9                                *
 * pick up k items in n item (n must be greater than k) *
 * calculate how many selection                         *
 * formula is n!/(k!*(n - k)!)                          *
 ********************************************************/
int Final2015Q9 (int n, int k){
    int factorial;
    /*******************************************************
     * this is a very tricky question                      *
     * it is hard to compute three base case               *
     * but you can find n!/k! can cancel each other        *
     * (4*3*2*1)/(2*1) = 4*3 k! is always the tail of n!   *
     * so it become one base case                          *
     * Ex. n = 8, k = 5                                    *
     * n!/k! = 8*7*6   and    (n - k)! = 3*2*1             *
     * it become (8/3)*(7/2)*(6/1)                         *
     *******************************************************/
    
    //remember to think about the conner case
    if ((n - k) == 0) return 1;
    //base case is n - k = 1
    else if ((n - k) == 1) return (n /(n - k));
    //Or get into recursion 
    else factorial = (n / (n - k)) * Final2015Q9(n - 1, k);
   
    return factorial ;
}

/******************************************
 * 2015 final question 10                 *
 * use bubble sort to sort the struct     *
 * by GPA use ascending                   *
 ******************************************/
typedef struct GPA{
    int GPA;
    char *name;
} record;

void Final2015Q10(record gradeArray[], int size){
    record temp;
    
    
    //get into loop for bubble sort
    for(int posMax = size; posMax > 0; posMax--){
        for(int pos = 0; pos < posMax - 1; pos++){
            //compare the GPA
            if (gradeArray[pos].GPA > gradeArray[pos + 1].GPA){
                temp = gradeArray[pos];
                gradeArray[pos] = gradeArray[pos + 1];
                gradeArray[pos + 1] = temp;
            }
            //if GPA is same compare the name
            else if (gradeArray[pos].GPA = gradeArray[pos + 1].GPA){
                if(strcmp(gradeArray[pos].name, gradeArray[pos + 1].name) > 0){
                    temp = gradeArray[pos];
                    gradeArray[pos] = gradeArray[pos + 1];
                    gradeArray[pos + 1] = temp;
                }
            }
        }
    }
    return;
}

/*
 * 2015 Final question 11
 * to average the pixel number for camera
 * average the number from 3*3 block and copy it in to new block
 */

void Final2015Q11 (double A[100][100], double B[98][98]){
    //choose the center of average square
    for(int rowPos = 1;rowPos < 100; rowPos++){
        for(int colPos = 1; colPos < 100; colPos++){
            /************************************************
             * dont forget to initialize inside the loop!!  *
             * int x = rowPos - 1;                          *
             * int y = colPos - 1;                          *
             ************************************************/
            //start to sum up the 3*3 block
            double sum = 0;
            //printf("x:%d y:%d\n", x, y);
            for(int x = rowPos - 1; x < rowPos + 2; x++){
                for(int y = colPos - 1; y < colPos + 2; y++){
                    sum = sum + A[x][y];
                }
            }
            //PASTE into B
            B[rowPos - 1][colPos - 1] = sum / 9.0;
        }
    }
    return;
}


typedef struct Node{
    int value;
    struct Node* link;
}node;
/************************************************************************
 * 2015 Final question to simplify the list with some duplicate number  *
 * this is hard I think. the conner case is the same number in tail     *
 ************************************************************************/
void Final2015Q12(node* head){
    node* current = head;
    node* temp;
    while(current != NULL){
        //conner case: if there is only one node
        if (current->link == NULL){
            return;
        }
        //general cas; more than two in the list
        else{
            //to avoid conner case more than two same in the tail
            if (current->link->link != NULL){
                while((current->value == current->link->value)){
                    //check first!! because you delete one after
                    //if the node the last two in the list
                        temp = current->link;
                        current->link = current->link->link;
                        free(temp);
                    }
                }
            if (current->link->link == NULL){
                if(current->value == current->link->value){
                    free(current->link->link);
                    current->link = NULL;
                }
            }
        }
        current = current->link;
    }
    
    return;
}

/********************************************************
 * 2015 Final question 13                               *
 * if two string have same length and same characters   *
 * they call anagram                                    *
 * Ex. "lives" vs "elvis"                               *
 ********************************************************/
bool Final2015Q13 (char s1[], char s2[]){
    int length = strlen(s1);
    //conner case they are not same length
    if (strlen(s1) != strlen(s2)) return false;
    //general case
    //in fact this is a sort problem
    //just sorting the string than compare
    for(int posMax = length - 1; posMax > 0; posMax--){
        for (int pos = 0; pos < length - 1; pos++){
            if(s1[pos] > s1[pos + 1]){
                char temp = s1[pos];
                s1[pos] = s1[pos + 1];
                s1[pos + 1] = temp;
            }
        }
    }
    
    for(int posMax = length - 1; posMax > 0; posMax--){
        for (int pos = 0; pos < length - 1; pos++){
            if(s2[pos] > s2[pos + 1]){
                char temp = s2[pos];
                s2[pos] = s2[pos + 1];
                s2[pos + 1] = temp;
            }
        }
    }
    
    if(strcmp(s1, s2) == 0) return true;
    else return false;
}

/***********************************************************************
 * 2015 Final question 14                                              *
 * for the binary tree to get the number of node below the parametirc  *
 * requirement                                                         *
 * 1. use recursion                                                    *
 * 2. use binary sort                                                  *
 ***********************************************************************/
typedef struct bTree{
    int value;
    struct bTree* left;
    struct bTree* right;
}treeNode;
int Final2015Q14(int threshold, treeNode* root){
    int sum = 0;
    treeNode* tree = root;
    //base case: there is no child
    if(tree->left == NULL && tree->right == NULL){
        if(tree->value < threshold) return 1;
        else return 0;
    }
    
    //inter base there is one child
    else if(tree->left != NULL && tree->right == NULL){
        if(tree->value < threshold){
            sum = sum + 1 + Final2015Q14(threshold, tree->left);
        }
        else{
            sum = sum + 0 + Final2015Q14(threshold, tree->left);
        }
    }
    
    //right is always greater than parent value
    else if(tree->left == NULL && tree->right != NULL){
        if(tree->value < threshold){
            sum = sum + 1 + Final2015Q14(threshold, tree->right);
        }
        else return 0;
    }
    //upper case have two children
    else if (tree->left != NULL && tree->right != NULL){
        if(tree->value < threshold){
            sum = sum + 1 + Final2015Q14(threshold, tree->left);
            sum = sum + Final2015Q14(threshold, tree->right);
        }
        else{
            sum = sum + Final2015Q14(threshold, tree->left);
        }
    }
    
    return sum;
}