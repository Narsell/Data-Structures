#pragma once

class BSTNode {

public:
	BSTNode(const int value)
		:value(value),
		left(nullptr),
		right(nullptr)
	{
	}

	BSTNode* left;
	BSTNode* right;
	int value;

};

class BinarySearchTree {

public:

	BinarySearchTree();

	const BSTNode* GetRoot() const { return root; };
	
	const bool Insert(const int value);

private:

	BSTNode* root;

};