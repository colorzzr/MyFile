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
#include <stdbool.h>
/*
 * 
 */
int Partition();
void QuickSort (int* list, int first, int last){
    if (first >= last) return;
    int half = Partition(list, first, last);
    
    QuickSort(list, first, half);
    QuickSort(list, half + 1, last);
    
    return;
}


int Partition(int* list,int first, int last){
    int x = first;
    int y = last;
    int pivot = list[(x + y)/2];
    bool clear = false;
    
    while(clear != true){
        //check the thing at left of pivot must be small
        while(list[x] < pivot) x++;
        //check the thing at right of pivot must be large
        while(list[y] > pivot) y--;
        
        //if y pass the x mean pivot is at right place
        if(y <= x) clear = true;
        else{
            int temp = list[x];
            list[x] = list[y];
            list[y] = temp;
            x++;y--;
        }
        //for(int i = 0; i < 5; i++) printf("%d ", list[i]);
        //printf("\n\n");
    }
    
    /****************************************************
     * reason for pass y instead of x                   *
     * loop is terminated when x is equal or 1 above y  *
     * y + 1 is within region we need to sort           *
     * while x + 1 is not                               *
     ****************************************************/
    return y;
}

int main(int argc, char** argv) {
    int list[10] = { 3, 1, 5, 4, 0, 9, 2, 6, 0, 8};
    
    QuickSort(list, 0, 9);
    //QuickSort(list, 0, 4);
    for(int i = 0; i < 10; i++) printf("%d ", list[i]);
    
    return (EXIT_SUCCESS);
}

