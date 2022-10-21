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

Node* insertBinTree(Node*& root, string data) {
	if (root == nullptr) return root = getNode(data);
	if (numberOfNode(root->left) <= numberOfNode(root->right))
		return insertBinTree(root->left, data);
	else
		return insertBinTree(root->right, data);
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

bool isOperand(string x) {
	return x[0] >= '0' && x[0] <= '9';
}

bool isOperator(string x) {
	return x.length() == 1 &&
		(x[0] == '+' && x[0] == '-' || x[0] == '*' || x[0] == '/');
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
