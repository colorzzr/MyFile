
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
void ChooseTheTypeOfMemory(double pass1, double *newPass1Laction, char pass2, char *newPass2Location) {
	char type;

	printf("please enter your type (d for double and int, c for char");
	scanf("&c", &type);
	if (type == 'd') {
		

	}


}*/