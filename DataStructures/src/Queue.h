#pragma once

class QNode {

public:

    QNode(const int value)
        :value(value),
        next(nullptr)
    {
    }

    int value;
    QNode* next;
};

class Queue {

public:

    Queue(const int value);
    ~Queue();

    void Print() const;

    // O(1) time complexity. Adds a node to the end of the queue. (Equivalent to Append on Linked Lists)
    void Enqueue(const int value);
    // O(1) time complexity. Removes the node at the begining of the queue. (Equivalent to DeleteFirst on Linked Lists) 
    void Dequeue();

private:

    QNode* first;
    QNode* last;
    int length;

};