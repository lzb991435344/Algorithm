// TrainingCode.cpp: 定义控制台应用程序的入口点。
//
/**
题目：
  有一个单链表。链表中每个节点保存一个整数，给定一个值val，把所有等于val的节点删掉。
给定一个单链表的头结点head，同时给定一个值val，返回清除后的链表的头结点，
保证链表中有不等于该值的其它值。同时保证其他元素的相对顺序。
 如：输入：{1,2,3,4,3,2,1},2
 输出：{1,3,4,3,1}																					
*/
#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class ClearValue {
public:
	ListNode* clear(ListNode* head, int val) {
 
        // 创建一个指向head的指针
		ListNode *node = new ListNode(0);
		node->next = head;
		ListNode *p = node;
		ListNode *cur = head;
		while (cur != NULL)// 遍历链表 删除目标值
		{
			if (cur->val == val)
			{
				//node节点指向cur的下一个节点
				p->next = cur->next;
			}
			else
			{
				p = p->next;
			}
			cur = cur->next;
		}
		return node->next;
	}
};

int main()
{
	//ListNode*head = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(2);
	ListNode* node5 = new ListNode(1);
	

	//head->next = node1;
	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;
	node1->next->next->next->next->next = NULL;

	ClearValue cv;
	ListNode* p = cv.clear(node1, 2);
	for (int i=0;i<3;i++)
	{
		cout << p->val<< endl;
		p = p->next;
	}
	getchar();
	system("pause");
	return 0;
}

