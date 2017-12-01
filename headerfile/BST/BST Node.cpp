#include <iostream>
#include "BST Node.h"

using namespace std;

int numberOfNode = 0 ;

//--------------------------------------condestructor--------------------------------
BSTNode::BSTNode(){

}
BSTNode::BSTNode(int _key){
	key = _key;
}
BSTNode::~BSTNode(){

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

//--------------------------------------other--------------------------------------
void BSTNode::print(){
	cout << key << endl;
}