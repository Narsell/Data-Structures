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
	HTNode* examlple[SIZE];

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

const int HashTable::Hash(const std::string& key) const
{
	int hash = 0;

	for (int i = 0; i < key.length(); ++i) {
		const int ascii = static_cast<int>(key[i]);
		hash = (hash + ascii * 23) % 23;
	}

	return hash;
}
