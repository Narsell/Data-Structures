
class LLNode {

public:

    LLNode(const int value)
        :value(value),
        next(nullptr)
    {
    }

    int value;
    LLNode* next;

};


class LinkedList {

public:

    LinkedList(const int value);

    ~LinkedList();

    const LLNode* GetHead() const { return head; };
    const LLNode* GetTail() const { return tail; };
    const int GetLength() const { return length; };
    void PrintList() const;

    /* BASIC OPERATIONS */

    // O(n) time complexity. Retrieves a node.
    LLNode* Get(const int index);
    // O(n) time complexity. Sets the value of a node at a given index.
    const bool Set(const int index, const int value);
    // O(n) time complexity. Inserts a node at a given index.
    const bool Insert(const int index, const int value);
    // O(1) time complexity. Adds a node to the begining.
    void Prepend(const int value);
    // O(1) time complexity. Adds a node to the end.
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
    const LLNode* GetMiddleNode() const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const LLNode* FindKthFromEnd(const int k) const;
    // O(n) time complexity. Using the "tortoise and hare" technique.
    const bool HasLoop() const;
    // O(n) time complexity. Partitions the list around x.
    void PartitionList(const int x);
    // O(n^2) time complexity. Removes duplicates using a runner pointer.
    void RemoveDuplicates();
    // O(n) time complexity. Removes duplicates using an std::unordered_set
    void RemoveDuplicatesUsingSet();
    // O(n) time complexity. Reverses a sublist between m and n.
    void ReverseBetween(int m, int n);
    

private:

    LLNode* head;
    LLNode* tail;
    int length;

};
