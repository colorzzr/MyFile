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

/*
 * 
 */
//use struct to return more value
class MaxIndex{
public:
    int low;
    int high;
    int maxSum;
    MaxIndex(int lowInd);
    MaxIndex();
};

//default
MaxIndex::MaxIndex(){
    low = 0;
    high = 0;
    maxSum = 0;
}

MaxIndex::MaxIndex(int lowInd){
    low = lowInd;
    high = 0;
    maxSum = 0;
}

//find the subarray
MaxIndex FindMaxSubArr(int array[], MaxIndex sub, int size){
    int sum = 0;
    //use nestloop!!!!!!!!!!!to check any combination!!
    for(int i = 0; i < size ; i++){
        //init to the first val
        sum = array[i];
        
        for (int j = i + 1; j < size; j ++){
            sum = sum + array[j];
            cout << sum << " ";
            //get sub record the low and high
            if (sum > sub.maxSum){
                sub.low = i;
                sub.high = j;
                sub.maxSum = sum;
            }
        }
        cout << endl;
    }
    cout << endl;
    return sub;
}


int main(int argc, char** argv) {
    //assume the size is power of 2
    int array[16];
    //generate srand seed
    int seed = 2434;
    srand(seed);
    //creat array ramdomly
    for(int i = 0; i < 16; i++){
        array[i] = rand()%10 - 3;
        cout << array[i] << " ";
    }
    cout << endl;

    //change to larger size
    int size = 16;
    MaxIndex left(0);
    
    left = FindMaxSubArr(array, left, size);
    //right = FindMaxSubArr(array, right, size);
    
    cout << left.low << " " << left.high << " " << left.maxSum << endl;
    //cout << right.low << " " << right.high << " " << right.maxSum;
    
    return 0;
}

