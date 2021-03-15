//-----------------------------------------------------
// Title: Dothraki Dictionary
// Author: Seyedehshahrzad Seyfafjehi
// ID: 21402754
// Section: 1
// Assignment: 4
// Description: This program is an implementation of looking up a word from the Dothraki Dictionary.
//-----------------------------------------------------
#include "TreeNode.h"

TreeNode::TreeNode() {

}

TreeNode::TreeNode(string key) : key(key) {

}

TreeNode::TreeNode(string key, TreeNode* leftChild, TreeNode* rightChild) : key(key), leftChild(leftChild), rightChild(rightChild) {

}


bool TreeNode::isLeaf()const {
	return(leftChild == NULL&&rightChild == NULL);
}

string TreeNode::getKey()const {
	return key;
}

void TreeNode::setKey(string newKey) {
	key = newKey;
}

void TreeNode::setBalance(Balance b) {
	balance = b;
}

TreeNode* TreeNode::getLeftChildPtr()const {
	return leftChild;
}

TreeNode* TreeNode::getRightChildPtr()const {
	return rightChild;
}

Balance TreeNode::getBalance() {
	return balance;
}

void TreeNode::setLeftChildPtr(TreeNode* newLeft) {
	leftChild = newLeft;
}


void TreeNode::setRightChildPtr(TreeNode* newRight) {
	rightChild = newRight;
}

bool TreeNode::isLeaf(TreeNode* treePtr) {
	return (leftChild == NULL);
}



