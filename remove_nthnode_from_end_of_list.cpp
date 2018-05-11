#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::logic_error;

//*******************************************
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(0){}	
};
//********************************************/

/********************************************************************
解法： 1)考虑输入异常情况：空链表， 删除结点位置非法
	   2)考虑只有一个结点情况
	   3)考虑删除尾结点情况
*********************************************************************/
ListNode* removeNthNodeFromEndOfList(ListNode *head, int n)
{
	if( head==NULL || n<=0 )
		throw logic_error("Invalid Input\n");

	ListNode **slow = &head, **fast = &head;

	int index=1;
	for( ; index<n && (*fast != NULL); ++index )
	{
		*fast = (*fast)->next;
	}

	if( index < n ) //链表长度小于n
	{
		throw logic_error("Numbers of list nodes less than needed deleted node\n");
	}

	while((*fast)->next != NULL)
	{
		(*slow) = (*slow)->next;
		(*fast) = (*fast)->next;
	}

	//只有一个结点
	if( (*slow)==head && (*fast)==head && (*slow)->next==NULL )
	{
		cout << "There is one node, delete it\n";
		delete *slow;
		*slow = NULL;
		return *slow;
	}
	//删除结点为尾结点
	else if( slow==fast && (*slow)->next==NULL )
	{
		cout << "delete tail node\n";
		delete *slow;	
		*slow = NULL;
	}
	else
	{
		(*fast) = (*slow)->next;
		(*slow)->val = (*slow)->next->val;
		(*slow)->next = (*slow)->next->next;
		delete *fast;
	}

	return head;
}

int main(int argc, char const *argv[])
{
	//ListNode *head = new ListNode(1);
	ListNode *head = new ListNode(1);
	ListNode  **temp = &head;
	delete *temp;
	*temp = NULL;
	cout << head << endl;
	
/*
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(3);
	ListNode *node3 = new ListNode(4);
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
*/

/*
	try
	{
		if( removeNthNodeFromEndOfList(NULL, 2) == NULL )
			cout << "null list\n" << endl;	
	}
	catch(logic_error &e)
	{
		cout << e.what() << endl;
	}

*/
	return 0;
}
