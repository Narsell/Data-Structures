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
    DLLNode* Get(const int index) const;
    // O(n) time complexity (with DLL optimization). Sets the value of a node at a given index.
    const bool Set(const int index, const int value);
    // O(n) time complexity. Inserts a new node at the given index.
    const bool Insert(const int index, const int value);
    // O(1) time complexity. Adds a new node to the begining.
    void Prepend(const int value);
    // O(1) time complexity. Adds a node to the end.
    void Append(const int value);
    // O(n) time complexity. Deletes a node at a given index.
    void DeleteNode(const int index);
    // O(1) time complexity. Deletes the last node.
    void DeleteLast();
    // O(1) time complexity. Deletes the first node.
    void DeleteFirst();

    /* LEETCODE EXERCISES */

    // O(1) time complexity. Swaps the first and last elements.
    void SwapFirstLast();
    // O(n) time complexity. Reverses the order on the list.
    void Reverse();
    // O(n) time complexity. Returns true if DLL is palindrome, i.e., its elements read the same forwards and backwards.
    const bool IsPalindrome() const;
    // O(n) time complexity. Swaps every two adjacent nodes in the list.
    void SwapPairs();


private:

    DLLNode* head;
    DLLNode* tail;
    int length;

};