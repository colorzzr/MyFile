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
	 * Find the max/min Node 	*
	 ****************************/
	BSTNode* findMax(BSTNode* startNode);
	BSTNode* findMin(BSTNode* startNode);

	/************************************
	 * Find the node with specific key	*
	 * and return a pointer to that Node*
	 ************************************/
	BSTNode* findNode(int key);

	/********************************************************
	 * function would generate a tree based on input "size"	*
	 * and using input "seed" to generate ramdon numebr		*
	 ********************************************************/
	void generateTree(int size, int seed);

	/********************************************************
	 * the function would return the total number of node 	*
	 * have same key with input "value"						*
	 ********************************************************/
	int checkKey(int value);

	/********************************************************
	 * the finction printPreorder would print the tree using*
	 * DFS order same as graph								*
	 ********************************************************/
	void printPreorder(BSTNode* node);

	/************************************************
	 * the fucntion would check the tree is BST		*
	 ************************************************/
	bool isBST();

	/****************************************
	 * print tree as CBA reverse of inorder	*
	 ****************************************/
	void reverseOrder(BSTNode* node);
};
#endif