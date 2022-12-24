#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList()
{
    for (IntSLLNode *p; !isEmpty();)
    {
        p = head->next;
        delete p;
        head = p;
    }
}
void IntSLList::addToHead(int el)
{
    head = new IntSLLNode(el, head);
    if(tail = 0)
        tail = head;
}

void IntSLList::addToTail(int el)
{
    if(tail != 0)
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    else
        head = tail = new IntSLLNode(el);
}
int IntSLList::deleteFromHead()
{
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail()
{
    int el = tail->info;
    
    if(tail = head)
    {
        delete head;
        tail = head = 0;

    }
    else
    {
        IntSLLNode *tmp;
        for(tmp = head; tmp->next != tail; tmp = tmp->next) ;
        delete tail;
        tmp->next = 0;
        tail = tmp;
    }

    return el;
}
void IntSLList::deleteNode(int el)
{
    if (head != 0)
        if (head == tail && el == head ->info)
        {
            delete head;
            head = tail = 0;
        }
        else if (el == head->info) //删除元素在第一个
        {
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else //在末尾或者其他地方
        {
            IntSLLNode *pred , *tmp;
            for(pred = head, tmp = head->next;
                tmp !=0 && !(tmp->info == el);
                pred = pred->next, tmp = tmp->next);
            if(tmp != 0)
            {
                pred->next = tmp->next;
                if (tmp == tail) //元素在末尾
                    tail = pred;
                delete tmp;
            }
        }
}

bool IntSLList::isInList(int el) const
{
    IntSLLNode *tmp;
    for(tmp = head; tmp != 0 && (tmp->info != el); tmp->next)
    return tmp !=0;
}