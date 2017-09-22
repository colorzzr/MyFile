#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream inputstream;
	char temp;
	inputstream.open("PracticeInput.txt");
	//while(!inputstream.eof()){
		temp = inputstream.get();
		//cout << temp;
		if(temp == '\n') cout << "hhhh" << endl;
	//}
	return 0;
}