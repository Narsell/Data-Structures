#include "LinkedList.h"

int main() {

    LinkedList linkedList(1);
    linkedList.Append(2);
    linkedList.Append(3);
    linkedList.Append(4);
    linkedList.Append(5);
    linkedList.PrintList();

    linkedList.Reverse();
    linkedList.PrintList();

    std::cout << "Middle node: " << linkedList.GetMiddleNode()->GetValue() << std::endl;

}