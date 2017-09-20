#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;



/************************************************
 * there problem is the '0' at the head of list *
 ************************************************/
void filterPhoneNum (string phoneNum){
	bool invalid = false;
	//for origin
	int i = phoneNum.size() - 1;
	//for filtered
	int j = 10;
	//origin one is shorter than filter abort
	if(i < j) {
		cout << "Fleshling follow-up needed" << endl;
		return;
	}
	char filtered[11];
	//just leave index[0] for surely '1' at head
	while(j != 0){
		if(isdigit(phoneNum[i])){
			filtered[j] = phoneNum[i];
			//go from tail to head
			j--;
		}
		//for letter input
		else if (phoneNum[i] == 'A' || phoneNum[i] ==  'B' || phoneNum[i] ==  'C'){
			filtered[j] = '2';
			j--;
		}
		else if (phoneNum[i] == 'D' || phoneNum[i] ==  'E' || phoneNum[i] ==  'F'){
			filtered[j] = '3';
			j--;
		}
		else if (phoneNum[i] == 'G' || phoneNum[i] ==  'H' || phoneNum[i] ==  'I'){
			filtered[j] = '4';
			j--;
		}
		else if (phoneNum[i] == 'J' || phoneNum[i] ==  'K' || phoneNum[i] ==  'L'){
			filtered[j] = '5';
			j--;
		}
		else if (phoneNum[i] == 'M' || phoneNum[i] ==  'N' || phoneNum[i] ==  'O'){
			filtered[j] = '6';
			j--;
		}
		else if (phoneNum[i] == 'P' || phoneNum[i] ==  'Q' || phoneNum[i] ==  'R' || phoneNum[i] ==  'S'){
			filtered[j] = '7';
			j--;
		}
		else if (phoneNum[i] == 'T' || phoneNum[i] ==  'U' || phoneNum[i] ==  'V' || phoneNum[i] ==  'W'){
			filtered[j] = '8';
			j--;
		}
		else if (phoneNum[i] == 'X' || phoneNum[i] == 'Y' || phoneNum[i] == 'Z'){
			filtered[j] = '9';
			j--;
		}
		
		i--;
	}

	//check for longer input
	if(i > 0) {
		cout << "Fleshling follow-up needed"  << endl;
		return;
	}

	filtered[0] = '1';
	cout << filtered << endl;
}


int main(int argc, char** argv){
	string phoneNum = "1 (123) 555-0100 X123";
 

	filterPhoneNum(phoneNum);
	
	return 0;
}