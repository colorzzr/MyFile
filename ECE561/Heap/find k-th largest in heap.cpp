/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: color
 *
 * Created on October 9, 2018, 10:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

/****************************************************
 * using heap to find k-th largest number in array  *
 ****************************************************/

struct cc{
    bool operator()(pair<int, char> left, pair<int, char> right){
        return left.first < right.first;
    }
};

int main(int argc, char** argv) {
    //generate test case
    int test[50];
    for(int i = 0; i < 50; i++){
        test[i] = rand() % 50;
//        test[i] = i;
        cout << test[i] << " ";
    }
    cout << endl;
    
    int k = 34;
    
    priority_queue<int, vector<int>, greater<int>> myq;
    
    
    for(int i = 0; i < 50; i++){
        myq.push(test[i]);
        if(myq.size() > k) myq.pop();
    }
    
    cout << myq.top() << endl;
    
    
    return 0;
}



