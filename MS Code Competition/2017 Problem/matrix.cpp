#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//reading input
//take transpose
//detect symatric


void readingMatrix(int &dimensions){
	ifstream inputstream;
	char temp = 'a';
	inputstream.open("PracticeInput.txt");
	if(!inputstream.is_open())  cout << "fail to open the inputstream" << endl;
	//to check the dimensions
	while(temp != ';'){
		if(temp == ',') dimensions++;
		inputstream >> temp;
		//cout << temp << endl;
		//cout << temp << endl;
	}
	dimensions ++;
	inputstream.close();
	inputstream.open("PracticeInput.txt");
	//cout << dimensions << endl;
	
	int matrix[dimensions][dimensions];
	for(int i = 0; i < dimensions ; i++){
		for(int j = 0; j < dimensions; j++){
			matrix[i][j] = 0;
			//cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int tempy;
	//cout << "test" << endl;
	while(!inputstream.eof()){
	int row = 0, col = 0;
	while(row < dimensions){
		inputstream >> tempy;
		inputstream >> temp;
		//if(inputstream.fail()) inputstream.clear();
		//cout << isdigit(temp) << endl;
		matrix[row][col] = tempy;
		//cout << matrix[row][col] << endl;
		col++;
		
		if (temp == ';') {
			row++;
			col = 0;
			//cout << "hhhh" << endl;
		}
		//do nothing
		//cout << "temp " << temp << "tempy " << tempy << endl;
		//cout << endl;
		//if(temp == '\n') break;

	}

	/*for(int i = 0; i < dimensions ; i++){
		for(int j = 0; j < dimensions; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	//int temppy;
	for(int row = 0; row < dimensions; row++){
		for(int col = row + 1; col < dimensions; col++){
			if(matrix[row][col] == matrix[col][row]){
				cout << "Symmetric" << endl;
				break;				
			}
			else{
				cout << "Not symmetric" << endl;
				break;
			}
		}
	}
	}

}



int main(int argc, char const *argv[]){	
	int dimensions = 0;
	//int matrix[3][3] = {{1,2,3},{2, 3, 4 },{3, 4, 5}};
	
	readingMatrix(dimensions);	
	//if(takeTranspose(matrix, dimensions)) cout << "Symmetric" << endl;
	//else cout << "Not symmetric" << endl;
	//cout << dimensions << endl;

	/*for(int i = 0; i < dimensions ; i++){
		for(int j = 0; j < dimensions; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}