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

    Node* Get(const int index);
    const bool Set(const int index, const int value);
    const bool Insert(const int index, const int value);
    void Prepend(const int value);
    void Append(const int value);
    void DeleteNode(const int index);
    void DeleteLast();
    void DeleteFirst();
    void Reverse();

    const Node* GetHead() const { return head; };
    const Node* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    const Node* GetMiddleNode() const;
    void PrintList() const;

private:

    Node* head;
    Node* tail;
    int length;

};
