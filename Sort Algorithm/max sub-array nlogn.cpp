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
MaxIndex FindMaxCrossSubArr(int array[], int low, int high, int mid){
    //get max left
    MaxIndex temp;
    int leftSum = -99999, rightSum = -9999999;
    for (int i = mid, sum = 0; i >= 0; i--){
        sum = sum + array[i];
        if (sum > leftSum){
            leftSum = sum;
            temp.low = i;
        }
    }
    //get max from right
    for (int i = mid + 1, sum = 0; i < high; i++){
        sum = sum + array[i];
        if (sum > rightSum){
            rightSum = sum;
            temp.high = i;
        }
    }
    //sum up and rutern
    temp.maxSum = leftSum + rightSum;
    return temp;
}

//recur func here
MaxIndex FindMaxArray(int array[], int low, int high){
    //base case: only one node
    if (low == high) {
        MaxIndex temp;
        temp.high = high;
        temp.low = low;
        temp.maxSum = array[low];
        return temp;
    }
    //general case: recur
    else {
        int mid = (low + high) / 2;
        MaxIndex left, right, cross;
        left = FindMaxArray(array, low, mid);
        right = FindMaxArray(array, mid + 1, high);
        cross = FindMaxCrossSubArr(array, low, high, mid);
        
        //now get the max sub array for general return
        if(right.maxSum >= left.maxSum && right.maxSum >= cross.maxSum) return right;
        else if (left.maxSum >= right.maxSum && left.maxSum >= cross.maxSum) return left;
        else return cross;
    }
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
    
    left = FindMaxArray(array, 1, 16);
    //right = FindMaxSubArr(array, right, size);
    
    cout << left.low << " " << left.high << " " << left.maxSum << endl;
    //cout << right.low << " " << right.high << " " << right.maxSum;
    
    return 0;
}
