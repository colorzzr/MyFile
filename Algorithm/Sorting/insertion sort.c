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
    
    //it is kind of bubble sort
    //go forward to get proper place
    for(int forwardPos = 0; forwardPos < size - 1;forwardPos++){
        if (unsortedArray[forwardPos] > unsortedArray[forwardPos + 1]){
            int temp = unsortedArray[forwardPos + 1];
            unsortedArray[forwardPos + 1] = unsortedArray[forwardPos];
            unsortedArray[forwardPos] = temp;
        }
        // and then go back to sort back
        for(int backPos = forwardPos; backPos > 0; backPos--){
            if (unsortedArray[backPos - 1] > unsortedArray[backPos]){
                int temp = unsortedArray[backPos];
                unsortedArray[backPos] = unsortedArray[backPos - 1];
                unsortedArray[backPos - 1] = temp;
            }
        }
    }
    
    for(int i = 0; i < 10 ;i++){
        printf("%d", unsortedArray[i]);
    }
    
    return (EXIT_SUCCESS);
}

