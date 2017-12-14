#include <iostream>
#include "BST Node.h"

using namespace std;

int BSTNode::numberOfNode = 0 ;

//--------------------------------------condestructor--------------------------------
BSTNode::BSTNode(){
	numberOfNode++;
	guard = -1;
	key = -32767;
}
BSTNode::BSTNode(int _key){
	key = _key;
	guard = 1;
	left = new BSTNode;
	left->parent = this;
	right = new BSTNode;
	right->parent = this;
	parent = NULL;
	numberOfNode++;
}
BSTNode::~BSTNode(){
	numberOfNode--;
	//cout << 11 << endl;
	if(left != NULL) delete left;
	if(right != NULL) delete right;
	cout << "hhh" << endl;
}

//----------------------------------------get fucntion---------------------------------
int BSTNode::getKey(){
	return key;
}

BSTNode* BSTNode::getLeft(){
	return left;
}

BSTNode* BSTNode::getRight(){
	return right;
}

BSTNode* BSTNode::getParent(){
	return parent;
}

int BSTNode::getGuard(){
	return guard;
}
//----------------------------------set function-----------------------------------
void BSTNode::setKey(int _key){
	key = _key;
}

void BSTNode::setLeft(BSTNode* _left){
	left = _left;
}

void BSTNode::setRight(BSTNode* _right){
	right = _right;
}

void BSTNode::setParent(BSTNode* _parent){
	parent = _parent;
}

void BSTNode::setGuard(int _guard){
	guard = _guard;
}
//--------------------------------------other--------------------------------------
void BSTNode::print(){
	cout << "Key is " << key << endl;
	//cout << "Guard is " << guard << endl;
	cout << "number of node: " << numberOfNode << endl;
	cout << endl;
}

int BSTNode::checkKey(int value){
	//leave
	if(left->getGuard() == -1 && right->getGuard() == -1) return (key == value);
	//has right child
	else if(left->getGuard() == -1 && right->getGuard() != -1) return (key == value) + right->checkKey(value);
	//only has left child
	else if(left->getGuard() != -1 && right->getGuard() == -1) return (key == value) + left->checkKey(value);
	//node
	else return (key == value) + right->checkKey(value) + left->checkKey(value);
}

BSTNode* BSTNode::findMax(BSTNode* startNode){
	while(1){
		if(startNode->getGuard() == -1) return startNode->getParent();
		else startNode = startNode->getRight();
	}
}
BSTNode* BSTNode::findMin(BSTNode* startNode){
	while(1){
		if(startNode->getGuard() == -1) return startNode->getParent();
		else startNode = startNode->getLeft();
	}
}

//always remeber follow the pointer
//not use private data member directly
bool BSTNode::checkBST(BSTNode* root){
	if(root->getGuard() == -1) return true;
	BSTNode* max = findMax(root->getLeft());
	//max->print();
	BSTNode* min = findMin(root->getRight());
	//cout << key << endl;
	return (root->getKey() >= max->getKey()) && (root->getKey() <= min->getKey()) 
			&& checkBST(root->getLeft()) && checkBST(root->getRight());
	// return (key >= max->getKey()) && (key <= min->getKey()) &&
	// 		checkBST(this->getLeft()) && checkBST(this->getRight());
}