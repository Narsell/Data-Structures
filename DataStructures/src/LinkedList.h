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

    // O(n) time complexity.
    Node* Get(const int index);
    // O(n) time complexity.
    const bool Set(const int index, const int value);
    // O(n) time complexity.
    const bool Insert(const int index, const int value);
    // O(1) time complexity.
    void Prepend(const int value);
    // O(n) time complexity.
    void Append(const int value);
    void DeleteNode(const int index);
    void DeleteLast();
    void DeleteFirst();
    void Reverse();

    const Node* GetHead() const { return head; };
    const Node* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    void PrintList() const;

    /* LEETCODE EXERCISES */

    // O(n) time complexity. Using the "tortoise and hare" technique.
    const Node* GetMiddleNode() const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const Node* FindKthFromEnd(const int k) const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const bool HasLoop() const;
    

private:

    Node* head;
    Node* tail;
    int length;

};
