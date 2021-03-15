//-----------------------------------------------------
// Title: Dothraki Dictionary
// Author: Seyedehshahrzad Seyfafjehi
// ID: 21402754
// Section: 1
// Assignment: 4
// Description: This program is an implementation of looking up a word from the Dothraki Dictionary.
//-----------------------------------------------------
#include "TreeNode.h"

class AVL {
private:
	TreeNode* root;
	int size;

	void destroy(TreeNode* &treePtr);
	TreeNode* getRoot();
	void setRoot(TreeNode* newRoot);

	int getSize();
	void setSize(int newSize);

	//insertion auxiliary function
	void insert(TreeNode* &treePtr, string newItem);

	void remove(TreeNode* treePtr, int item);
	void removeNode(TreeNode* &aNode);

	//rotations
	void leftRotation(TreeNode* &treePtr);
	void rightRotation(TreeNode* &treePtr);
	void rightLeftRot(TreeNode* &treePtr);
	void leftRightRot(TreeNode* &treePtr);

	//functions needed for insertion
	int height(TreeNode* treePtr);
	bool heightDiff(TreeNode* treePtr, int &diff);
	void makeBalance(TreeNode* &treePtr);

	//setting the balance property of a node
	void deterBalance(TreeNode* treePtr);

	//finding the inorder succesor of an item
	TreeNode* inorderSuccessor(TreeNode* treePtr);

	void swap(TreeNode* &a, TreeNode* &b);

	void inorder(TreeNode* treePtr);

	//find a word in the AVL tree
	bool findItem(TreeNode* treePtr, string target);

	//get the longest matching prefix
	int longestPref(TreeNode* &treePtr, const string word);

	//making suggestions to the user
	void suggestion(const string word, TreeNode* treePtr);

	TreeNode* findStartingNode(TreeNode* treePtr, string word);
	int longest(string word);
	int longest(TreeNode* treePtr, string word);

public:
	AVL();
	~AVL();

	void insertNode(const string &item);

	void deleteNode(string item);
	bool isValidAVL();
	bool isEmpty();

	void inorderDisplay();

	bool find(string target);

	void suggestions(const string word);
	void test(TreeNode* rootPtr, AVL &newTree, const string word);
	void test(const string word);
};

