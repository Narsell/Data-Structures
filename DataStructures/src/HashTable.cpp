#include <iostream>

#include "HashTable.h"

HTNode::HTNode(const std::string& key, const int value)
	:key(key), value(value), next(nullptr)
{
}

HashTable::HashTable()
{
	for (int i = 0; i < SIZE; ++i) {
		dataMap[i] = nullptr;
	}
}

void HashTable::Print() const
{
	for (int i = 0; i < SIZE; ++i) {
		std::cout << "\n" << i << ":";
		if (dataMap[i]) {
			HTNode* current = dataMap[i];
			while (current) {
				std::cout << "\n\t" << current->key << ": " << current->value;
				current = current->next;
			}
		}
	}
}

const int HashTable::Get(const std::string& key) const
{
	const int index = Hash(key);

	const HTNode* current = dataMap[index];
	while (current) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}
	
	return INT_MIN;
}

void HashTable::Set(const std::string& key, const int value)
{
	const int index = Hash(key);

	if (dataMap[index] == nullptr) {
		HTNode* newNode = new HTNode(key, value);
		dataMap[index] = newNode;
	}
	else {
		HTNode* current = dataMap[index];

		while (current->next || current->key == key) {
			if (current->key == key) {
				current->value = value;
				return;
			}
			current = current->next;
		}
		current->next = new HTNode(key, value);;
	}
}

const int HashTable::Hash(const std::string& key) const
{
	int hash = 0;

	for (int i = 0; i < key.length(); ++i) {
		const int ascii = static_cast<int>(key[i]);
		hash = (hash + ascii * 23) % SIZE;
	}

	return hash;
}
