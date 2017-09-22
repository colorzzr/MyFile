ifstream inputstream;
inputstream.open("inputFile.txt");
if(!inputstream.is_open())  cout << "fail to open the inputstream" << endl;

ofstream outputstream;
outputstream.open("outputFile.txt");
if(!outputstream.is_open()) cout << "fail to open the outputstream" << endl;

struct linkList{
	linkList* next;
	linkList* previous;
	int gardien;
}

struct BT{
	BT* left;
	BT* right;
	BT* parent;
	int gardien;
}

int* test(int* array){
	array[0] = 1;
	return array;
}

int main(int argc, char const *argv[]){	
	int array[3] = {0, 1, 2};
	int* newArr;
	newArr = test(array);
	for(int i = 0; i < 3; i++){
		cout << array[i] << endl;
	}


	return 0;
}