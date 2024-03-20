#include <sstream>
#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(const int value)
{
	Node* newNode = new Node(value);
	head = newNode;
	tail = newNode;
	length = 1;
}

DoublyLinkedList::~DoublyLinkedList()
{
	const Node* currentNode = head;
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

	std::cout << "\nDoubly Linked List:\n\n"
		<< "\tHead: " << headValue << "\n"
		<< "\tTail: " << tailValue << "\n"
		<< "\tLength: " << length << "\n\n";

	const Node* currentNode = head;
	while (currentNode) {
		std::cout << "\t" << currentNode->value << "\n";
		currentNode = currentNode->next;
	}

}

void DoublyLinkedList::Append(const int value)
{
	Node* newNode = new Node(value);

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
	Node* newNode = new Node(value);
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

	Node* lastNode = tail;

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