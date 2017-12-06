#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

void insertNode(BSTNode* &headlist){

}

int main(int argc, char const *argv[]){
	BST* tree = new BST;
	int array[10];
	//tree.getHead()->print();
	srand(101);
	for(int i = 0; i < 10; i++){
		array[i] = rand() % 90;
		cout << array[i] << endl;
	}


	for(int i = 0; i < 10; i++){
		BSTNode* newNode = new BSTNode(array[i]);
		tree->insertNode(newNode);
	}
	
	for(int i = 0; i < 10; i++){
		BSTNode* temp = tree->findNode(array[i]);
		tree->deleteNode(temp);
	}
	

	tree->printTree(tree->getHead()->getLeft());

	return 0;
}