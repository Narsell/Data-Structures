#pragma once

class DLLNode {

public:

    DLLNode(const int value)
        :value(value),
        next(nullptr),
        prev(nullptr)
    {
    }

    int value;
    DLLNode* next;
    DLLNode* prev;

};

class DoublyLinkedList {

public: 

    DoublyLinkedList(const int value);
    ~DoublyLinkedList();

    const DLLNode* GetHead() const { return head; };
    const DLLNode* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    void PrintList() const;

    /* BASIC OPERATIONS */

    // O(n) time complexity (with DLL optimization). Gets the node at the given index.
    const DLLNode* Get(const int index);
    // O(1) time complexity. Adds a node to the end.
    void Append(const int value);
    // O(1) time complexity. Adds a new node to the begining.
    void Prepend(const int value);
    // O(1) time complexity. Deletes the last node.
    void DeleteLast();
    // O(1) time complexity. Deletes the first node.
    void DeleteFirst();

private:

    DLLNode* head;
    DLLNode* tail;
    int length;

};