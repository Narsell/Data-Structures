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
	
	// Strictly speaking O(n) time complexity however most of the time it can be treated as O(log n).
	const bool Insert(const int value);
	// Strictly speaking O(n) time complexity however most of the time it can be treated as O(log n).
	const bool Contains(const int value) const;

private:

	BSTNode* root;

};