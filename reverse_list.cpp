/*
	原地反转链表
	要求：
		1.空间复杂度O(1)
		2.时间复杂度O(n)
*/
#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
	ListNode(int val): m_val(val), m_next(NULL){}
	int m_val;
	ListNode *m_next;
};

ListNode* ReverseListInPlace(ListNode *head)
{
	if( head == NULL )
		return NULL;
	
	ListNode *pCurrent=head;
	ListNode *pPrevious=NULL;
	ListNode *pNext=head->m_next;

	while( pCurrent->m_next != NULL )
	{
		pNext = pCurrent->m_next;	
		pCurrent->m_next = pPrevious;
		pPrevious = pCurrent;
		pCurrent = pNext;
	}
	pCurrent->m_next = pPrevious;
	
	return pCurrent;
}

/*
	测试用例
	1.输入空链表
	2.输入只有一个结点的链表
	3.输入包含多个结点的链表
*/

int main(int argc, char** argv)
{
	ListNode *head = new ListNode(1);
	//ListNode *node1 = new ListNode(2);
	//ListNode *node2 = new ListNode(3);

	//head->m_next = node1;
	//node1->m_next = node2;
	ListNode *p = ReverseListInPlace(head);
	if( p == NULL )
	{
		cout << "null list\n";
		return 0;
	}
	while( p != NULL )
	{
		cout << p->m_val << ' ';
		p = p->m_next;
	}

	delete head;
	cout << endl;
}
