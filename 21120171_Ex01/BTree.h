#pragma once
/*
	Name: Nguyen Dinh Anh
	ID: 2112 0171
	Lab Data structure & Algorithms - Week 05 - Exercise 01
	@file BTree.h
*/

#include <iostream>
#include <cstdint>
using namespace std;

int nMax(int a, int b) {
	return a > b ? a : b;
}

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* getNode(int data) {
	return new Node{ data, nullptr, nullptr };
}

int getHeight(Node* root) {
	if (root == nullptr) return 0;
	return 1 + nMax(getHeight(root->left), getHeight(root->right));
}

void clear(Node*& root) {
	if (root == nullptr) return;
	clear(root->left);
	clear(root->right);
	delete root;
	root = nullptr;
}

void inorder(Node* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void printCurLv(Node* root, int level) {
	if (root == nullptr) return;
	if (level == 1) cout << root->data << " ";
	if (level > 1) {
		printCurLv(root->left, level - 1);
		printCurLv(root->right, level - 1);
	}
}

void printByLv(Node* root) {
	int level = getHeight(root);
	for (int i = 1; i <= level; i++) {
		printCurLv(root, i);
		cout << endl;
	}
}

Node* insertBSTree(Node*& root, int data) {
	if (root == nullptr) return root = getNode(data);
	if (data < root->data) return insertBSTree(root->left, data);
	return insertBSTree(root->right, data);
}

int numberOfNode(Node* root) {
	int count = 0;
	if (root == nullptr) return 0;
	return 1 + numberOfNode(root->left) + numberOfNode(root->right);
}

Node* insertBinTree(Node*& root, int data) {
	if (root == nullptr) return root = getNode(data);
	if (numberOfNode(root->left) <= numberOfNode(root->right))
		return insertBinTree(root->left, data);
	return insertBinTree(root->right, data);
	
}

void check(Node* root, bool &res) {
	static int prev = INT32_MIN;
	if (root==nullptr) return;
	check(root->left, res);
	if (prev >= root->data) res = false;
	prev = root->data;
	check(root->right, res);
}

bool isBSTree(Node* root) {
	if (numberOfNode(root) < 2) return true;
	bool res = true;
	check(root, res);
	return res;
}

// -------------------------------------------
// End of @file BTree.h






