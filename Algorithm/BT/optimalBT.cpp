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
int min(int first, int second){
    if (first > second) return second;
    else return first;
}

void PrintTable(int cost[][4]){
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4; j++){
            printf(" %2d", cost[i][j]);
        }
        cout << endl;
    }
}

int GetVal(int row, int col, int cost[][4]){
    if(row > col) return 0;
    else return cost[row][col];
}

int OptimalBT(int* nodeKey, int* frequency){
    int cost[4][4];
    int root[4][4];

    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            //the diagonal only contain it self sign cost and root
            if (row == col) {
                cost[row][col] = frequency[row];
                root[row][col] = nodeKey[row];
            }
        }
    }
    //initial to zero
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(col < row) {
                cost[row][col] = 0;
                root[row][col] = 0;
            }
          
            //initial to base cost we must go through all point once
            else if (col > row ){
                int baseCost = 0;
                for (int temp = row; temp <= col; temp++){
                    baseCost = baseCost + cost[temp][temp];
                }
                cost[row][col] = baseCost;
            }
        }
    }
    
    /****************************************
     * Here we go through the diagonal by   *
     * diagonal as dynamic programming      *
     * Solve the small subproblem first     *
     * Here is the process                  *
     * 1. compute X diagonal                *
     *  4  X  -  -          4  8  -  -      *
     *  0  2  X  -          0  2 10  -      *
     *  0  0  6  X  ----->  0  0  6 12      *
     *  0  0  0  3          0  0  0  3      *
     * 2. Then compute Y diagonal           *
     *  4  8  Y  -          4  8 20  -      *
     *  0  2 10  Y          0  2 10 16      *
     *  0  0  6 12  ----->  0  0  6 12      *
     *  0  0  0  3          0  0  0  3      *
     ****************************************/
    for(int i = 1; i < 4; i++){
        for(int col = i, row = 0; col < 4; row++,col++){
            int minCost = 32767;
            //now here we need to choose the root and find min cost
            //if we pick up k(row <= k <= col)
            //cost = cost(row to k-1) + cost(k+1 to col) + base cost
            for(int tempRoot = row; tempRoot <= col; tempRoot++){
                if (GetVal(row, tempRoot - 1, cost) + GetVal(tempRoot + 1, col, cost) + cost[row][col] < minCost){
                    minCost = GetVal(row, tempRoot - 1, cost) + GetVal(tempRoot + 1, col, cost) + cost[row][col];
                    root[row][col] = nodeKey[tempRoot];
                }
            }
            cost[row][col] = minCost;
        }
    }
    PrintTable(cost);
    PrintTable(root);
    return cost[0][3];
}

int main(int argc, char** argv) {
    int price[4] = {10, 12 ,16 ,21};
    int frequency[4] = {4, 2, 6, 3};
    OptimalBT(price, frequency);
    return 0;
}

