#include <iostream>

using namespace std;

class BT{
private:
	int key;
public:
	BT(int input){
		key = input;
	}
	int getKey() {return key;}
	BT* left;
	BT* right;
};

bool checkBT(BT* head, int min, int max){
	if(head == NULL) return true;
	else if(head->getKey() > min && head->getKey() < max){
		return checkBT(head->left, min, head->getKey()) && checkBT(head->right, head->getKey(), max);
	}
	else return false;
}


int main(int argc, char const *argv[]){
	BT* head = new BT(2);
	BT* new1 = new BT(1);
	BT* new2 = new BT(3);
	BT* new3 = new BT(5);
	head->left = new1;
	head->right = new2;
	new2->right = new3;

	//BT* new3 = new BT(1);
	if(checkBT(head, -9999, 9999)) cout << "BT!" << endl;
	else cout << "not BT!" << endl;
	


	return 0;
}