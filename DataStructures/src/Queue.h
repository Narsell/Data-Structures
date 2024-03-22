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

    // O(1) time complexity. Adds a node to the queue's end.
    void Enqueue(const int value);
    // O(1) time complexity. Pops the first element in the queue.
    void Dequeue();

private:

    QNode* first;
    QNode* last;
    int length;

};