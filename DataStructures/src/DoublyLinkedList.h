#pragma once

class Node {

public:

    Node(const int value)
        :value(value),
        next(nullptr),
        prev(nullptr)
    {
    }

    int value;
    Node* next;
    Node* prev;

};

class DoublyLinkedList {

public: 

    DoublyLinkedList(const int value);
    ~DoublyLinkedList();

    const Node* GetHead() const { return head; };
    const Node* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    void PrintList() const;

    /* BASIC OPERATIONS */

    // O(1) time complexity. Adds a node to the end.
    void Append(const int value);
    // O(1) time complexity. Adds a new node to the begining.
    void Prepend(const int value);
    // O(1) time complexity. Deletes the last node.
    void DeleteLast();

private:

    Node* head;
    Node* tail;
    int length;

};