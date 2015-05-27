#include "linklist.h"
#include "MergeSortLinkList.h"

MergeSortLinkList::MergeSortLinkList(LLNode *head)
{
	m_head = head;
}

void MergeSortLinkList::SplitList(LLNode *head, LLNode **firstList, LLNode ** secondList)
{
	if(!head || !head->next)
	{
		*firstList = head;
		*secondList = NULL;
		return;
	}

	*firstList = head;

	LLNode *singleNodeJump = head;
	LLNode *doubleNodeJump = head->next;
	while(doubleNodeJump != NULL && doubleNodeJump->next != NULL)
	{
		doubleNodeJump = doubleNodeJump->next->next;
		singleNodeJump = singleNodeJump->next;
	}
	*secondList = singleNodeJump->next;
	singleNodeJump->next = NULL;
}

LLNode *MergeSortLinkList::Sort(LLNode *node)
{
	printf("In Sort node->nodeNum:%d\n" ,node->nodeNum);

	//if node is NULL, return NULL
	if(node == NULL || node->next == NULL)
		return node;

	//SplitList node as firstlist, secondlist
	LLNode *firstList = NULL;
	LLNode *secondList = NULL;
	SplitList(node, &firstList, &secondList);

	printf("firstList->nodeNum:%d, secondList->nodeNum:%d\n" ,firstList->nodeNum, secondList->nodeNum);

	// sort first list,second list.
	LLNode *sortedFirstList = Sort(firstList);
	printf("firstList->nodeNum:%d\n" ,sortedFirstList->nodeNum);

	LLNode *sortedSecondList = Sort(secondList);
	printf("secondList->nodeNum:%d\n" ,sortedSecondList->nodeNum);

	//merge first and second list.
	return MergeList(sortedFirstList, sortedSecondList);
}

LLNode * MergeSortLinkList::MergeList(LLNode *firstList, LLNode* secondList)
{
	if(! firstList)
		return secondList;
	else if(! secondList)
		return firstList;

	LLNode *mergeListHead = firstList;
	if(firstList->nodeNum > secondList->nodeNum)
	{
		mergeListHead = secondList;
		secondList = secondList->next;
	}
	else
	{
		mergeListHead = firstList;
		firstList = firstList->next;
	}

	LLNode *mergeList = mergeListHead;
	while(firstList != NULL && secondList != NULL)
	{
		if(firstList->nodeNum > secondList->nodeNum)
		{
			mergeList->next = secondList;
			mergeList = secondList;
			secondList = secondList->next;			
		}
		else
		{
			mergeList->next = firstList;
			mergeList = firstList;
			firstList = firstList->next;
		}
	}

	if(firstList || secondList)
	{
		if(! firstList)
			mergeList->next = secondList;
		if(! secondList)
			mergeList->next = firstList;
	}

	if(!firstList && !secondList)
		mergeList->next = NULL;

	return mergeListHead;
}

