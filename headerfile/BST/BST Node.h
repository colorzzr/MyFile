#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

using namespace std;

class BSTNode{
private:
	/************************************
	 * Data Base Here: 					*
	 * you can augement data Here 		*
	 ************************************/
	int key;

	/************************
	 * Links for tree node	*
	 ************************/
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

	/********************************
	 * Guard for all tree algorithm	*
	 * 1-> node -1-> Guard			*
	 ********************************/
	int guard;

	/********************************
	 *check the total node in tree	*
	 ********************************/
	static int numberOfNode;
public:
	//condestructor
	BSTNode();
	BSTNode(int _key);
	~BSTNode();

	//get fucntion
	virtual int getKey();
	virtual BSTNode* getLeft();
	virtual BSTNode* getRight();
	virtual BSTNode* getParent();
	virtual int getGuard();


	//set function
	virtual void setKey(int _key);
	virtual void setLeft(BSTNode* _left);
	virtual void setRight(BSTNode* _right);
	virtual void setParent(BSTNode* _parent);
	virtual void setGuard(int _guard);

	//other
	virtual void print();
	/****************************************************
	 * use recursive way to count total number of nodes	*
	 * have same key with input "value"					*
	 ****************************************************/
	virtual int checkKey(int value);

	/****************************
	 * Find the max/min Node 	*
	 ****************************/
	virtual BSTNode* findMax(BSTNode* startNode);
	virtual BSTNode* findMin(BSTNode* startNode);

	/************************************************
	 * the fucntion would check the tree is BST		*
	 * based on the input "root"					*
	 ************************************************/
	virtual bool checkBST(BSTNode* root);
};

#endif