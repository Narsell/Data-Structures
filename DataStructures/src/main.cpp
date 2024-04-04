#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"

int main() {

    std::cout << "\n\n================= LINKED LIST ================= \n";
    std::cout << "\n=============================================== \n\n";

    LinkedList linkedList(1);
    linkedList.Append(2);
    linkedList.Append(3);
    linkedList.Append(4);
    linkedList.Append(5);
    linkedList.Print();

    std::cout << "\tMiddle node: " << linkedList.GetMiddleNode()->value << "\n";
    std::cout << "\t2nd element from end: " << linkedList.FindKthFromEnd(2)->value << "\n";
    std::cout << "\tHas loop?: " << linkedList.HasLoop() << "\n";

    std::cout << "\n=========\nREVERSED\n=========\n";

    linkedList.Reverse();
    linkedList.Print();

    constexpr int x = 3;
    std::cout << "\n====================\nPARTITIONED AROUND " << x << " \n====================\n";
    linkedList.PartitionList(x);
    linkedList.Print();

    std::cout << "\n================\nREMOVED DUPLICATES\n================\n";
    linkedList.RemoveDuplicatesUsingSet();
    linkedList.Print();

    linkedList.ReverseBetween(1, 3);
    linkedList.Print();

    std::cout << "\n\n================= DOUBLY LINKED LIST ================= \n";
    std::cout << "\n====================================================== \n\n";

    DoublyLinkedList doublyLL(1);
    doublyLL.Append(2);
    doublyLL.Append(3);
    doublyLL.Append(4);
    doublyLL.Append(5);
    doublyLL.Append(6);
    doublyLL.Append(7);

    doublyLL.SwapPairs();

    doublyLL.Print();

    std::cout << "\n\n================= STACK ======================== \n";
    std::cout << "\n================================================ \n\n";

    Stack stack(1);

    std::cout << stack.Pop() << "\n";

    stack.Print();

    std::cout << "\n\n================= QUEUE ======================== \n";
    std::cout << "\n================================================ \n\n";

    Queue queue(0);
    queue.Dequeue();
    queue.Enqueue(5);
    queue.Print();

    std::cout << "\n\n================= BINARY SEARCH TREE ======================== \n";
    std::cout << "\n============================================================ \n\n";

    BinarySearchTree bst;

    bst.Insert(47);
    bst.Insert(21);
    bst.Insert(76);
    bst.Insert(18);
    bst.Insert(52);
    bst.Insert(82);


    bst.Insert(27);


    std::cout << bst.GetRoot()->left->right->value << "\n";


}