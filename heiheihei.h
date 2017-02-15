
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


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