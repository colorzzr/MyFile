/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   selection sort.c
 * Author: user
 *
 * Created on April 11, 2017, 7:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


int main(int argc, char** argv) {
    int size = 10;
    int unsortedArray[10] = {1,2,3,4,6,7,8,9,11,12};
    int searchNum = 0;
    //ask input
    printf("which number do you want to search by binary search?\n");
    scanf("%d", &searchNum);
    //get lowPos and highPos to sort havlf
    int lowPos = 0, highPos = size;
    while(lowPos != highPos){
        if(unsortedArray[(lowPos + highPos)/2] < searchNum){
            lowPos = (lowPos + highPos)/2 + 1;
        }
        else{
            highPos = (lowPos + highPos)/2;
        }
    }
    if (searchNum == unsortedArray[lowPos]){
        printf("%d found in Position %d\n", searchNum, lowPos);
    }
    else{
        printf("No Found\n");
    }
    return (EXIT_SUCCESS);
}

