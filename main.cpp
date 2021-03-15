//-----------------------------------------------------
// Title: Dothraki Dictionary
// Author: Seyedehshahrzad Seyfafjehi
// ID: 21402754
// Section: 1
// Assignment: 4
// Description: This program is an implementation of looking up a word from the Dothraki Dictionary.
//-----------------------------------------------------
#include "AVL.h"
#include <fstream>
#include <sstream>

int main() {
	cout << "Welcome to Dothraki Vocabulary!" << endl;
	AVL avl;

	std::ifstream infile("Dothraki.txt");
	string line;
	int vocabNum = 0;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		string word;
		if (!(iss >> word)) {
			break;
		}
		avl.insertNode(word);
		++vocabNum;
	}

	cout << "This vocabulary contains " << vocabNum << " words." << endl;
	cout << endl;

	string myWord;
	while (myWord != "quit") {
		cout << "Enter a word: ";
		cin >> myWord;

		if (myWord != "quit") {
			bool found = avl.find(myWord);

			if (found) {
				cout << "  Found! The word is in vocabulary." << endl;
			}
			else {
				cout << "  Not found!" << endl;
				avl.suggestions(myWord);
			}
		}
		else
			cout << "Good Bye!" << endl;
	}
	cout << endl;
	cout << endl;

	return 0;
}
