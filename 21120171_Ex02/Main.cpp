/*
	Name: Nguyen Dinh Anh
	ID: 2112 0171
	Lab Data structure & Algorithms - Week 05 - Exercise 02
	@file Main.cpp
*/
#include <iostream>
#include "BinTree.h"

using namespace std;

void menuMain() {
	Node* root = nullptr;
	string x;
	int choice = 0;
	do {
		system("cls");
		cout << "Expression: ";
		preorder(root);
		cout << endl << "-----------------------" << endl;
		
		cout << "OPTIONS:" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Calculate" << endl;
		cout << "0. Clear" << endl;
		cout << "Your option (-1 to exit): ";
		cin >> choice;

		cout << "---------------" << endl;
		switch (choice) {
		case 0:
			clear(root);
			cout << "Tree has been cleared!" << endl;
			break;
		case 1:
			cout << "Insert: ";
			cin >> x;
			insertBinTree(root, x);
			break;
		case 2:
			try {
				double res = calExpr(root);
				cout << "Result: " << res << endl;
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			system("pause");
			break;
		case -1:
			break;
		default:
			cout << "Invalid option, try again. ";
			system("pause");
			break;
		}
	} while (choice != -1);
}

int main(int argc, char* argv[]) {
	try {
		menuMain();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}

// ---------------------------------
// End of @file Main.cpp
