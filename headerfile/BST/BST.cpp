#include <iostream>

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
		else if(temp->getKey() < insertOne->getKey()) temp = temp->getLeft();
		else temp = temp->getRight();
	}

}