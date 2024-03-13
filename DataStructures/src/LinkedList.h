#include <iostream>
#include <sstream>


class Node {

public:

    Node(const int value)
        :m_value(value),
        m_next(nullptr)
    {
    }

    const int GetValue() const { return m_value; };
    Node* GetNext() const { return m_next; };

    void SetValue(const int value) { m_value = value; };
    void SetNext( Node* next) { m_next = next; };

private:

    int m_value;
    Node* m_next;

};


class LinkedList {

public:

    LinkedList(const int value);

    ~LinkedList();

    const Node* GetHead() const { return head; };
    const Node* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    void PrintList() const;

    /* BASIC OPERATIONS */

    // O(n) time complexity. Retrieves a node.
    Node* Get(const int index);
    // O(n) time complexity. Sets the value of a node at a given index.
    const bool Set(const int index, const int value);
    // O(n) time complexity. Inserts a node at a given index.
    const bool Insert(const int index, const int value);
    // O(1) time complexity. Adds a node to the begining.
    void Prepend(const int value);
    // O(n) time complexity. Adds a node to the end.
    void Append(const int value);
    // O(n) time complexity. Deletes a node at a given index.
    void DeleteNode(const int index);
    // O(n) time complexity. Deletes the last node.
    void DeleteLast();
    // O(1) time complexity. Deletes a node at the begining.
    void DeleteFirst();
    // O(n) time complexity. Reverses the LL order.
    void Reverse();

    /* LEETCODE EXERCISES */

    // O(n) time complexity. Using the "tortoise and hare" technique.
    const Node* GetMiddleNode() const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const Node* FindKthFromEnd(const int k) const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const bool HasLoop() const;
    // O(n) time complexity. Partitions the list around x.
    void PartitionList(const int x);
    

private:

    Node* head;
    Node* tail;
    int length;

};
