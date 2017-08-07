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
#include <cmath>
#include <boost/shared_ptr.hpp>

using namespace std;
//struct for node
typedef struct RBT{
    int value;
    char color;
    RBT* parent;
    RBT* left;
    RBT* right;
    //for sentinal 't' for normal Node, 's' for start guard, 'e' for ending guard
    char nil;
    //new functional size: contains the subtree node's number
    int size;
}rbt;

void FixUp (rbt* insertNode);
void DeleteFixUpp(rbt* doubleBlackNode);
void RotateToLeft(rbt* nodeOnRight, rbt* node);
void RotateToRight(rbt* nodeOnLeft, rbt* node);
void PrintTree(rbt* headList);
rbt* NewNode(int value);
int CountSize(rbt* headList);

//initializing for the node
rbt* NewNode(int value){
    rbt* newNode = new rbt;
    newNode->value = value;
    newNode->color = 'r';
    newNode->left = NULL;
    newNode->parent = NULL;
    newNode->right = NULL;
    //initializing for tree node not sentinal
    newNode->nil = 't';
    return newNode;
}

//for ending guard
rbt* NewNode(){
    rbt* newNode = new rbt;
    newNode->color = 'b';
    newNode->left = NULL;
    newNode->parent = NULL;
    newNode->right = NULL;
    //initializing for tree node not sentinal
    newNode->nil = 'e';
    newNode->value = -32767;
    newNode->size = 0;
    return newNode;
}

