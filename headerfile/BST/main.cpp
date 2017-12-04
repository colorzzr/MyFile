#include <iostream>
#include "BST.h"

using namespace std;

void insertNode(BSTNode* &headlist){

}

int main(int argc, char const *argv[]){
	BST* tree = new BST;
	//tree.getHead()->print();
	BSTNode* newNode = new BSTNode(1);
	tree->insertNode(newNode);
	tree->printTree(tree->getHead()->getLeft());



	return 0;
}