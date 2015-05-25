#include "linklist.h"

void sort_0_1_3_LinkList(LLNode ** head)
{
    LLNode * zeroListHead = NULL;
    LLNode * oneListHead = NULL;
    LLNode * twoListHead = NULL;

    LLNode * zeroListNode = NULL;
    LLNode * oneListNode = NULL;
    LLNode * twoListNode = NULL;

    LLNode * node = *head;
    while(node != NULL)
    {
       if(node->nodeNum == 0)
       {
           if(NULL == zeroListHead)
           {
              zeroListHead = node;
              zeroListNode = node;
           }
           else
           {
              zeroListNode->next = node;
              zeroListNode = node;
           }
       } 
       else if(node->nodeNum == 1)
       {
           if(NULL == oneListHead)
           {
              oneListHead = node;
              oneListNode = node;
           }
           else
           {
              oneListNode->next = node;
              oneListNode = node;
           }
       }
       else if(node->nodeNum == 2)
       {
           if(NULL == twoListHead)
           {
              twoListHead = node;
              twoListNode = node;
           }
           else
           {
              twoListNode->next = node;
              twoListNode = node;
           }
       }
       node = node->next; 
    }

    *head = zeroListHead;
    zeroListNode->next = oneListHead;
    oneListNode->next = twoListHead;
    twoListNode->next = NULL;
}

