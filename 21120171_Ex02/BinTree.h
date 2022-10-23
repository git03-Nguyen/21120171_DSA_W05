#pragma once
/*
	Name: Nguyen Dinh Anh
	ID: 2112 0171
	Lab Data structure & Algorithms - Week 05 - Exercise 02
	@file BinTree.h
*/
#include <iostream>
#include <string>
using namespace std;

bool isOperand(string x) {
	return x[0] >= '0' && x[0] <= '9';
}

bool isOperator(string x) {
	return x.length() == 1 &&
		(x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/');
}

struct Node {
	string data;
	Node* left, * right;
};

Node* getNode(string x) {
	return new Node{ x, nullptr, nullptr };
}

int numberOfNode(Node* root) {
	if (root == nullptr) return 0;
	return 1 + numberOfNode(root->left) + numberOfNode(root->right);
}

void insertBinTree(Node*& root, string& prefix) {
	string temp;
	int i = 0;
	for (i = 0; i < prefix.length() && prefix[i] != ' '; i++) {
		temp += prefix[i];
	}
	if (temp.length() <= 0) return;
	prefix.erase(0, i + 1);

	root = getNode(temp);
	if (isOperand(temp)) return;

	insertBinTree(root->left, prefix);
	insertBinTree(root->right, prefix);
}

void preorder(Node* root) {
	if (root == nullptr) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void clear(Node*& root) {
	if (root == nullptr) return;
	clear(root->left);
	clear(root->right);
	delete root;
	root = nullptr;
}

double calculate(string op, double a, double b) {
	switch (op[0]) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		throw "Invalid operator!";
	}
	return 0;
}

double calExpr(Node* root) {
	if (root == nullptr) return 0;
	if (isOperand(root->data)) {
		if (root->left || root->right)
			throw "Invalid expression!";
		return stod(root->data);
	}
	if (isOperator(root->data)) {
		if (!root->left || !root->right)
			throw "Invalid expression!";
		return calculate(root->data, calExpr(root->left), calExpr(root->right));
	}
	throw "Errors!";
}


// ----------------------------------
// End of @file BinTree.h
