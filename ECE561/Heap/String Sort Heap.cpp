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

/*
 * 
 */
int main(int argc, char** argv) {
    string test = "color";
    
    priority_queue<char, vector<char>, greater<int>> myq;
    
    for(int i = 0; i < test.length(); i++){
        myq.push(test[i]);
    }
    
    while(!myq.empty()){
        cout << myq.top() << endl;
        myq.pop();
    }
    
    return 0;
}



