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
    int unsortedArray[10] = {9,5,6,7,4,2,7,5,3,1};
    
    //outer loop to get smallest in array 
    for (int pos = 0; pos < size; pos++){
        int temp = unsortedArray[pos];
        int smallIndex = pos;
        for (int nowPos = pos; nowPos < size; nowPos++){
            if(unsortedArray[smallIndex] >= unsortedArray[nowPos]){
                smallIndex = nowPos;
            }
        }
        //put the smallest one to the head
        unsortedArray[pos] = unsortedArray[smallIndex];
        unsortedArray[smallIndex] = temp;
        for(int i = 0; i < 10 ;i++){
            printf("%d", unsortedArray[i]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < 10 ;i++){
        printf("%d", unsortedArray[i]);
    }
    
    return (EXIT_SUCCESS);
}

