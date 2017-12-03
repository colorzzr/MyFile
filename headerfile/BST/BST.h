#ifndef BST_H
#define BST_H

#include <iostream>
#include "BST Node.h"

class BST{
private:
	BSTNode* headlist;
public:
	//void insertNode(BSTNode& )
	//constructor
	BST();
	~BST();

	BSTNode* getHead();


};
#endif