#include <unordered_set>
#include <sstream>
#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList(const int value)
    :length(1)
{
    LLNode* newNode = new LLNode(value);
    head = newNode;
    tail = newNode;
}

LinkedList::~LinkedList()
{
    const LLNode* currentNode = head;
    while (head) {
        head = head->next;
        delete currentNode;
        currentNode = head;
    }
}

LLNode* LinkedList::Get(const int index) const
{
    if (index < 0 || index >= length) {
        return nullptr;
    }
    LLNode* currentNode = head;
    int currentIndex = 0;
    while (head) {
        if (currentIndex == index) {
            return currentNode;
        }
        ++currentIndex;
        currentNode = currentNode->next;
    }
}

const bool LinkedList::Set(const int index, const int value)
{
    LLNode* node = Get(index);
    
    if (node) {
        node->value = value;
        return true;
    }
    return false;
}

const bool LinkedList::Insert(const int index, const int value)
{
    if (index < 0 || index > length) {
        return false;
    }
    else if (index == 0) {
        Prepend(value);
    }
    else if (index == length) {
        Append(value);
    }
    else {
        LLNode* newNode = new LLNode(value);
        LLNode* nodeBefore = Get(index - 1);

        newNode->next = nodeBefore->next;
        nodeBefore->next = newNode;
        ++length;
    }
    return true;

}

void LinkedList::Prepend(const int value)
{
    LLNode* newNode = new LLNode(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    ++length;
}

void LinkedList::Append(const int value)
{
    LLNode* newNode = new LLNode(value);
    if (length > 0) {
        tail->next = newNode;
        tail = newNode;
    }
    else {
        head = newNode;
        tail = newNode;
    }
    ++length;
}

void LinkedList::DeleteNode(const int index)
{
    if (index < 0 || index >= length) return;
    if (index == 0) return DeleteFirst();
    else if (index == length - 1) return DeleteLast();
 
    LLNode* nodeBefore = Get(index - 1);
    LLNode* node = nodeBefore->next;
 
    nodeBefore->next = node->next;
    delete node;
    --length;
}

void LinkedList::DeleteLast()
{
    if (length == 0) return;
    else if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    else {
        LLNode* currentNode = head;
        while (currentNode->next)
        {
            if (currentNode->next == tail)
            {
                delete tail;
                tail = currentNode;
                currentNode->next = nullptr;
                break;
            }
            currentNode = currentNode->next;

        }
        --length;
    }
}

void LinkedList::DeleteFirst()
{
    if (length == 0) return;

    const LLNode* headBeforeDelete = head;

    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
    }
    delete headBeforeDelete;
    --length;
}

void LinkedList::Reverse()
{
    if (!head) {
        return;
    }

    LLNode* tempHead = head;
    head = tail;
    tail = tempHead;

    LLNode* currentNode = tail;
    LLNode* nodeBefore = nullptr;
    while (currentNode) {
        LLNode origCurrentNode = *currentNode;
        currentNode->next = nodeBefore;

        nodeBefore = currentNode;
        currentNode = origCurrentNode.next;
    }

}

const LLNode* LinkedList::GetMiddleNode() const
{
    if (!head) {
        return nullptr;
    }
    LLNode* slowNode = head;
    LLNode* fastNode = head;

    while (fastNode && fastNode != tail) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }

    return slowNode;
}

const LLNode* LinkedList::FindKthFromEnd(const int k) const
{
    LLNode* slow = head;
    LLNode* fast = head;

    for (int i = 0; i < k; ++i) {
        if (!fast) {
            return nullptr;
        }
        fast = fast->next;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

const bool LinkedList::HasLoop() const
{
    if (!head) {
        return false;
    }
    LLNode* slowNode = head;
    LLNode* fastNode = head;

    while (fastNode && fastNode->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;

        if (slowNode == fastNode) {
            return true;
        }

    }
    return false;
}

void LinkedList::PartitionList(const int x){

    if (!head) return;

    LLNode lhead(0);
    LLNode rhead(0);

    LLNode* ltail = &lhead;
    LLNode* rtail = &rhead;

    LLNode* currentNode = head;
    while (currentNode) {

        if (currentNode->value < x) {
            ltail->next = currentNode;
            ltail = currentNode;
        }
        else {
            rtail->next = currentNode;
            rtail = currentNode;
        }

        currentNode = currentNode->next;
    }

    rtail->next = nullptr;
    ltail->next = rhead.next;

    head = lhead.next;
    tail = rtail;

}

void LinkedList::RemoveDuplicates() {
    if (!head) return;

    LLNode* current = head;
    LLNode* runner = current;
    LLNode* prev_runner = current;

    while (current) {
        runner = current->next;
        prev_runner = current;

        while (runner) {
            if (runner->value == current->value) {
                prev_runner->next = runner->next;
                --length;
                delete runner;
                runner = prev_runner->next;
            }
            else {
                runner = runner->next;
                prev_runner = prev_runner->next;
            }
        }
        if (!current->next) {
            tail = current;
        }
        current = current->next;
    }
}

void LinkedList::RemoveDuplicatesUsingSet()
{
    if (!head) return;

    std::unordered_set<int> values;

    LLNode* current = head;
    LLNode* previous = nullptr;

    while (current) {

        if (values.find(current->value) != values.end()) {
            const LLNode* duplicate = current;
            previous->next = current->next;
            delete current;
            current = previous->next;
            --length;
        }
        else {
            values.insert(current->value);
            previous = current;
            current = current->next;
        }
        if (!current) {
            tail = previous;
        }
    }
}

void LinkedList::ReverseBetween(int m, int n)
{
    if (!head || m == n || m < 0 || m > length - 1 || n > length - 1) return;

    LLNode* sublistHead = new LLNode(0);
    sublistHead->next = head;
    LLNode* sublistTail = sublistHead->next;

    LLNode* leftEdge = head;
    LLNode* rightEdge = nullptr;

    //Iterate through LL and find sublist and edges of original list.
    LLNode* currentNode = head;
    int index = 0;
    while (currentNode) {
        if (index + 1 == m) {
            leftEdge = currentNode;
            sublistHead->next = currentNode->next;
        }
        else if (index == n) {
            rightEdge = currentNode->next;
            sublistTail = currentNode;
        }

        ++index;
        currentNode = currentNode->next;
    }

    //Reverse sublist.
    LLNode* sublistNode = sublistHead->next;
    LLNode* previous = nullptr;
    while (sublistNode && previous != sublistTail) {
        LLNode* nextNode = sublistNode->next;

        sublistNode->next = previous;

        previous = sublistNode;
        sublistNode = nextNode;
    }

    LLNode* tempSublistHead = sublistHead->next;
    sublistHead->next = sublistTail;
    sublistTail = tempSublistHead;

    //Attatch reversed sublist to original list appropriately 
    if (sublistTail == head) {
        head = sublistHead->next;
    }
    else {
        leftEdge->next = sublistHead->next;
    }

    sublistTail->next = rightEdge;
    
}

void LinkedList::Print() const
{
    const std::string headValue = head ? std::to_string(head->value) : "nullptr";
    const std::string tailValue = tail ? std::to_string(tail->value) : "nullptr";

    std::cout << "\n\tLinked List:\n\n"
        << "\tHead: " << headValue << "\n"
        << "\tTail: " << tailValue << "\n"
        << "\tLength: " << length << "\n\n";

    const LLNode* currentNode = head;
    while (currentNode) {
        std::cout << "\t" << currentNode->value << "\n";
        currentNode = currentNode->next;
    }

}