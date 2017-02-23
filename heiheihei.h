/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heiheihei.h
 * Author: user
 *
 * Created on February 21, 2017, 12:06 PM
 */

#ifndef HEIHEIHEI_H
#define HEIHEIHEI_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEIHEIHEI_H */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


//Function to get the average value of array
double Average (double inputNum[], int numVals) {
	int i;
	double average = 0;
	for (i = 0; i < numVals; i++) {
		//add together
		average = average + inputNum[i];
	}
	average = average / numVals;
	return average;
}

//find the space in char and return thenumber of space and where it is
int CheckSpace(char inputChar[],int length) {
	int number = 0;
	for (int i = 0; i < length; i++) {
		if (isspace(inputChar[i])) {
			printf("%d", i);
			number++;
		}
	}
	return number;
}

//find the prime number 
bool IsPrime(int input) {
	bool result = true;
	if (input != 2) {
		
		//test the division for every number
		for (int j = 2; j <= (input / 2); j++) {
			if (input % j == 0) {
				result = false;
				break;
			}
		}
	}
	return result;
}

//find the prime number after
void PrimeAfter(int *prime) {
	int value;
	value = *prime;
	if (value == 2) {
		value = value + 1;
	}
	while (IsPrime(value) == false) {
		value = value + 1;
	}

	*prime = value;
	return;
}

/***********************************
 * input 3 would print ABC BCA CAB *
 ***********************************/
void PrintChar(int a) {
	for (int row = 0; row < a; row++) {
		for (int col = 0; col < a; col++) {
			
			//repeat to the first letter
			printf("%c", 'A' + ((col + row) % a));
		}
		printf("\n");
	}
}

//function can sort out the number
void Rearrange(int numArray[], int numVal) {
	int temp;
	int i;
	int j = numVal;
	
	//move out the largest number
	while (j > 0) {
		
		//switch the number to left if it is greater
		for (i = 0; i < (j - 2); i++) {
			temp = numArray[i];
			if (numArray[i + 1] <= numArray[i]) {
				temp = numArray[i + 1];
				numArray[i + 1] = numArray[i];
				numArray[i] = temp;
			}
		}
		j--;
	}

	for (i = 0; i < numVal; i++) {
		printf("%d\n", numArray[i]);
	}
}


/*//this is a dynamic memory allocation
void ChooseTheTypeOfMemory(double pass1, double *newPass1Location, char pass2, char *newPass2Location) {
	int type;
        int extra;
        
        //ask for the type
	//printf("please enter your type (1 for double and int, 2 for char)");
	//scanf(" &c", &type);
        
        //branch loop
	//if (type == 1) {
            printf("please enter the extra space you want:");
            scanf("%d", &extra);
            newPass1Location = (double*)malloc(10 * sizeof(double));
            printf("%d", sizeof(newPass1Location));
	}
        else{
            //printf("please enter the extra space you want:");
            scanf("%d", &extra);
            //newPass1Location = (double*)malloc(extra * sizeof(double));
            printf(" %d", sizeof(newPass1Location));
        }
        return ;
}*/

//happy function to guess the secrete number
void GuessSecreteNum (){
    int guess;
    int min, max;
    bool result = false;
   
    //ask for the max and min value 
    printf("please enter your min and max value: ");
    scanf("%d %d", &min, &max);
    
    /***************************************************************
     * check the value in the interval min ~ min + (min + max) / 2 *
     * or in the interval (min + max) / 2 ~ max                    *
     ***************************************************************/
    while (result != true){
        printf("is your secrete number in the %d ~ %d (1 for yes 0 for no)?", min, ((max - min) / 2) + min);
        scanf("%d", &guess);
        
        //yes means number is in first interval no for second interval
        if (guess == 0){
            min = ((max - min) / 2) + min + 1;
        }
        else if (guess == 1){
            max = ((max - min) / 2) + min;
        }
        
        //check for the secrete number
        if (min == max){
            result = true;
        }
    
    }
    
    printf("the secrete number is %d", min);
}

//this function would define the Pi
void DefinePi (){
    double arc1 = 0;
    double arc2 = 0;
    double x1 = 1 / 5.0;
    double x2 = 1 / 239.0;
    int j;
    
    //Pi = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0)
    //arctan(x) = x-x^3/3 + x^5/5.....x^301/301
    
    for (int i = 1,j = 0; i <= 301; i += 2, j++){
        arc1 = arc1 + (pow(x1,i) / i)*pow(-1,j);
        
    }
    
    for (int i = 1,j = 0; i <= 301; i += 2,j++){
        arc2 = arc2 + (pow(x2,i) / i)*pow(-1,j);
        
    }
    
    arc1 = 16 * arc1 - 4 * arc2;
    printf("Pi is %.10lf", arc1);
    
    return;
}

//this trial function just do it
void Print10repeteated (){
    int j;
    scanf("%d", &j);
    for (int i = 0; i < 10; i++){
        for (int x = 0; x < 10; x++, j++){
            printf("%d", (j + i) % 10);
        }
        printf("\n");
    }
}

