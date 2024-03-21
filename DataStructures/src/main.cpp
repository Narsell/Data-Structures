#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main() {

    std::cout << "\n\n================= LINKED LIST ================= \n";
    std::cout << "\n=============================================== \n\n";

    LinkedList linkedList(1);
    linkedList.Append(2);
    linkedList.Append(3);
    linkedList.Append(4);
    linkedList.Append(5);
    linkedList.PrintList();

    std::cout << "\tMiddle node: " << linkedList.GetMiddleNode()->value << "\n";
    std::cout << "\t2nd element from end: " << linkedList.FindKthFromEnd(2)->value << "\n";
    std::cout << "\tHas loop?: " << linkedList.HasLoop() << "\n";

    std::cout << "\n=========\nREVERSED\n=========\n";

    linkedList.Reverse();
    linkedList.PrintList();

    constexpr int x = 3;
    std::cout << "\n====================\nPARTITIONED AROUND " << x << " \n====================\n";
    linkedList.PartitionList(x);
    linkedList.PrintList();

    std::cout << "\n================\nREMOVED DUPLICATES\n================\n";
    linkedList.RemoveDuplicatesUsingSet();
    linkedList.PrintList();

    linkedList.ReverseBetween(1, 3);
    linkedList.PrintList();

    std::cout << "\n\n================= DOUBLY LINKED LIST ================= \n";
    std::cout << "\n====================================================== \n\n";

    DoublyLinkedList doublyLL(1);
    doublyLL.Append(2);
    doublyLL.Append(3);
    doublyLL.Append(4);
    doublyLL.Append(5);
    doublyLL.Append(6);
    doublyLL.Append(7);

    doublyLL.Insert(7, 99);

    doublyLL.PrintList();

}