#include <sstream>
#include <iostream>

#include "Stack.h"

Stack::Stack(const int value)
    :height(1)
{
	SNode* newNode = new SNode(value);
	top = newNode;
}

Stack::~Stack()
{
    const SNode* currentNode = top;
    while (currentNode) {
        top = top->next;
        delete currentNode;
        currentNode = top;
    }
}

void Stack::Print() const
{
    const std::string topValue = top ? std::to_string(top->value) : "nullptr";

    std::cout << "\n\tStack:\n\n"
        << "\tTop: " << topValue << "\n"
        << "\tHeight: " << height << "\n\n";

    const SNode* currentNode = top;
    while (currentNode) {
        std::cout << "\t" << currentNode->value << "\n";
        currentNode = currentNode->next;
    }
}

void Stack::Push(int value)
{
    SNode* newNode = new SNode(value);
    newNode->next = top;
    top = newNode;

    ++height;

}

const int Stack::Pop()
{
    if (!top) return INT_MIN;

    SNode* node = top;
    const int nodeValue = node->value;
    top = top->next;
    delete node;
    --height;

    return nodeValue;
}
