// TrainingCode.cpp: 定义控制台应用程序的入口点。
//
/**
题目：判断一个链表是否为回文结构。
要求：时间复杂度为 O(n)，空间时间复杂度为O(1)。

思路分析：回文链表的特点就是对称，那么要判断是否回文，就可以用两个指针
指向对称的节点，看它们的数据是否一样。由于是单向链表，不能同时用两个指针，
从头尾向内部遍历取值比较。且本题对空间复杂度也有要求，所以可用如下方法实现。
具体步骤如下：
（1）先得到链表的中间节点；
（2）从中间节点的下一个节点开始，反转链表。
（3）从中间节点处，断开原链表。
（4）用两个指针分别向两个端点移动，同时进行比较，数据相同则继续，
数据不同则直接返回false。直到遍历完成，最后返回true。

*/
#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) {
		// write code here
		ListNode *fast = pHead;
		ListNode *slow = pHead;
        // 建立快慢指针 快指针一次走两个 慢指针一次走一个
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	    //辅助节点
		ListNode *prev = NULL;

       // 此时慢指针在中心，从中间开始反转剩下链表
		//这里反转是值改变指针的指向：如 1 -> 2 -> 3 <- 2 <- 1
		//将两处地方先断链，再连接起来
		while (slow != NULL)
		{
			//给新节点赋值
			ListNode *next = slow->next;

			//这两步将节点的指针进行反转，即断链+重连
			slow->next = prev;//先赋给辅助节点
			prev = slow;//辅助节点再重新指向中间的节点

			//slow指向next，处理剩下的需要反转的指针
			slow = next;
		}

		ListNode *p = pHead;
    // 判断从头开始到中间和从末尾开始到中间的这两个链表是否相等，
   //若相等则说明是回文结构
		while (prev)
		{
			//反转之后进行遍历
			if (prev->val == p->val)
			{
				prev = prev->next;
				p = p->next;
			}
			else
			{
				return false;
			}
		}
		return true;
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

	Palindrome pd;
	cout <<pd.isPalindrome(node1) << endl;
	getchar();
	system("pause");
	return 0;
}

