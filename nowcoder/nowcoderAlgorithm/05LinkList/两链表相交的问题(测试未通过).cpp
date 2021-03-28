/**
  题目：给定两个单链表的头节点head1和head2，如何判断两个链表
是否相交？相交的话返回true，不相交的话返回false。给定两个
链表的头结点head1和head2(注意，另外两个参数adjust0和adjust1
用于调整数据,与本题求解无关)。请返回一个bool值代表它们是否
相交。

  解析：假设list1的入环结点为node1，list2的入环结点为node2,
  (1)一个为空，一个不为空，则不可能相交
  (2)都为空，则两个链表无环
  (3)两个都不为空，则有环
*/

#include <iostream>
#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class ChkIntersection {
public:
	bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
		// write code here
		ListNode* head1circle = getCircleHead(head1);// 获得入环头结点
		ListNode* head2circle = getCircleHead(head2);// 获得入环头结点

		ListNode* p1 = head1;
		ListNode* p2 = head2;
      // 可能是两个无环链表相交问题 也可能是两个有环链表在入环之前相交的问题
		while (p1 != head1circle&&p2 != head2circle)
		{
			if (p1 == p2)
			{
				return true;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		if (head1circle == head2circle)
		{
			return true;
		}

		p1 = head1circle->next;
        // 在入环之后相交 或者两者不相交
		while (p1 != head1circle)
		{
			if (p1 == head2circle)
			{
				return true;
			}
			p1 = p1->next;
		}
		return false;
	}
	//找到List1的最后一个结点，将其next指向List2的表头。这样若链表相交
	//则会构成环，不相交的话就不会构成环。
	ListNode* getCircleHead(ListNode* head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* fast = head->next;
		ListNode* slow = head;

		while (fast != slow)
		{
			if (fast == NULL || fast->next == NULL)
			{
				return NULL;
			}
			//快指针走两步
			//慢指针走一步
			fast = fast->next->next;
			slow = slow->next;
		}
		//快指针指向头结点
		fast = head;
		//慢指针继续走
		slow = slow->next;

		//这时候快慢指针都走一步
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		//快指针指向的节点就是入环结点
		return fast;
	}
};


int main()
{
	ListNode*head1 = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(4);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(5);

	head1->next = node1;
	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = NULL;

	ListNode*head2 = new ListNode(0);
	ListNode* node5 = new ListNode(3);
	ListNode* node6 = new ListNode(3);
	ListNode* node7 = new ListNode(3);
	ListNode* node8 = new ListNode(3);

	head2->next = node5;
	node5->next = node6;
	node5->next->next = node7;
	node5->next->next->next = node8;
	node5->next->next->next->next = NULL;

	for (int i = 0; i < 4; i++)
	{
		printf("%d\t", node1->val);
		node1 = node1->next;
	}

	for (int j = 0; j < 4; j++)
	{
		printf("%d\t", node5->val);
		node5 = node5->next;
	}

	ChkIntersection ch;
	bool p;
	p = ch.chkInter(node1, node5, 0, 0);

	printf("6666666666666");
	printf("%d\n",p);
	getchar();
	system("pause");
	return 0;
}