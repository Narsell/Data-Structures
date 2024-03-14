#include <unordered_set>

#include "LinkedList.h"

LinkedList::LinkedList(const int value)
    :length(1)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
}

LinkedList::~LinkedList()
{
    const Node* currentNode = head;
    while (head) {
        head = head->next;
        delete currentNode;
        currentNode = head;
    }
}

Node* LinkedList::Get(const int index)
{
    if (index < 0 || index >= length) {
        return nullptr;
    }
    Node* currentNode = head;
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
    Node* node = Get(index);
    
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
        Node* newNode = new Node(value);
        Node* nodeBefore = Get(index - 1);

        newNode->next = nodeBefore->next;
        nodeBefore->next = newNode;
        ++length;
    }
    return true;

}

void LinkedList::Prepend(const int value)
{
    Node* newNode = new Node(value);
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
    Node* newNode = new Node(value);
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
 
    Node* nodeBefore = Get(index - 1);
    Node* node = nodeBefore->next;
 
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
        Node* currentNode = head;
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

    const Node* headBeforeDelete = head;

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

    Node* tempHead = head;
    head = tail;
    tail = tempHead;

    Node* currentNode = tail;
    Node* nodeBefore = nullptr;
    while (currentNode) {
        Node origCurrentNode = *currentNode;
        currentNode->next = nodeBefore;

        nodeBefore = currentNode;
        currentNode = origCurrentNode.next;
    }

}

const Node* LinkedList::GetMiddleNode() const
{
    if (!head) {
        return nullptr;
    }
    Node* slowNode = head;
    Node* fastNode = head;

    while (fastNode && fastNode != tail) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }

    return slowNode;
}

const Node* LinkedList::FindKthFromEnd(const int k) const
{
    Node* slow = head;
    Node* fast = head;

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
    Node* slowNode = head;
    Node* fastNode = head;

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

    Node lhead(0);
    Node rhead(0);

    Node* ltail = &lhead;
    Node* rtail = &rhead;

    Node* currentNode = head;
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

    Node* current = head;
    Node* runner = current;
    Node* prev_runner = current;

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

    Node* current = head;
    Node* previous = nullptr;

    while (current) {

        if (values.find(current->value) != values.end()) {
            const Node* duplicate = current;
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

void LinkedList::PrintList() const
{
    const std::string headValue = head ? std::to_string(head->value) : "nullptr";
    const std::string tailValue = tail ? std::to_string(tail->value) : "nullptr";

    std::cout << "\nLinked List:\n\n"
        << "\tHead: " << headValue << "\n"
        << "\tTail: " << tailValue << "\n"
        << "\tLength: " << length << "\n\n";

    const Node* currentNode = head;
    while (currentNode) {
        std::cout << "\t" << currentNode->value << "\n";
        currentNode = currentNode->next;
    }

}