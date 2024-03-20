#include <sstream>
#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(const int value)
{
	DLLNode* newNode = new DLLNode(value);
	head = newNode;
	tail = newNode;
	length = 1;
}

DoublyLinkedList::~DoublyLinkedList()
{
	const DLLNode* currentNode = head;
	while (head) {
		head = head->next;
		delete currentNode;
		currentNode = head;
	}
}

void DoublyLinkedList::PrintList() const
{
	const std::string headValue = head ? std::to_string(head->value) : "nullptr";
	const std::string tailValue = tail ? std::to_string(tail->value) : "nullptr";

	std::cout << "\n\tDoubly Linked List:\n\n"
		<< "\tHead: " << headValue << "\n"
		<< "\tTail: " << tailValue << "\n"
		<< "\tLength: " << length << "\n\n";

	const DLLNode* currentNode = head;
	while (currentNode) {
		std::cout << "\t" << currentNode->value << "\n";
		currentNode = currentNode->next;
	}

}

const DLLNode* DoublyLinkedList::Get(const int index)
{
	if (!head || index >= length || index < 0) return nullptr;

	const bool closerToHead = index <= (length - 1)/ 2;
	const DLLNode* currentNode = closerToHead ? head : tail;
	const int finalIndex = closerToHead ? index : length - 1 - index;

	for (int i = 0; i < finalIndex; ++i) {
		currentNode = closerToHead ? currentNode->next : currentNode->prev;
	}

	return currentNode;
}

void DoublyLinkedList::Append(const int value)
{
	DLLNode* newNode = new DLLNode(value);

	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++length;
}

void DoublyLinkedList::Prepend(const int value)
{
	DLLNode* newNode = new DLLNode(value);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	++length;
}

void DoublyLinkedList::DeleteLast()
{
	if (!head) return;

	const DLLNode* lastNode = tail;

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = lastNode->prev;
		tail->next = nullptr;
	}
	delete lastNode;
	--length;
}

void DoublyLinkedList::DeleteFirst()
{
	if (!head) return;
	const DLLNode* headToDelete = head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}
	--length;
	delete headToDelete;
}
