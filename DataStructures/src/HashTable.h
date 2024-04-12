#pragma once
#include <vector>
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

	/**
	 * O(1) time complexity, technically O(n) but almost mathematically impossible to behave like O(n).
	 * Returns the value from a given key. If the key does not exists, it returns INT_MIN.
	 */
	const int Get(const std::string& key) const;

	/**
	 * O(1) time complexity, technically O(n) but almost mathematically impossible to behave like O(n).
	 * Sets the value of a key. If the key already exists it will be overwritten with the new value.
	 */
	void Set(const std::string& key, const int value);

	/**
	 * O(n) time complexity.
	 * Retrieves all keys and returns them in a std::vector.
	 */
	std::vector<std::string> Keys() const;

private:

	const int Hash(const std::string& key) const;

	static constexpr int SIZE = 7;
	HTNode* dataMap[SIZE];

};