/**
题目：对于一个链表，我们需要用一个特定阈值完成对它的分化，
使得小于等于这个值的结点移到前面，大于该值的结点在后面，同时保证
两类结点内部的位置关系不变。

给定一个链表的头结点head，同时给定阈值val，请返回一个链表，
使小于等于它的结点在前，大于等于它的在后，保证结点值不重复。

测试样例：

{1,4,2,5},3

{1,2,4,5}

*/

#include <iostream>
#include<stdio.h>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
/**
思路：初始化3个链表，small,cur,big,分别用于存放小于，等于，大于val的值
然后在

*/


class Divide {
public:
	ListNode* listDivide(ListNode* head, int val) {
		// write code here
		// 分别创建大于 等于 小于三个头结点
		ListNode *small = new ListNode(0);
		ListNode *big = new ListNode(0);
		ListNode *cur = head->next;
		//大于val节点的头指针指向big
		ListNode *bighead = big;
		//小于val节点的头指针指向small
		ListNode *smallhead = small;
		while (cur !=NULL)
		{
			//当前的值小于等于val值
			if (cur->val <= val)
			{
				//当前的small的下一个指针指向等于val的指针cur
				small->next = cur;
				small = small->next;
			}
			//cur的值比val大
			if (cur->val > val)
			{
				big->next = cur;
				big = big->next;
			}

			cur = cur->next;
		}
		//small和big两个链表之间的连接
		small->next = bighead->next;
		big->next = NULL;

		//返回链表
		return smallhead->next;

	}
};

int main()
{
	ListNode*head=new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(4);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(5);

	head->next = node1;
	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = NULL;
	
	for (int i = 0; i<4; i++)
	{
		printf("%d\t",node1->val);
		node1 = node1->next;
	}

    Divide di;
	ListNode*p = NULL;
	p = di.listDivide(head,3);

	for (int i=0;i<4;i++)
	{
		printf("%d\t", p->val);
		p = p->next;
	}
	getchar();
	system("pause");
	return 0;
}