void InsertNode(rbt* headList, rbt* newNode){
    //jump to actual root
    rbt* temp = headList->left;
    //find the right end we place the new node
    while(temp->nil != 'e'){
        //property of BT... left is greater and right is smaller
        if(newNode->value > temp->value){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    //go back to parent and start insert
    temp = temp->parent;
    
    //conner case: empty list
    if (headList->left->nil == 'e') {
        cout << "----------Empty list start insert head----------" << endl;
        delete headList->left;
        headList->left = newNode;
        //connect with parent
        newNode->parent = headList;
        //create end sentinal
        rbt* endNode = NewNode();
        headList->left->right = endNode;
        endNode->parent = headList->left;
        endNode = NewNode();
        headList->left->left = endNode;
        endNode->parent = headList->left;
        //root should be black
        headList->left->color = 'b';
    }
    //general case: the insert is greater
    else if (temp->value < newNode->value){
        cout << "----------start to insert right-----------" << endl; 
        //even it is ending guard we can save it to connect
        rbt* tempy = temp->right;
        //connect new with parent
        temp->right = newNode;
        newNode->parent = temp;
        //connect new with children
        newNode->right = tempy;
        newNode->right->parent = newNode;
        //give left a end guard
        tempy = NewNode();
        newNode->left = tempy;
        tempy->parent = newNode;
    }
    //general case: the insert is smaller
    else {
        cout << "----------start to insert left-----------" << endl; 
        //even it is ending guard we can save it to connect
        rbt* tempy = temp->left;
        //connect new with parent
        temp->left = newNode;
        newNode->parent = temp;
        //connect new with children
        newNode->left = tempy;
        newNode->left->parent = newNode;
        //give right a end guard
        tempy = NewNode();
        newNode->right = tempy;
        tempy->parent = newNode;
    }
    //for maintaining the red-black tree
    FixUp(newNode);
    CountSize(headList->left);
}

int CountSize(rbt* headList){
    if(headList->nil != 'e') {
        headList->size = CountSize(headList->left) + CountSize(headList->right) + 1;
        return headList->size;
    }
    else{
        return 0;
    }
}

void FixUp (rbt* insertNode){
    //the problem is the property 2 and 4 the insert node parent is red
    while(insertNode->parent->color == 'r' && insertNode->color == 'r'){
        //insert on left side
        if (insertNode->parent == insertNode->parent->parent->left){ 
            
            rbt* grandPa = insertNode->parent->parent;
            /*
             * case 1: the uncle of insert node is red(left)
             *      A(B)                    A(B)
             *      /  \
             *   B(R)  C(R)         ->
             *      \
             *     C(R)(either side)
             */
            if(grandPa->right->color == 'r'){
                cout << "----------case 1---------" << endl;
                //paint all parent and uncle to black grandpa to red
                grandPa->color = 'r';
                grandPa->left->color = 'b';
                grandPa->right->color = 'b';
                //set grandPa to new loop para
                insertNode = grandPa;
                //conner case: if grandPa is head
                if(insertNode->parent->nil == 's') insertNode->color = 'b';
            }
            //case 2: the uncle of insert node is black(left)
            else if (grandPa->right->color == 'b'){
                // and insert is right children (case 2)
                if(insertNode == grandPa->left->right){
                    cout << "----------case 2---------" << endl;
                    RotateToLeft(insertNode, grandPa->left);
                }
                //PrintTree(grandPa);
                /***********************************************
                 * remember here the grandPa now is not change *
                 * if not go through the case 2                *
                 * list is grandPa -> parent -> insertNode     *
                 * if go through case 2                        *
                 * list is grandPa -> insertNode -> parent     *
                 ***********************************************/
                insertNode = grandPa->left->left;
                //paint black and white to maintain the property 4
                grandPa->left->color = 'b';
                grandPa->color = 'r';
                
                
                //then it is case 3 the insert node is left children(even it rotate they are both red)
                cout << "----------case 3---------" << endl;
                RotateToRight(grandPa->left, grandPa);
                //move up one node cos we operate the parent and grandPa here
                insertNode = insertNode->parent;
            }
            
            else cout << "----------unexecpted output---------" << endl;
        }
        
        //the parent is on right side
        else{
            rbt* grandPa = insertNode->parent->parent;
            //case 1: the uncle of insert node is red(right)
            if(grandPa->left->color == 'r'){
                cout << "----------case 1---------" << endl;
                //paint all parent and uncle to black grandpa to red
                grandPa->color = 'r';
                grandPa->left->color = 'b';
                grandPa->right->color = 'b';
                //set grandPa to new loop para
                insertNode = grandPa;
                //conner case: if grandPa is head
                if(insertNode->parent->nil == 's') insertNode->color = 'b';
            }
            //case 2: the uncle of insert node is black(right)
            else if (grandPa->left->color == 'b'){
                // and insert is right children (case 2)
                if(insertNode == grandPa->right->left){
                    cout << "----------case 2---------" << endl;
                    RotateToRight(insertNode, grandPa->right);
                }
                /***********************************************
                 * remember here the grandPa now is not change *
                 * if not go through the case 2                *
                 * list is grandPa -> parent -> insertNode     *
                 * if go through case 2                        *
                 * list is grandPa -> insertNode -> parent     *
                 ***********************************************/
                insertNode = grandPa->right->right;
                //paint black and white to maintain the property 4
                insertNode->parent->color = 'b';
                grandPa->color = 'r';
                //insertNode->parent->color = 'b';
                
                //then it is case 3 the insert node is left children(even it rotate they are both red)
                cout << "----------case 3---------" << endl;
                RotateToLeft(grandPa->right, grandPa);
                //move up one node cos we operate the parent and grandPa here
                insertNode = insertNode->parent;
            }
            else cout << "----------unexecpted output---------" << endl;
        }
    }
    
    cout << endl;
}


void RotateToLeft(rbt* nodeOnRight, rbt* node){
    //operate on children first
    node->size = node->left->size + nodeOnRight->left->size + 1;
    nodeOnRight->size = node->size + nodeOnRight->right->size + 1;
    node->right = nodeOnRight->left;
    node->right->parent = node;
    nodeOnRight->left = node;
    rbt* parent = node->parent;
    node->parent = nodeOnRight; 
    //operate on parent
    //conner case: we rotate at root
    if(parent->nil == 's'){
        cout << "----------Parent is root----------" << endl;
        parent->left = nodeOnRight;
        nodeOnRight->parent = parent;
    }
    //general case: node is on the left of parent
    else if (node == parent->left){
        cout << "----------Parent is left----------" << endl;
        parent->left = nodeOnRight;
        nodeOnRight->parent = parent;
    }
    //general case: node is on the right
    else if (node == parent->right){
        cout << "----------Parent is right----------" << endl;
        parent->right = nodeOnRight;
        nodeOnRight->parent = parent;
    }
    else{
        cout << "----------Error----------" << endl;
    }
}

void RotateToRight(rbt* nodeOnLeft, rbt* node){
    //operate on children first
    node->size = node->right->size + nodeOnLeft->right->size + 1;
    nodeOnLeft->size = node->size + nodeOnLeft->left->size + 1;
    node->left = nodeOnLeft->right;
    node->left->parent = node;
    nodeOnLeft->right = node;
    rbt* parent = node->parent;
    node->parent = nodeOnLeft;
    
    //operate on parent
    //conner case: we rotate at root
    if(parent->nil == 's'){
        cout << "----------Parent is root----------" << endl;
        parent->left = nodeOnLeft;
        nodeOnLeft->parent = parent;
    }
    //general case: node is on the left of parent
    else if (node == parent->left){
        cout << "----------Parent is left----------" << endl;
        parent->left = nodeOnLeft;
        nodeOnLeft->parent = parent;
    }
    //general case: node is on the right
    else if (node == parent->right){
        cout << "----------Parent is right----------" << endl;
        parent->right = nodeOnLeft;
        nodeOnLeft->parent = parent;
    }
    else{
        cout << "----------Error----------" << endl;
    }
}

//tree operation to find minimum value in the tree
rbt* MinInTree (rbt* headList){
    while(headList->nil != 'e') headList = headList->left;
    return headList->parent;
}

rbt* SearchNode (rbt* headList, int target){
    if(headList->value == target && headList->nil != 'e') {
        cout << "----------Found !-----------" << endl;
        return headList;
    }
    else if(headList->value < target && headList->nil != 'e'){
        SearchNode(headList->right, target);
    }
    else if(headList->value > target && headList->nil != 'e'){
        SearchNode(headList->left, target);
    }
    else if(headList->nil == 'e'){
        cout << "----------Cannot find the node----------" << endl;
        return NULL;
    }
    else cout << "---------unexpected output---------" << endl;
}

//to connect the delete-parent and delete-children
void TransPlant(rbt* deleteNode, rbt* connectNode){
    //conner case: the delete node is headList
    if(deleteNode->parent->nil == 's') {
        cout << "----------grandpa is starting guard-----------" << endl;
        deleteNode->parent->left = connectNode;
        connectNode->parent = deleteNode->parent;
        delete deleteNode;
    }
    //general case: the delete node is left side
    else if (deleteNode == deleteNode->parent->left){
        deleteNode->parent->left = connectNode;
        connectNode->parent = deleteNode->parent;
        delete deleteNode;
    }
    //general case: the delete node is right side
    else {
        deleteNode->parent->right = connectNode;
        connectNode->parent = deleteNode->parent;
        delete deleteNode;
    }
}

void DeleteNode(rbt* headList, rbt* deleteNode){
    char originalColor;
    rbt* doubleBlackNode;
    //node is on the left side
    //if(deleteNode == deleteNode->parent->left){
        //conner case the deleteNode has no right child(no smallest)
        if(deleteNode->right->nil == 'e'){
            cout << "----------deleteNode has no smallest------------" << endl;
            doubleBlackNode = deleteNode->left;
            originalColor = deleteNode->color;
            TransPlant(deleteNode, deleteNode->left);
            delete deleteNode->right;
            //cout << doubleBlackNode->value << endl;
        }
        //we can find smallest
        else{
            rbt* smallest = MinInTree(deleteNode->right);
            if(smallest == smallest->parent->right){
                cout << "----------smallest is right child----------" << endl;
                rbt* temp = smallest->parent;
                doubleBlackNode = smallest->right;
                originalColor = smallest->color;
                //succeesor the color
                smallest->color = temp->color;
                smallest->left = deleteNode->left;
                smallest->left->parent = smallest;
                TransPlant(deleteNode, smallest);
            }
            else{
                cout << "----------smallest is not right child----------" << endl;
                doubleBlackNode = smallest->right;
                originalColor = smallest->color;//succeesor the color
                //swap smallest with deleteNode
                deleteNode->value = smallest->value;
                TransPlant(smallest, smallest->right);
            }
        }
    CountSize(headList->left);
    if(originalColor == 'b') DeleteFixUpp (doubleBlackNode);
}

void DeleteFixUpp(rbt* doubleBlackNode){
    bool clear = false;
    if(doubleBlackNode->color == 'r') {
        doubleBlackNode->color = 'b';
        clear = true;
    }
    while(clear == false){
        //doubleBlackNode is on left side
        if(doubleBlackNode == doubleBlackNode->parent->left){
            cout << "----------doubleBlack is on left----------" << endl;
            //here is three terminal situation
            if(doubleBlackNode->parent->nil == 's') {
                cout << "----------root----------" << endl;
                doubleBlackNode->color = 'b';
                clear = true;
            }
            //PRBBB
            else if(doubleBlackNode->parent->color == 'r' && doubleBlackNode->parent->right->color == 'b'
                    && doubleBlackNode->parent->right->left->color == 'b'
                    && doubleBlackNode->parent->right->right->color == 'b'){
                cout << "----------PRBBB----------" << endl;
                doubleBlackNode->parent->color = 'b';
                doubleBlackNode->parent->right->color = 'r';
                clear = true;
            }
            //PNBNR
            else if(doubleBlackNode->parent->right->color == 'b' && doubleBlackNode->parent->right->right->color == 'r'){
                cout << "----------PNBNR----------" << endl;
                rbt* temp = doubleBlackNode->parent;
                temp->right->color = temp->color;
                temp->color = 'b';
                temp->right->right->color = 'b';
                RotateToLeft(temp->right, temp);
                clear = true;
            }
            //here is three need continue loop
            //PBBBB
            else if(doubleBlackNode->parent->color == 'b' && doubleBlackNode->parent->right->color == 'b'
                    && doubleBlackNode->parent->right->left->color == 'b'
                    && doubleBlackNode->parent->right->right->color == 'b'){
                cout << "----------PBBBB----------" << endl;
                doubleBlackNode->parent->right->color = 'r';
                doubleBlackNode = doubleBlackNode->parent;
            }
            //PNBRB
            else if( doubleBlackNode->parent->right->color == 'b'
                    && doubleBlackNode->parent->right->left->color == 'r'
                    && doubleBlackNode->parent->right->right->color == 'b'){
                cout << "----------PRBRB----------" << endl;
                doubleBlackNode->parent->right->left->color = 'b';
                doubleBlackNode->parent->right->color = 'r';
                RotateToRight(doubleBlackNode->parent->right->left, doubleBlackNode->parent->right);
            }
            //PBRBB
            else if(doubleBlackNode->parent->color == 'b' && doubleBlackNode->parent->right->color == 'r'
                    && doubleBlackNode->parent->right->left->color == 'b'
                    && doubleBlackNode->parent->right->right->color == 'b'){
                cout << "----------PBRBB----------" << endl;
                doubleBlackNode->parent->right->color = 'b';
                doubleBlackNode->parent->color = 'r';
                RotateToLeft(doubleBlackNode->parent->right, doubleBlackNode->parent);
            }
            else cout << "----------Unexpected output -----------" << endl;
        }
        //double black node is on right side
        else{
            cout << "----------doubleBlack is on right----------" << endl;
            //here is three terminal situation
            if(doubleBlackNode->parent->nil == 's') {
                cout << "----------root----------" << endl;
                doubleBlackNode->color = 'b';
                clear = true;
            }
            //PRBBB
            else if(doubleBlackNode->parent->color == 'r' && doubleBlackNode->parent->left->color == 'b'
                    && doubleBlackNode->parent->left->left->color == 'b'
                    && doubleBlackNode->parent->left->right->color == 'b'){
                cout << "----------PRBBB----------" << endl;
                doubleBlackNode->parent->color = 'b';
                doubleBlackNode->parent->left->color = 'r';
                clear = true;
            }
            //PNBNR
            else if(doubleBlackNode->parent->left->color == 'b' && doubleBlackNode->parent->left->left->color == 'r'){
                cout << "----------PNBNR----------" << endl;
                rbt* temp = doubleBlackNode->parent;
                temp->left->color = temp->color;
                temp->color = 'b';
                temp->left->left->color = 'b';
                RotateToRight(temp->left, temp);
                clear = true;
            }
            //here is three need continue loop
            //PBBBB
            else if(doubleBlackNode->parent->color == 'b' && doubleBlackNode->parent->left->color == 'b'
                    && doubleBlackNode->parent->left->left->color == 'b'
                    && doubleBlackNode->parent->left->right->color == 'b'){
                cout << "----------PBBBB----------" << endl;
                doubleBlackNode->parent->left->color = 'r';
                doubleBlackNode = doubleBlackNode->parent;
            }
            //PNBRB
            else if(doubleBlackNode->parent->left->color == 'b'
                    && doubleBlackNode->parent->left->left->color == 'b'
                    && doubleBlackNode->parent->left->right->color == 'r'){
                cout << "----------PBBRB----------" << endl;
                doubleBlackNode->parent->left->right->color = 'b';
                doubleBlackNode->parent->left->color = 'r';
                RotateToRight(doubleBlackNode->parent->left->right, doubleBlackNode->parent->left);
            }
            
            
            //PBRBB
            else if(doubleBlackNode->parent->color == 'b' && doubleBlackNode->parent->left->color == 'r'
                    && doubleBlackNode->parent->left->left->color == 'b'
                    && doubleBlackNode->parent->left->right->color == 'b'){
                cout << "----------PBRBB----------" << endl;
                doubleBlackNode->parent->left->color = 'b';
                doubleBlackNode->parent->color = 'r';
                RotateToRight(doubleBlackNode->parent->left, doubleBlackNode->parent);
            }
            else cout << "----------Unexpected output -----------" << endl;
        }
    }
    
}

//use reccur cos the head is not smallest
void PrintTree(rbt* headList){
    //base case: reach the ending guard
    if (headList->nil == 'e') {
        cout << "----end node is " << headList->parent->value << endl;
        return;
    }
    else{
        PrintTree(headList->left);
        cout << headList->value << "  " << headList->color << "  " << headList->size << endl;
        PrintTree(headList->right);
    }
}

//check the given rank and return the node
rbt* CheckByRank1(rbt* headList, int targetRank){
    int nowRank = headList->left->size + 1;
    if(nowRank == targetRank) return headList;
    //current Node is greater go left
    else if (nowRank > targetRank) return CheckByRank1(headList->left, targetRank);
    //current node is smaller go right
    else return CheckByRank1(headList->right, targetRank - nowRank);
}

rbt* CheckByRank(rbt* headList, int targetRank){
    bool found = false;
    int r;
    while(found != true){
        r = headList->left->size + 1;
        if(r > targetRank) {
            headList = headList->left;
        }
        else if (r < targetRank){
            targetRank = targetRank - r;
            headList = headList->right;
        }
        else {
            found = true;
        }
    }
    return headList;
}

//here is go up
int DeterRank1(rbt* headList, rbt* targetNode){
    int rank = targetNode->left->size + 1;
    rbt* temp = targetNode;
    while(temp->parent->nil != 's'){
        //if targetNode is on the right that means above it there are some smaller node
        if (temp == temp->parent->right) rank = rank + temp->parent->left->size + 1;
        temp = temp->parent;
    }
    return rank;
}

//here is going down
int DeterRank(rbt* headList, rbt* targetNode){
    if(targetNode->value == headList->value) return targetNode->left->size + 1;
    else if(targetNode->value < headList->value){
        return DeterRank(headList->left, targetNode);
    }
    else return targetNode->left->size + 1 + DeterRank(headList->right, targetNode);
}

int main(int argc, char** argv) {
    rbt* newNode = NewNode();
    rbt* newNode1 = NewNode();
    //create the headList with one starting guard and ending guard
    rbt* headList = newNode;
    headList->nil = 's';
    headList->left = newNode1;
    newNode1->parent = headList;
    
    //for create a non-repetable ramdom input
    srand(434);
    int array[10];
    int size = 0;
    
    while(size < 10){
        int j = rand() % 17;
        array[size] = j;
        newNode = NewNode(array[size]);
        InsertNode(headList, newNode);
        size++;
    }
    for (int i = 0; i < 10; i++)  cout << array[i] << " ";
    cout << endl;
    
    
    cout << CheckByRank(headList->left, 4)->value << endl;
    cout << DeterRank(headList->left, SearchNode(headList->left, 6)) << endl;
    
    
    
    /*for(int i = 0; i < 10; i++) {
        DeleteNode(headList, SearchNode(headList->left, array[i]));
        cout << "----------deleting " << array[i] << "----------" << endl;
        cout << "The root is " << headList->left->value << endl;
        PrintTree(headList->left);
        cout << endl;
    }*/
    
    
    
    

    cout << "-----------Printing the tree-----------" << endl;
    cout << "The root is " << headList->left->value << endl;
    PrintTree(headList->left);
    cout << "-----------Finishing printing-----------" << endl;
     
    return 0;
}

