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

    void Push(int value);
    const int Pop();

private:

    SNode* top;
    int height;

};