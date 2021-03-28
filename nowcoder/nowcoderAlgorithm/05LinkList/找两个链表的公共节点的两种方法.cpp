#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
   输入两个链表，输出公共的节点。
有公共节点：如果两个链表有公共节点，那么从第一个公共节点开始 直到链表
结束，这段链表的长度N对两个链表来说长度是一致的，且公共链表必定是从距
离两个链表尾向前N（公共部分的节点个数）个节点的位置的下一位置开始的。
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

int getLength(ListNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int size = 0;
	//计算链表的长度
	while (root!=NULL)
	{
		root = root->next;
		size++;
	}
	return size;
}
ListNode* findCommonValue(ListNode* pHead1 , ListNode* pHead2)
{
	ListNode* head1 = pHead1;
	ListNode* head2 = pHead2;
	//获取两个链表的长度
	int len1 = getLength(head1);
	int len2 = getLength(head2);
	//指向头指针
	head1 = pHead1;
	head2 = pHead2;

	//在较长的链表上进行遍历
	if(len1 > len2)
	{ 
   // pos变量用处在于：在距离两个链表的进入公共节点之前
   //距离的前pos个位置中找到公共值，并且必须在较长的链表中开始进行遍历
		int pos = len1 - len2;
		while (pos > 0)
		{
			head1 = head1->next;
			pos--;
		}
	}
	else
	{
		int pos = len2 - len1;
		while (pos > 0)
		{
			head2 = head2->next;
			pos--;
		}
	}
	//找到两个相等的值即停止循环
	while (head1->val != head2->val)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1;
}
/**
假设链表一的长度为N，链表二的长度为M，Q为链表一和链表二长度差的绝对值。
N+M=M + N; <1>
if N>M，so N = M+Q;代入（1），N+M = N+(N-Q) = N-Q+N = M+N.;
else if N<M, so M = N+Q;代入（1），N+M = N+N+Q = N+Q+N = M+N;
else M=N, Q=0.
**/
ListNode* findCommonTest(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	while (p1!=p2)
	{
		if (p1!=NULL)
		{
			p1 = p1->next;
		}
		if (p2!=NULL)
		{
			p2 = p2->next;
		}
		if (p1!=p2)
		{
			if (p1 == NULL) { p1 = pHead2; }
			if (p2 == NULL) { p2 = pHead1; }
		}
	}
	return p1;
}
int main()
{
	ListNode p1(5);
	ListNode p2(4);
	ListNode p3(3);
	ListNode p4(2);
	ListNode p5(1);

	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	p5.next = NULL;

	ListNode* tmp = findCommonValue(&p1, &p3);
	//ListNode* tmp =findCommonTest(&p1, &p3);
	cout << tmp->val<< endl;
	getchar();
	return 0;
}