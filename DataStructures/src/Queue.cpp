#include <sstream>
#include <iostream>

#include "Queue.h"

Queue::Queue(const int value)
	:length(1)
{
	QNode* newNode = new QNode(value);
	first = newNode;
	last = newNode;
}

Queue::~Queue()
{
	const QNode* currentNode = first;
	while (currentNode) {
		first = first->next;
		delete currentNode;
		currentNode = first;
	}
}

void Queue::Print() const
{
	const std::string firstValue = first ? std::to_string(first->value) : "nullptr";
	const std::string lastValue = last ? std::to_string(last->value) : "nullptr";

	std::cout << "\n\tQueue:\n\n"
		<< "\tFirst: " << firstValue << "\n"
		<< "\tLast: " << lastValue << "\n"
		<< "\tLength: " << length << "\n\n";

	const QNode* currentNode = first;
	while (currentNode) {
		std::cout << "\t" << currentNode->value << "\n";
		currentNode = currentNode->next;
	}
}

void Queue::Enqueue(const int value)
{
	QNode* newNode = new QNode(value);
	
	if (!first) {
		first = newNode;
		last = newNode;
	}
	else {
		last->next = newNode;
		last = newNode;
	}


	++length;
}

void Queue::Dequeue()
{
	if (!first) { return; }
	else if (first == last) { last = nullptr; }

	QNode* currentNode = first;
	first = first->next;
	delete currentNode;
	--length;

}
