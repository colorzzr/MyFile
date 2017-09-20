#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int RANGER_UPPER = 255;
const int RANGE_LOWER = 0;


bool checkIP(int input){
	if(input > 255 || input < 0) {
		cout << "Invalid" << endl;
		return false;
	}
	else{
		 cout << "valid" << endl;
		 return true;
	}
}

void filterIP(string IP){
	//for initial!!!!!!!!!!!!!!!!!!!!!
	int filtered[4] = {0, 0, 0, 0};
	int index = 0, power = 0;
	int length = IP.size();
	for(int i = length - 1; i >= 0 ; i--){
		//move to next series
		if(IP[i] == '.') {
			checkIP(filtered[index]);
			index ++;
			i--;
			power = 0;
		}
		filtered[index] = filtered[index] + (IP[i] - '0') * pow(10, power);
		power++;
	}
	checkIP(filtered[3]);

	for (int i = 0; i < 4; i++){
		cout << filtered[i] << '.';
	}
	cout << endl;
	return;
}


int main(int argc, char** argv){
	
	string IP = "235.999.454.232";
	filterIP(IP);

}