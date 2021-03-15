//-----------------------------------------------------
// Title: Dothraki Dictionary
// Author: Seyedehshahrzad Seyfafjehi
// ID: 21402754
// Section: 1
// Assignment: 4
// Description: This program is an implementation of looking up a word from the Dothraki Dictionary.
//-----------------------------------------------------
#include "AVL.h"

AVL::AVL() : root(NULL), size(0) {

}

AVL::~AVL() {
	destroy(root);
}

//get root function
TreeNode* AVL::getRoot() {
	return root;
}

//get the size of the tree
int AVL::getSize() {
	return size;
}

void AVL::setSize(int newSize) {
	size = newSize;
}

//set root function
void AVL::setRoot(TreeNode* newItem) {
	root = newItem;
}

//destroy function
void AVL::destroy(TreeNode* &treePtr) {
	if (treePtr != NULL) {
		destroy(treePtr->leftChild);
		destroy(treePtr->rightChild);
		delete treePtr;
		treePtr = NULL;
	}
}

//setting the balance property
void AVL::deterBalance(TreeNode* treePtr) {
	int hDiff;
	heightDiff(treePtr, hDiff);

	if (hDiff == 0) {
		treePtr->setBalance(equal);
	}
	else
		treePtr->setBalance(nEqual);
}

//determining empty AVL
bool AVL::isEmpty() {
	return (root == NULL);
}

//inorder display
void AVL::inorder(TreeNode* treePtr) {
	if (treePtr != NULL) {
		inorder(treePtr->leftChild);
		cout << treePtr->getKey() << " ";
		inorder(treePtr->rightChild);
	}

}

void AVL::inorderDisplay() {
	inorder(root);
}

//find an item in the AVL tree
bool AVL::find(string target) {
	return findItem(root, target);
}

bool AVL::findItem(TreeNode* treePtr, string target) {

	if (treePtr == NULL)
		return false;

	if (treePtr->getKey() == target)
		return true;

	bool lFound = findItem(treePtr->leftChild, target);
	bool rFound = findItem(treePtr->rightChild, target);

	if (lFound || rFound)
		return true;
	else
		return false;
}

//insertion
void AVL::insertNode(const string &newItem) {
	insert(root, newItem);
}

void AVL::insert(TreeNode* &treePtr, string newItem) {
	if (treePtr == NULL) {
		treePtr = new TreeNode(newItem, NULL, NULL);
		if (treePtr == NULL) {
			cout << "invalid node" << endl;
		}
		else
			++size;
	}

	else {
		int i = 0;

		if (treePtr->getKey() == newItem) {
			cout << "error! already exists" << endl;
			return;
		}

		//comparison based on the first letter
		else if (newItem.at(i) < treePtr->getKey().at(i)){
			insert(treePtr->leftChild, newItem);
			makeBalance(treePtr);
		}
		//in case the first letters are the same
		else if (newItem.at(i) == treePtr->getKey().at(i)) {
			int m = newItem.size();
			int l = treePtr->getKey().size();

			for (int n = 0; n < m && n < l && newItem.at(i) == treePtr->getKey().at(i); n++) {
				i++;
			}

			//in case one word is completely included in the other word( if newItem is smaller->leftsubtree, if newItem is bigger->rightsubtree)
			if (i == m) {
				insert(treePtr->leftChild, newItem);
				makeBalance(treePtr);
			}
			else if (i == l) {
				insert(treePtr->rightChild, newItem);
				makeBalance(treePtr);
			}

			//if not all letters of one word exists in the other
			else if (newItem.at(i) < treePtr->getKey().at(i)) {
				insert(treePtr->leftChild, newItem);
				makeBalance(treePtr);
			}
			else {
				insert(treePtr->rightChild, newItem);
				makeBalance(treePtr);
			}
		}
		else {
			insert(treePtr->rightChild, newItem);
			makeBalance(treePtr);
		}
	}
}

//right rotation(for the left subtree)
void AVL::rightRotation(TreeNode* &treePtr) {
	TreeNode* child = treePtr->leftChild;
	TreeNode* parent = treePtr;

	parent->leftChild = child->rightChild;
	child->rightChild = parent;
	treePtr = child;

}

//left rotation(for the right subtree)
void AVL::leftRotation(TreeNode* &treePtr) {
	TreeNode* child = treePtr->rightChild;
	TreeNode* paretnt = treePtr;

	paretnt->rightChild = child->leftChild;
	child->leftChild = paretnt;
	treePtr = child;
}

//double right-left rotation(for the left of the right subtree)
void AVL::rightLeftRot(TreeNode* &treePtr) {
	rightRotation(treePtr->rightChild);
	leftRotation(treePtr);
}

