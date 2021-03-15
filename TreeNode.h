//-----------------------------------------------------
// Title: Dothraki Dictionary
// Author: Seyedehshahrzad Seyfafjehi
// ID: 21402754
// Section: 1
// Assignment: 4
// Description: This program is an implementation of looking up a word from the Dothraki Dictionary.
//-----------------------------------------------------
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//check whether the height of subtrees of a node are balance or not
enum Balance
{
	equal, nEqual
};


class TreeNode {
public:
	TreeNode();
	TreeNode(string key);
	TreeNode(string key, TreeNode* leftChild, TreeNode* rightChild);

	bool isLeaf() const;

	string getKey() const;

	void setKey(string newKey);

	TreeNode* getLeftChildPtr() const;
	TreeNode* getRightChildPtr() const;

	void setLeftChildPtr(TreeNode* newLeft);
	void setRightChildPtr(TreeNode* newRight);
	void setBalance(Balance b);
	Balance getBalance();

	bool isLeaf(TreeNode* treePtr);

	friend class AVL;
private:
	string key;
	TreeNode* leftChild, *rightChild;
	Balance balance;
};


