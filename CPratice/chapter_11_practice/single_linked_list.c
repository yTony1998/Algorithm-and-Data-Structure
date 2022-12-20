#include <stdlib.h>
#include <stdio.h>

typedef struct NODE
{
    struct NODE *link;
    int value;
} Node;

#define FALSE 0
#define TRUE 1

int sll_inesrt( register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;
    /*
    *寻找正确的插入点
    */
    while ((current = *linkp) != NULL || current->value < new_value)
    {
        linkp = &current->link;
    }
    new = (Node*)malloc(sizeof(Node));
    if(new==NULL)
        return FALSE;

    new->value = new_value;
    //插入新节点
    new->link = current;
    *linkp = new;
    return TRUE;
   
}