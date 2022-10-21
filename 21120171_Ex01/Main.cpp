/*
	Name: Nguyen Dinh Anh
	ID: 2112 0171
	Lab Data structure & Algorithms - Week 05 - Exercise 01
	@file Main.cpp
*/
#include <iostream>
#include "BTree.h"
using namespace std;

void test() {
	Node* root = nullptr;
	int choice = 0;
	int data = 0;

	do {
		system("cls");
		cout << "Inorder: ";
		inorder(root);
		cout << endl << "By Level:" << endl;
		printByLv(root);
		cout << endl << "---------------" << endl;

		cout << "1. Insert BS Tree" << endl;
		cout << "2. Insert Binary Tree" << endl;
		cout << "3. Check BS Tree" << endl;
		cout << "0. Clear" << endl;
		cout << "Your choice (-1 to exit): ";
		cin >> choice;
		if (choice < -1 || choice > 3)
			cout << "Invalid! Try again: " << endl;
		cout << "----------" << endl;

		switch (choice)
		{
		case 1:
			cout << "Insert: ";
			cin >> data;
			insertBSTree(root, data);
			break;
		case 2:
			cout << "Insert: ";
			cin >> data;
			insertBinTree(root, data);
			break;
		case 3: 
			if (isBSTree(root)) {
				cout << "It's a BS Tree" << endl;
			}
			else {
				cout << "It's not a BS Tree" << endl;
			}
			system("pause");
			break;
		case 0:
			clear(root);
			cout << "The tree has been cleared!" << endl;
			system("pause");
			break;
		case -1:
			break;
		default:
			break;
		}
	} while (choice != -1);

	clear(root);
}

int main(int argc, char* argv[]) {
	try {
		test();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	system("PAUSE");
	return 0;
}

// -------------------------
// End of @file Main.cpp
