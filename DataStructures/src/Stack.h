#pragma once

class SNode {

public:

    SNode(const int value)
        :value(value),
        next(nullptr)
    {
    }

    int value;
    SNode* next;

};

class Stack {

public:
    Stack(const int value);
    ~Stack();

    SNode* GetTop() const { return top; };
    const int GetHeigth() const { return height; }
    void Print() const;

    // O(1) time complexity. Adds a node to the top of the stack. (Equivalent to Prepend on Linked Lists)
    void Push(int value);
    // O(1) time complexity. Removes the node at the top of the stack. (Equivalent to DeleteFirst on Linked Lists)
    const int Pop();

private:

    SNode* top;
    int height;

};