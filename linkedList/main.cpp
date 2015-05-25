#include "linklist.h"

void reverseLLSample()
{
   int arr[] = { 10, 4, 5, 7, 111, 75 };
   LLNode * head = CreateLinkList(arr, sizeof(arr)/sizeof(arr[0]));
   printf("actual linked list\n");
   PrintLinkList(head);
   printf("after reversing linked list\n");
   LLNode * newHead = NULL;
   reverseLinkList(head, &newHead);
   PrintLinkList(newHead);
}

void DemoForMergeLinkList()
{
   int arr1[] = { 2, 4, 6, 8 };
   LLNode * head1 = CreateLinkList(arr1, sizeof(arr1)/sizeof(arr1[0]));
   int arr2[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
   LLNode * head2 = CreateLinkList(arr2, sizeof(arr2)/sizeof(arr2[0]));
   printf("actual linked list 1\n");
   PrintLinkList(head1);
   printf("actual linked list 2\n");
   PrintLinkList(head2);
   
   mergeOfLinkList(head1, head2, 3); 

   printf("after merging linked list\n");
   printf("linked list 1\n");
   PrintLinkList(head1);
   printf("linked list 2\n");
   PrintLinkList(head2);

   //LLNode *commonNode = GetCommonNode_Approach_1(head1, head2);
   LLNode *commonNode = GetCommonNode_Approach_2(head1, head2);
   printf("common: %d\n", commonNode->nodeNum);
}

void DemoForSorting_0_1_2()
{
   int arr[] = { 3, 0, 0, 0, 2, 1, 1, 1, 0 };
   LLNode * head = CreateLinkList(arr, sizeof(arr)/sizeof(arr[0]));
  
   printf("actual linked list 1\n");
   PrintLinkList(head);
   sort_0_1_3_LinkList(&head); 
   printf("after sorting linked list\n");
   PrintLinkList(head);
}

int main(int argc, char *argv[])
{
   DemoForSorting_0_1_2();
   return 0;
}
