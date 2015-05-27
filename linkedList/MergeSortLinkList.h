class MergeSortLinkList
{
public:
	MergeSortLinkList(LLNode *head);
	LLNode * Sort(LLNode *node);
private:
	void SplitList(LLNode *head, LLNode **firstList, LLNode ** secondList);
	LLNode * MergeList(LLNode *firstList, LLNode* secondList);

	LLNode *m_head;
};
