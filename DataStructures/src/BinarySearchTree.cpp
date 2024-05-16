#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
	:root(nullptr)
{
}

const bool BinarySearchTree::Insert(const int value)
{
	BSTNode* newNode = new BSTNode(value);

	if (!root) {
		root = newNode;
		return true;
	}
	
	BSTNode* current = root;

	while (current) {

		if (current->value == value) {
			delete newNode;
			return false;
		};

		if (value > current->value) {
			if (current->right == nullptr) {
				current->right = newNode;
				return true;
			}
			current = current->right;
		}
		else {
			if (current->left == nullptr) {
				current->left = newNode;
				return true;
			}
			current = current->left;
		}
	}
}

const bool BinarySearchTree::Contains(const int value) const
{
	BSTNode* current = root;

	while (current) {

		if (current->value == value) {
			return true;
		}
		else if (value < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	
	}

	return false;
}

const bool BinarySearchTree::rContains(const int value)
{
	return rContains(root, value);
}

const bool BinarySearchTree::rInsert(const int value)
{
	return rInsert(root, value);
}

const bool BinarySearchTree::rContains(BSTNode* currentNode, const int value)
{
	if (currentNode == nullptr) return false;

	if (value == currentNode->value) return true;

	if (value < currentNode->value) {
		return rContains(currentNode->left, value);
	}
	else {
		return rContains(currentNode->right, value);
	}

}

const bool BinarySearchTree::rInsert(BSTNode* currentNode, const int value)
{

	if (currentNode == root && root == nullptr) {
		root = new BSTNode(value);
		return true;
	} else if (currentNode->value == value) 
		return false;

	if (value < currentNode->value) {
		if (currentNode->left == nullptr) {
			currentNode->left = new BSTNode(value);
			return true;
		}
		return rInsert(currentNode->left, value);
	}
	else {
		if (currentNode->right == nullptr) {
			currentNode->right = new BSTNode(value);
			return true;
		}
		return rInsert(currentNode->right, value);
	}
}
