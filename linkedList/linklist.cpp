#include "linklist.h"

LLNode * createNode(int nodeNum)
{
    LLNode *node = malloc (sizeof(LLNode));
    node->nodeNum = nodeNum;
    node->next = NULL;
    return node;
}

void PrintLinkList(LLNode * head)
{
    LLNode * node = head;
    int i =1;
    while(node != NULL)
    {
       printf("Node: %d, nodeNum: %d\n", i, node->nodeNum);
       node = node->next;
       ++i;
    }
}

LLNode * CreateLinkList(const int arr[], const arrLength)
{
   size_t counter = 0;
   LLNode *head = createNode(arr[counter]);
   LLNode *node = head;
   for(counter=1;counter<arrLength;++counter)
   {
      LLNode *tempNode = createNode(arr[counter]);
      node->next = tempNode;
      node = tempNode;
   }
   return head;
}

LLNode * reverseLinkList(LLNode *node, LLNode **newHead)
{
   if(NULL == node->next)
   {
      *newHead = node;
      return node;
   }
   LLNode * tempNode = reverseLinkList(node->next, newHead);
   tempNode->next = node;
   node->next = NULL;
   return node; 
}
