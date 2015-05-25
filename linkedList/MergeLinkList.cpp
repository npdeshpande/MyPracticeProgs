#include "linklist.h"
#include <stack>

using namespace std;
 
size_t GetLinkListLength(LLNode *node)
{
    size_t length = 0;
    while(node != NULL)
    {
        node = node->next;
        ++length;
    }
    return length;
}

LLNode * GetNodeAtPosition(LLNode * head, size_t joinAtPosition)
{
    LLNode * node = head;
    size_t counter = 0;
    while((node != NULL) && (counter < joinAtPosition-1))
    {
        node = node->next;
        ++counter;
    }
    return node;
}

void JoinSmallListNodeToBigListAtCommonNode(LLNode *commonNode, LLNode *smallListHead)
{
   LLNode * node = smallListHead;
   while(node->next != NULL)
   {
      node = node->next;
   }
   node->next = commonNode;
}

void mergeOfLinkList(LLNode * firstHead, LLNode * secondHead, size_t joinAtPosition)
{
    LLNode * bigListhead = firstHead;
    LLNode * smallListhead = secondHead;
    size_t firstLength = GetLinkListLength(firstHead);
    size_t secondLength = GetLinkListLength(secondHead);

    if((firstLength < joinAtPosition) && (secondLength < joinAtPosition))
    {
       printf("None of list length is more than position.\n");
       return;
    }

    if(firstLength < secondLength)
    {
        //swap ptrs
	bigListhead = secondHead;
	smallListhead = firstHead;
    }

    // join at position
    LLNode * commonNode = GetNodeAtPosition(bigListhead, joinAtPosition);
    printf("common Node: %d, at position: %ld\n", commonNode->nodeNum,joinAtPosition);
    JoinSmallListNodeToBigListAtCommonNode(commonNode, smallListhead);
}


//identify common Node and print.
LLNode * GetCommonNode_Approach_1(LLNode * firstHead, LLNode * secondHead)
{
    size_t firstLength = GetLinkListLength(firstHead);
    size_t secondLength = GetLinkListLength(secondHead);
    
    LLNode * bigListHead = firstHead;
    LLNode * smallListHead = secondHead;
    int diff = firstLength - secondLength;
    if(diff < 0)
    {
        bigListHead = secondHead;
        smallListHead = firstHead;
        diff = secondLength - firstLength;
    }

    LLNode * bigListNode = bigListHead;
    while(bigListNode && (diff != 0))
    {
        --diff;
        bigListNode = bigListNode->next;
    }

    LLNode *firstListNode = bigListNode;
    LLNode *secondListNode = smallListHead;
    while((firstListNode != NULL) && (secondListNode != NULL))
    {
       if(firstListNode == secondListNode)
        break; 
       
       firstListNode = firstListNode->next;
       secondListNode = secondListNode->next;
    }

    printf("CommonNode data: %d\n", firstListNode->nodeNum);
    return firstListNode;
}


LLNode * GetCommonNode_Approach_2(LLNode * firstNode, LLNode * secondNode)
{
    std::stack<LLNode *> firstStack;
    std::stack<LLNode *> secondStack;
   
    LLNode * node = firstNode;
    while(node != NULL)
    {
       firstStack.push_back(node);
       node = node->next;
    }
 
    node = secondNode;
    while(node != NULL)
    {
       secondStack.push_back(node);
       node = node->next;
    }

   
   
   std::stack<LLNode *>::iterator fIter=firstStack.begin();
   std::stack<LLNode *>::iterator sIter=secondStack.begin();
   for(;fIter!=firstStack.end() && sIter != secondStack.end(); ++firstStack,secondStack) 
   {
       if(*fIter == *sIter)
         return *fIter;
   }
   
   printf("No common node found.\n");
   return NULL;
}
