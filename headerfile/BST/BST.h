#ifndef BST_H
#define BST_H

#include <iostream>
#include "BST Node.h"

class BST{
private:
	BSTNode* headList;
public:
	//constructor
	BST();
	//delete tree recursively
	~BST();

	//get function
	BSTNode* getHead();

	//operation function
	void operatingOnTree();

	/************************************************************
	 * this function would use recursion to print whole Tree 	*
	 ************************************************************/
	void printTree(BSTNode* head);

	/************************************************************
	 * This function would check the place is right children	*
	 * or left children	if left return true else return false	*
	 ************************************************************/
	bool checkLOrR(BSTNode* targetPlace);

	/****************************************
	 * insert would NOTNOT consider balance	*
	 ****************************************/
	void insertNode(BSTNode* insertOne);

	/****************************************
	 * the deletion would keep the balance  *
	 ****************************************/
	void deleteNode(BSTNode* targetNode);

	/****************************
	 * Find the left max Node 	*
	 ****************************/
	BSTNode* findLeftMax(BSTNode* startNode);

	/************************************
	 * Find the node with specific key	*
	 * and return a pointer to that Node*
	 ************************************/
	BSTNode* findNode(int key);


};
#endif