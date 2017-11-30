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
#include <cstring>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <boost/shared_ptr.hpp>

using namespace std;

/*
 * 
 */
//to create a pack for size with array


//just a function to compare
int max(int first, int second){
    if (first > second) return first;
    else return second;
}

int RodCut(int* price, int length){
    int revenue[11];
    revenue[0] = 0;
    //loop for 1 to whole length
    for( int j = 1; j < length + 1;j++){
        int maxR = -32767;
        //then find the max profit for only one cut
        //cos we start at 1 we can find the best cut for smaller length
        //then we can increment the length by divide it into many best cut of smaller
        for( int i = 1; i < j + 1; i++){
            maxR = max(maxR, price[i - 1] + revenue[j - i]);
        }
        revenue[j] = maxR;
    }
    return revenue[length];
}

int main(int argc, char** argv) {
    int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << RodCut(price, 4);
    return 0;
}

