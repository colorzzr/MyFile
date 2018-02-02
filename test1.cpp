#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int test(int* array, int start, int end, int target){
	//if(target > array[end] || target < array[start]) return 0;
	int mid = (start + end)/2;
	if(start == end || start == end - 1){
		if(abs(target - array[end]) > abs(target - array[start]))return start;
		else return end;
	}
	cout << start << " " << end << endl;
	if(target < array[end] && target > array[mid])return test(array, mid, end, target);
	else return test(array, start, mid, target);
	//return test(array, start, (end + start)/2, target) + test(array, (end + start)/2, end, target);

}

class DBST{
private:
	int x;
	int y;
	DBST* leftTop;
	DBST* rightTop;
	DBST* leftBot;
	DBST* rightBot;
public:
	DBST(){
		x = 0;
		y = 0;
		leftTop = NULL;
		rightTop = NULL;
		leftBot = NULL;
		rightBot = NULL;
	} 
	DBST(int x_, int y_){
		x = x_;
		y = y_;
		leftTop = NULL;
		rightTop = NULL;
		leftBot = NULL;
		rightBot = NULL;
	}
	~DBST(){
		if(leftTop != NULL)delete leftTop;
		if(rightTop != NULL)delete rightTop;
		if(leftBot != NULL)delete leftBot;
		if(rightBot != NULL)delete rightBot;		
	}
	int getX(){return x;}
	int getY(){return y;}
	DBST* getLeftTop(){return leftTop;}
	DBST* getRightTop(){return rightTop;}
	DBST* getLeftBot(){return leftBot;}
	DBST* getRightBot(){return rightBot;}

	void setX(int x_){x = x_;}
	void setY(int y_){y = y_;}
	void setLeftTop(DBST* leftTop_){leftTop = leftTop_;}
	void setRightTop(DBST* rightTop_){rightTop = rightTop_;}
	void setLeftBot(DBST* leftBot_){leftBot = leftBot_;}
	void setRightBot(DBST* rightBot_){rightBot = rightBot_;}
};

void printNode(DBST* node){
	cout << "x is " << node->getX() << endl;
	cout << "y is " << node->getY() << endl;
	cout << "-----------------------" << endl;
}


void printDBST(DBST* root){
	if(root->getLeftTop() != NULL) printDBST(root->getLeftTop());
	if(root->getRightTop() != NULL) printDBST(root->getRightTop());
	printNode(root);
	if(root->getLeftBot() != NULL) printDBST(root->getLeftBot());
	if(root->getRightBot() != NULL) printDBST(root->getRightBot());
}

void insert(DBST* root, DBST* newNode){
	while(1){
		//left half
		if(newNode->getX() < root->getX()){
			//left bot
			if(newNode->getY() < root->getY()){
				//no children
				if(root->getLeftBot() == NULL){
					root->setLeftBot(newNode);
					cout << 444 << endl;
					break;
				}
				else root = root->getLeftBot();
			}
			//left top
			else{
				//no children
				if(root->getLeftTop() == NULL){
					root->setLeftTop(newNode);
					cout << 333 << endl;
					break;
				}
				else root = root->getLeftTop();
			}
		}
		//right half
		else{
			//right bot
			if(newNode->getY() < root->getY()){
				//no children
				if(root->getRightBot() == NULL){
					root->setRightBot(newNode);
					cout << 222 << endl;
					break;
				}
				else root = root->getRightBot();
			}
			//right top
			else{
				//no children
				if(root->getRightTop() == NULL){
					root->setRightTop(newNode);
					cout << 111 << endl;
					break;
				}
				else root = root->getRightTop();
			}
		}
	}
}


DBST* findClosetPoint(DBST* root, DBST* target){
	while(1){
		//letf half
		if(target->getX() < root->getX()){
			//left bot
			if(target->getY() < root->getY()){
				if(root->getLeftBot() == NULL) return root;
				else root = root->getLeftBot();
			}
			//left top
			else{
				if(root->getLeftTop() == NULL) return root;
				else root = root->getLeftTop();
			}
		}
		else if (target->getX() < root->getX() && target->getY() < root->getY()) return root;
		//right half
		else{
			//right bot
			if(target->getY() < root->getY()){
				if(root->getRightBot() == NULL) return root;
				else root = root->getRightBot();
			}
			//right top
			else{
				if(root->getRightTop() == NULL) return root;
				else root = root->getRightTop();
			}
		}
	}
}



int main(int argc, char const *argv[]){
	DBST* root = new DBST(1,2);

	DBST* newNode = new DBST(2,2);
	insert(root, newNode);

	newNode = new DBST(0,0);
	insert(root, newNode);

	newNode = new DBST(12,11);
	insert(root, newNode);

	newNode = new DBST(7,10);
	insert(root, newNode);

	newNode = new DBST(1, 100);
	insert(root, newNode);

	newNode = new DBST(99, 7);
	insert(root, newNode);



	printDBST(root);

	newNode = new DBST(50, 50);

	DBST* test1 =  findClosetPoint(root, newNode);
	cout << "find !" << endl;
	printDBST(test1);

	delete newNode;

	delete root;



	return 0;
} 