// TrainingCode.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
using namespace std;

/**
题目：现有两个升序链表，且链表中均无重复元素。
请设计一个高效的算法，打印两个链表的公共值部分。
给定两个链表的头指针headA和headB，请返回一个vector，元素为两个链表的公共部分。
请保证返回数组的升序。两个链表的元素个数均小于等于500。
保证一定有公共值测试样例：{1,2,3,4,5,6,7},{2,4,6,8,10} 返回：[2,4,6]
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Common {
public:
	vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
		// write code here
		vector<int> res;
		if (headA == NULL || headB == NULL)
		{
			return res;
		}
		//都不为空的时候开始循环
		while (headA != NULL && headB != NULL)
		{
			//A元素>B元素，从值小的链表进行遍历
			//因为链表是有序的
			if (headA->val > headB->val)
			{
				headB = headB->next;
			}
			else if (headA->val < headB->val)
			{
				headA = headA->next;
			}
			else
			{
				//两个值相等，直接将该值压入vector中，继续寻找下一个值
				res.push_back(headA->val);
				headA = headA->next;
				headB = headB->next;
			}
		}

		return res;
	}
};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);

	node1->next = node2;
	node1->next->next = node3;
	node1->next->next->next = node4;
	node1->next->next->next->next = node5;
	node1->next->next->next->next->next = node6;
	node1->next->next->next->next->next->next = node7;
	node1->next->next->next->next->next->next->next = NULL;

	ListNode* node8 = new ListNode(2);
	ListNode* node9 = new ListNode(4);
	ListNode* node10 = new ListNode(6);
	ListNode* node11 = new ListNode(8);
	ListNode* node12 = new ListNode(10);

	node8->next = node9;
	node8->next->next = node10;
	node8->next->next->next = node11;
	node8->next->next->next->next = node12;
	node8->next->next->next->next->next = NULL;

	Common co;
	vector<int> res;
	res = co.findCommonParts(node1, node8);

	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		cout << *it << endl;
	}
	getchar();
	system("pause");
	return 0;
}

