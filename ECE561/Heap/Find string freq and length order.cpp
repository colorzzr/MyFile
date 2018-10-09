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
#include <map>

using namespace std;

/****************************************************
 * using heap to find string with it length and freq*
 ****************************************************/

struct Compare{
    bool operator()(pair<int, string> left, pair<int, string> right){
        return left.first < right.first || left.first == right.first && left.second < right.second;
    }
};

int main(int argc, char** argv) {
    //generate test case
    string test[7] = {"I", "love", "ECE", "I", "love", "ef", "I"};
    
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> myq;
    map<string, int> mymap;
    
    for(int i = 0; i < 7; i++){
        mymap[test[i]]++;
    }
    
    for(map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
        myq.push(make_pair(it->second, it->first));
    }
    
    cout << myq.top().second << endl;
    myq.pop();
    cout << myq.top().second << endl;
    
    return 0;
}



