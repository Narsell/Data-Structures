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
