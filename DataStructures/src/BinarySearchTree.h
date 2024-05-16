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
	
	/**
	 * O(log n) time complexity most of the time, can be O(n) if treated as a Linked List.
	 * Inserts a node into the BST.
	 * Returns true if the node was inserted successfully.
	 */
	const bool Insert(const int value);
	/**
	 * O(log n) time complexity most of the time, can be O(n) if treated as a Linked List.
	 * Determines whether a value is contained in the BST or not.
	 * Returns true if the value is contained, false otherwise.
	 */	
	const bool Contains(const int value) const;

	/**
	 * O(log n) time complexity most of the time, can be O(n) if treated as a Linked List.
	 * Recursively determines whether a value is contained in the BST or not.
	 * Returns true if the value is contained, false otherwise.
	 */
	const bool rContains(const int value);

	/**
	 * O(log n) time complexity most of the time, can be O(n) if treated as a Linked List.
	 * Recursively inserts a node into the BST.
	 * Returns true if the node was inserted successfully.
	 */
	const bool rInsert(const int value);


private:

	BSTNode* root;

	const bool rContains(BSTNode* currentNode, const int value);
	const bool rInsert(BSTNode* currentNode, const int value);
};