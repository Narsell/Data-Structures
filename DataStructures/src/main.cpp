//#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main() {

    //LinkedList linkedList(1);
    //linkedList.Append(2);
    //linkedList.Append(3);
    //linkedList.Append(4);
    //linkedList.Append(5);
    //linkedList.PrintList();

    //std::cout << "Middle node: " << linkedList.GetMiddleNode()->value << "\n";
    //std::cout << "2nd element from end: " << linkedList.FindKthFromEnd(2)->value << "\n";
    //std::cout << "Has loop?: " << linkedList.HasLoop() << "\n";

    //std::cout << "\n================= REVERSED ================= \n";
    //linkedList.Reverse();
    //linkedList.PrintList();

    //constexpr int x = 3;
    //std::cout << "\n================= PARTITIONED LL AROUND "  << x << " ================= \n";
    //linkedList.PartitionList(x);
    //linkedList.PrintList();

    //std::cout << "\n================= REMOVED DUPLICATES ================= \n";
    //linkedList.RemoveDuplicatesUsingSet();
    //linkedList.PrintList();

    //linkedList.ReverseBetween(1, 3);
    //linkedList.PrintList();


    DoublyLinkedList doublyLL(2);
    doublyLL.Append(3);
    doublyLL.Prepend(1);
    doublyLL.PrintList();

}