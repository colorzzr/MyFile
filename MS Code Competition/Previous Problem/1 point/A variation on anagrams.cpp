#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


//igore the space
int checkLength(string input){
	int count = 0;
	int i = 0;

	while(input[i] != '\0'){
		//get fide of space
		if(!isspace(input[i])){
			count++;
		}
		i++;
	}
	return count;
}

bool checkPattern(string input1, int length1, string input2, int length2){
	if (length2 != length1) return false;

	length1 = input1.size();
	length2 = input2.size();
	//double for-loop to scan two arrays
	for(int i = 0; i < length1; i++){
		//igore the space
		while(isspace(input1[i])) i++;
		bool noFoundSameChar = true;
		for(int j = 0; j < length2; j++){

			//igore the space
			while(isspace(input2[j])) j++;
			if(input1[i] == input2[j] || input1[i] == toupper(input2[j]) || input1[i] == tolower(input2[j])){
				//potientially hiden
				input2[j] = '0';
				noFoundSameChar = false;
				cout << input2 << endl;
				break;
			}
		}

		//if there is no macthing char
		if (noFoundSameChar == true) {
			cout << "Cant find " << input1[i] << endl;
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv){
	string input1 ("Substitute Focal Awe"), input2 = "Associate But Flu Wet";
    int length1, length2;
    int i = 0;
    //while(i < (argc - 1)){
    	//input1 = argv[i];
    	//i++;
    	//input2 = argv[i];
    	//i++;

    	cout << input1 << endl;
    	cout << input2 << endl;

    	length1 = checkLength(input1);
    	length2 = checkLength(input2);

    	cout << length1 << endl;
    	cout << length2 << endl;

		if(checkPattern(input1, length1, input2, length2)){
			cout << "find pattern" << endl;
		}
		else{
			cout << "invalide" << endl;
		}

	//}
	
	return 0;
}