//left-right rotation(for the right of the left subtree)
void AVL::leftRightRot(TreeNode* &treePtr) {
	leftRotation(treePtr->leftChild);
	rightRotation(treePtr);
}

//get the height of a specific node
int AVL::height(TreeNode* treePtr) {
	int h = 0;

	if (treePtr != NULL) {
		int lheight = height(treePtr->leftChild) + 1;
		int rHeight = height(treePtr->rightChild) + 1;
		int maxHeight;

		if (lheight > rHeight)
			maxHeight = lheight;
		else
			maxHeight = rHeight;
		h = maxHeight;
	}

	return h;

}

//get the height difference of subtrees
bool AVL::heightDiff(TreeNode* treePtr, int &diff) {
	if (treePtr == NULL)
		return false;

	int lHeight = height(treePtr->leftChild);
	int rHeight = height(treePtr->rightChild);

	diff = lHeight - rHeight;
	return true;
}

//make a node balanced
void AVL::makeBalance(TreeNode* &treePtr) {
	int diff = 0;
	heightDiff(treePtr, diff);

	if (diff > 1) {
		int lDiff = 0;
		heightDiff(treePtr->leftChild, lDiff);
		if (lDiff > 0) {
			rightRotation(treePtr);
		}
		else
			leftRightRot(treePtr);
	}
	else if (diff < -1) {
		int rDiff = 0;
		heightDiff(treePtr->rightChild, rDiff);
		if (rDiff < 0)
			leftRotation(treePtr);
		else
			rightLeftRot(treePtr);
	}

}

void AVL::swap(TreeNode* &a, TreeNode* &b) {
	TreeNode* temp = a;
	a = b;
	b = temp;
}

//suggest similar words
void AVL::suggestions(const string word) {
	suggestion(word, root);
}

void AVL::suggestion(const string word, TreeNode* treePtr) {
	cout << "  Some suggestions:";
	if (treePtr == NULL)
		cout << " There is no word starting with letter " << word.at(0) << " in vocabulary!" << endl;
	else {
		int longestMatch = longestPref(treePtr, word);

		if (treePtr == NULL) {
			cout << " There is no word starting with letter " << word.at(0) << " in vocabulary!" << endl;
			return;
		}

		if (longestMatch == 0)
			cout << " There is no word starting with letter " << word.at(0) << " in vocabulary!" << endl;
		else {
			TreeNode* curr = treePtr;
			TreeNode* rightCurr = curr;
			TreeNode* leftCurr = curr;

			while (rightCurr->getKey().at(0) == word.at(0) && rightCurr != NULL) {
				int rSize = 0;
				int myRSize = rightCurr->key.size();

				for (int i = 0; (i < myRSize) && (rightCurr->key.at(i) == word.at(i)); i++) {
					++rSize;
				}

				if (rSize >= longestMatch)
					cout << rightCurr->key << " ";

				rightCurr = rightCurr->rightChild;
				cout << endl;
			}

			while (leftCurr->getKey().at(0) == word.at(0) && leftCurr != NULL) {
				int lSize = 0;
				int myLSize = leftCurr->key.size();

				for (int i = 0; (i < myLSize) && (leftCurr->key.at(i) == word.at(i)); i++) {
					++lSize;
				}

				if (lSize >= longestMatch)
					cout << rightCurr->key << " ";

				leftCurr = leftCurr->leftChild;
				cout << endl;
			}
		}
	}
}

//find the number of the longest matching prefix
int AVL::longestPref(TreeNode* &treePtr, const string word) {
	TreeNode* curr = treePtr;
	int max = 0;

	while ((curr != NULL) && (curr->getKey().at(0) != word.at(0))) {
		if (curr->key > word)
			curr = curr->leftChild;
		else if (curr->key < word)
			curr = curr->rightChild;
	}

	if (curr == NULL)
		return 0;

	TreeNode* rightCurr = curr;
	TreeNode* leftCurr = curr;

	while (rightCurr->getKey().at(0) == word.at(0) && rightCurr != NULL) {
		int myL = 0;
		int myRCurrSize = rightCurr->key.size();

		for (int j = 0; (j < myRCurrSize) && (rightCurr->key.at(j) == word.at(j)); j++) {
			++myL;
		}

		if (myL > max) {
			max = myL;
			treePtr = rightCurr;
		}
		rightCurr = rightCurr->rightChild;
	}

	while (leftCurr->getKey().at(0) == word.at(0) && leftCurr != NULL) {
		int myL = 0;
		int myLCurrSize = leftCurr->key.size();

		for (int j = 0; (j < myLCurrSize) && (leftCurr->key.at(j) == word.at(j)); j++) {
			++myL;
		}

		if (myL > max) {
			max = myL;
			treePtr = leftCurr;
		}
		leftCurr = leftCurr->leftChild;
	}
	return max;
}



