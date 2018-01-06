#include <iostream>
#include <cstdlib>
#include "BST.h"

BST::BST(){
	//starting guard
	headList = new BSTNode;
	//forming ending guard
	headList->setLeft(new BSTNode);
	headList->getLeft()->setParent(headList);
	headList->setRight(new BSTNode);
	headList->getRight()->setParent(headList);
}

BST::~BST(){
	delete headList;
}

//----------------------------------------------get function------------------------------------------

BSTNode* BST::getHead(){
	return headList;
}

//----------------------------------------------operation funciton-----------------------------------
void BST::printTree(BSTNode* head){
	if(head->getGuard() == -1) return;
	else{
		printTree(head->getLeft());
		head->print();
		printTree(head->getRight());
	}
}

// if left return true else false
bool BST::checkLOrR(BSTNode* targetPlace){
	if(targetPlace == targetPlace->getParent()->getLeft()) return true;
	else return false;
}


void BST::insertNode(BSTNode* insertOne){
	BSTNode* temp = headList->getLeft();
	while(1){
		//find right place
		if(temp->getGuard() == -1){
			//left child
			if(checkLOrR(temp)){
				BSTNode* parent = temp->getParent();
				//delete duplicated guard
				delete parent->getLeft();
				//double link
				parent->setLeft(insertOne);
				insertOne->setParent(parent);
			}
			//right child
			else{
				BSTNode* parent = temp->getParent();
				//delete duplicated guard
				delete parent->getRight();
				//double link
				parent->setRight(insertOne);
				insertOne->setParent(parent);
			}
			return;
		}
		else if(temp->getKey() < insertOne->getKey()) temp = temp->getRight();
		else temp = temp->getLeft();
	}

}

void BST::deleteNode(BSTNode* targetNode){
	//conner case there is no left childen
	if(targetNode->getLeft()->getGuard() == -1){
		delete targetNode->getLeft();

		//check the LORchildren
		if(checkLOrR(targetNode)){
			BSTNode* temp = targetNode->getParent();
			//double link
			temp->setLeft(targetNode->getRight());
			temp->getLeft()->setParent(temp);
			delete targetNode;
		}
		else{
			BSTNode* temp = targetNode->getParent();
			//double link
			temp->setRight(targetNode->getRight());
			temp->getRight()->setParent(temp);
			delete targetNode;
		}
		
	}
	else{
		BSTNode* temp = findMax(targetNode->getLeft());
		targetNode->setKey(temp->getKey());
		//left child of target
		if(checkLOrR(temp)){
			targetNode->setLeft(temp->getLeft());
			targetNode->getLeft()->setParent(targetNode);
			delete temp->getRight();
			delete temp;
		}
		else{
			BSTNode* parent = temp->getParent();
			parent->setRight(temp->getLeft());
			parent->getRight()->setParent(parent);
			delete temp->getRight();
			delete temp;

		}
	}
}

BSTNode* BST::findMax(BSTNode* startNode){
	while(1){
		if(startNode->getGuard() == -1) return startNode->getParent();
		else startNode = startNode->getRight();
	}
}
BSTNode* BST::findMin(BSTNode* startNode){
	while(1){
		if(startNode->getGuard() == -1) return startNode->getParent();
		else startNode = startNode->getLeft();
	}
}

BSTNode* BST::findNode(int key){
	BSTNode* temp = headList->getLeft();
	while(1){
		if(temp->getGuard() == -1){
			cout << "Error: cannot find node" << endl;
			return NULL;
		}
		//find the node
		else if(temp->getKey() == key)return temp; 
		//else go left or right
		else if(temp->getKey() < key) temp = temp->getRight();
		else temp = temp->getLeft();
	}
}


void BST::generateTree(int size, int seed){
	srand(seed);
	while(size > 0){
		BSTNode* newNode = new BSTNode(rand() % 50);
		insertNode(newNode);
		size--;
	}
}

int BST::checkKey(int value){
	if(headList->getLeft()->getGuard() == -1) return 0;
	else return headList->getLeft()->checkKey(value);
}

void BST::printPreorder(BSTNode* node){
	if(node->getGuard() == -1) return;
	node->print();
	printPreorder(node->getLeft());
	printPreorder(node->getRight());
}

bool BST::isBST(){
	//headList->getLeft()->print();
	return headList->getLeft()->checkBST(headList->getLeft());
}

void BST::reverseOrder(BSTNode* node){
	// if(node->getGuard() == -1) return;
	// reverseOrder(node->getRight());
	// node->print();
	// reverseOrder(node->getLeft());
	// return;
	if(node->getRight()->getGuard() != -1) reverseOrder(node->getRight());
	node->print();
	if(node->getLeft()->getGuard() != -1) reverseOrder(node->getLeft());
}
