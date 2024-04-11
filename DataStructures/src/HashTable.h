#pragma once

#include <sstream>

class HTNode {

public:

	HTNode(const std::string& key, const int value);

	const std::string key;
	int value;
	HTNode* next;

};

class HashTable {

public:

	HashTable();
	void Print() const;

private:

	const int Hash(const std::string& key) const;

	static constexpr int SIZE = 7;
	HTNode* dataMap[SIZE];

};