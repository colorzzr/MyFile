#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string str1 = "ac";
string str2 = "abb";
int row, col;
void printMap(int** checkMap){
	for(int i = 0; i < row ; i++){
		for(int j = 0; j< col ; j++){
			cout << checkMap[i][j] << ' ';
		}
		cout << endl;
	}
}

/****************************************
 * find the minial operation in 3 of 8	*
 * B B X	B is checking place			*
 * B C X	C is current place			*
 ****************************************/
int searchMinIn3Direction(int** checkMap, int row, int col){
	int min = checkMap[row - 1][col];
	if(checkMap[row - 1][col - 1] < min) min = checkMap[row - 1][col - 1];
	if(checkMap[row][col - 1] < min) min = checkMap[row][col - 1];
	return min;
}

//using dynamic programing to check out all block
void DPCheck(int** checkMap){
	for(int i = 1; i < row ; i++){
		for(int j = 1; j< col ; j++){
			//find minial
			int min = searchMinIn3Direction(checkMap, i, j);
			/****************************************************
			 * if the string characters are equaled not change	*
			 * because we only need previous operaiton to get	*
			 * current string									*
			 ****************************************************/
			if(str1[i] == str2[j]) checkMap[i][j] = min;
			//else add 1 for 1 operation
			else checkMap[i][j] = min + 1;
		}
	}
}

int main(int argc, char const *argv[]){
	cin >> str1 >> str2;
	row = str1.length() + 1;
	col = str2.length() + 1;

	int** checkMap = new int*[row];
	for(int i = 0; i < row; i++) checkMap[i] = new int [col];
	for(int i = 0; i < row ; i++){
		for(int j = 0; j< col ; j++){
			if(i == 0) checkMap[i][j] = j;
			else if(j == 0) checkMap[i][j] = i;
			else checkMap[i][j] = 0;
		}
	}
	DPCheck(checkMap);
	printMap(checkMap);

	for(int i = 0; i < row; i++) delete [] checkMap[i];
	delete [] checkMap;

	return 0;
} 