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
        head = head->GetNext();
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
        currentNode = currentNode->GetNext();
    }
}

const bool LinkedList::Set(const int index, const int value)
{
    Node* node = Get(index);
    
    if (node) {
        node->SetValue(value);
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

        newNode->SetNext(nodeBefore->GetNext());
        nodeBefore->SetNext(newNode);
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
        newNode->SetNext(head);
        head = newNode;
    }
    ++length;
}

void LinkedList::Append(const int value)
{
    Node* newNode = new Node(value);
    if (length > 0) {
        tail->SetNext(newNode);
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
    Node* node = nodeBefore->GetNext();
 
    nodeBefore->SetNext(node->GetNext());
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
        while (currentNode->GetNext())
        {
            if (currentNode->GetNext() == tail)
            {
                delete tail;
                tail = currentNode;
                currentNode->SetNext(nullptr);
                break;
            }
            currentNode = currentNode->GetNext();

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
        head = head->GetNext();
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
        currentNode->SetNext(nodeBefore);

        nodeBefore = currentNode;
        currentNode = origCurrentNode.GetNext();
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
        slowNode = slowNode->GetNext();
        fastNode = fastNode->GetNext()->GetNext();
    }

    return slowNode;
}

void LinkedList::PrintList() const
{
    const std::string headValue = head ? std::to_string(head->GetValue()) : "nullptr";
    const std::string tailValue = tail ? std::to_string(tail->GetValue()) : "nullptr";

    std::cout << "\nLinked List:\n"
        << "Head: " << headValue << "\n"
        << "Tail: " << tailValue << "\n"
        << "Length: " << length << "\n";

    const Node* currentNode = head;
    while (currentNode) {
        std::cout << currentNode->GetValue() << "\n";
        currentNode = currentNode->GetNext();
    }

}