// TrainingCode.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

/**
访问单个节点的删除
(1)头结点
(2)中间节点
(3)尾节点
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//返回删除后的头结点
ListNode* removeNode(ListNode* pHead, int delVal) {
	ListNode * temp = pHead;
	//首先判断头节点是否为要被删除节点
	if (pHead->val == delVal) {
		pHead = pHead->next;
		return pHead;
	}
	//当被删除节点存在中间部分时
	while (temp->next != NULL) {
		if (temp->next->val == delVal) {
			temp->next = temp->next->next;
			return pHead;
		}
		temp = temp->next;
	}

	//被删除节点为尾节点时，直接赋值为null
	if (temp->next == NULL) {
		temp = NULL;
	}
	return pHead;
}

int main()
{
	//ListNode*head = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);

	//head->next = node1;
	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;
	node1->next->next->next->next->next = node6;
	node1->next->next->next->next->next->next = node7;
	node1->next->next->next->next->next->next->next = NULL;

	ListNode*p = NULL;
	p = removeNode(node1,5);

	for (int i=0;i<6;i++)
	{
		cout << p->val<< endl;
		p = p->next;
	}
	getchar();
	system("pause");
	return 0;
}

