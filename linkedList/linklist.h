#include "stdio.h"
#include "stdlib.h"

struct LLNode
{
    int nodeNum;
    struct LLNode * next;
};

typedef struct LLNode LLNode;

LLNode * createNode(int nodeNum);

void PrintLinkList(LLNode * head);
LLNode * CreateLinkList();
LLNode * reverseLinkList(LLNode *node, LLNode **newHead);
void mergeOfLinkList(LLNode * firstHead, LLNode * secondHead, size_t joinAtPosition);
LLNode * GetCommonNode_Approach_1(LLNode * firstHead, LLNode * secondHead);
void sort_0_1_3_LinkList(LLNode ** head);
