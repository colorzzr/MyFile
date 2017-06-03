/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on May 20, 2017, 8:15 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;

/*
 * 
 */
class nameList{
    private:
        char *name;
        int month;
        int day;
        nameList *next;
    public:
        //constructor for standard
        nameList(char tempName[], int tempMonth, int tempDay);
        //constructor for default
        nameList();
        //link to next
        void LinkNext(nameList *previous, nameList *current, nameList *next);
        //access to private data
        void Print();
        //go to next node
        nameList* GoNext(nameList *now);
        //compare two name
        nameList* CompareAndInsert(nameList *node1, nameList *node2);
        //for general case
        nameList* CompareAndInsert(nameList *headList, nameList *previous, nameList* next);
};

/********************************************
 * malloc the name                          *
 * and copy the day and month to the class  *
 ********************************************/
nameList::nameList(char tempName[], int tempMonth, int tempDay){
    name = (char*)malloc(sizeof(char)*(strlen(tempName)+1));
    strcpy(name, tempName);
    month = tempMonth;
    day = tempDay;
    next = NULL;
    cout << "Data loaded" << endl;
}

//print out the private data
void nameList::Print(){
    cout << "The name: " << name << " " << endl
         << "Birthday: " << month << " " << day << endl << endl;
  
}

//use link list
void nameList::LinkNext(nameList* previous, nameList* current, nameList* next){
    previous->next = current;  
    current->next = next;
}

//go to next node
nameList* nameList::GoNext(nameList* now){
    return now->next;
}

//for conner case1
nameList* nameList::CompareAndInsert(nameList* node1, nameList* node2){
    if(strcmp(node1->name,node2->name) > 0){
        node1->LinkNext(node2, node1, node2->next);
        //just return headList
        return node2;
    }
    else {
        node1->LinkNext(node1, node2, node1->next);
        return node1;
    }
}

//general case
nameList* nameList::CompareAndInsert(nameList* headList, nameList* node1, nameList* inNode){
    int count = 0;
    //assume there are two in list now
    nameList* previous = headList;
    nameList* current = headList->next;
    
    //remember to look forward
    //if insert node have to place in the front of list
    if(strcmp(previous->name, inNode->name) > 0){
        inNode->next = headList;
        headList = inNode;
    }
    else{
        //find right place
        while(strcmp(current->name, inNode->name) < 0 ){
            current = current->next;
            previous = previous->next;
            if(current == NULL) break;
        }
        //now insert Node
        previous->next = inNode;
        inNode->next = current;
    }
    return headList;
}

int main(int argc, char** argv) {
    nameList *headList = NULL;
    char action;
    /****************************
     * same as lab8 and lab9    *
     * go left portal is        *
     * ~/lab/lab8 or lab9       *
     * I -> Insert a node       *
     * P -> print out the list  *
     ****************************/

    do{
        cout << "What is the command(I, P, Q)?" ;
        cin >> action;
        //insert new node
        if(action == 'i'){
            nameList *newNode;
            char temName[50];
            int month, day;
            cout << "please enter your name and birth:";
            cin >> temName >> month >> day;
            //new is new kind of malloc?
            newNode = new nameList(temName, month, day);
            //old type of compare see lab 8
            if(headList == NULL){
                headList = newNode;
            }
            //corner case1 there are two in list 
            else if (headList->GoNext(headList) == NULL){
                headList = headList->CompareAndInsert(headList, newNode);
            }
            //general case: more than two in list
            else {
                headList = headList->CompareAndInsert(headList, headList, newNode);
                
            }
            //change to hash table later
            
        }
        //accesss to public function to print out
        else if (action == 'p'){
            while (headList != NULL){
                headList->Print();
                headList = headList->GoNext(headList);
            }
        }
        else{
            cout << "plz enter right command" << endl;
        }
    
    }while(action != 'q');
    
    cout << "program exit!";
    
    return 0;
}

