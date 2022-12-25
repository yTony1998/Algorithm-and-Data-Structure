#include "intSLList.hpp"
#include <iostream>
int main()
{
    IntSLList *intSLList = new IntSLList();
    intSLList->addToHead(45);
    intSLList->addToTail(85);
    intSLList->addToTail(95);
    intSLList->addToTail(105);
    
    // // bool ;
    // std::cout<<intSLList->isInList(85)<<std::endl;
    intSLList->deleteNode(85);
    intSLList->deleteNode(95);
    intSLList->deleteNode(105);
    intSLList->deleteNode(45);
    std::cout<<intSLList->isEmpty()<<std::endl;
}