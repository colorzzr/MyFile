#include <iostream>

#include "BST.h"

BST::BST(){
	headlist = new BSTNode;
}

BST::~BST(){

}


BSTNode* BST::getHead(){
	return headlist;
}