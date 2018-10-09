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
 * using heap to order the char with its frequency  *
 ****************************************************/

struct cc{
    bool operator()(pair<int, char> left, pair<int, char> right){
        return left.first < right.first;
    }
};

int main(int argc, char** argv) {
    string test = "color sdlkfjaaoqwiej";
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> myq;
    vector<int> mv(26, 0);
    
    
    for(int i = 0; i < test.length(); i++){
        mv[test[i] - 'a']++;
    }
    for(int i = 0; i < mv.size(); i++){
        if(mv[i] != 0) myq.push(make_pair(mv[i], 'a' + i));
    }
    
    while(!myq.empty()){
        cout << myq.top().second << endl;
        myq.pop();
    }
    
    return 0;
}



