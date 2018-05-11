/*
	合并两个排序的链表，保证合并后的链表依然有序
	测试用例：
		1. 两个链表均为空
		2. 其中一个链表为空
		3. 两个链表均不为空
*/

#include <iostream>


struct ListNode
{
	int _val;
	ListNode *next;
	ListNode(int val):_val(val), next(NULL){}
};

//递归方法
ListNode* MergeTwoSortedListRecursive(ListNode *l1, ListNode *l2)
{
	if( l1==NULL && l2==NULL )
		return  NULL;
	else if( l1==NULL && l2 != NULL )
		return l2;
	else if( l1 != NULL && l2 == NULL )
		return l1;

	ListNode *pMergeHead = NULL;
	if( l1->_val >= l2->_val )
	{
		pMergeHead = l1;
		pMergeHead->next = MergeTwoSortedList(l1->next, l2);
	}
	else
	{
		pMergeHead = l2;
		pMergeHead->next = MergeTwoSortedList(l1, l2->next);
	}

	return pMergeHead;
}
