#include <iostream>
#include <vector>
using namespace std;

/**
  有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。 
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。 
测试样例： 
[1,3,4,5,7],[1,2,3,4,0],2 
返回：{1,2,3,4,5,7}
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode* pList;
//创建新链表
ListNode* createList(vector<int> A, vector<int> nxt)
{
	ListNode* root = new ListNode(A[0]);
	ListNode* temp = root;

	for (int i = 0; i < A.size(); i++)
	{
		root->next = new ListNode(A[i]);
		root = root->next;
	}
	return temp;
}
ListNode* insert(vector<int> A, vector<int> nxt ,int val)
{
	ListNode* root = createList(A,nxt);

	ListNode* pre = root;
	ListNode* cur = root->next;

	ListNode* node = NULL;

	while (cur->next!=NULL)
	{
		//在于pre和cur之间
		if (node->val >= pre->val && node->val <= cur->val)
		{
			node = new ListNode(val);
			pre->next = node;
			node->next = cur;
		}
		pre = pre->next;
		cur = cur->next;
	}
  //最大值，尾插入
	if (node == NULL)
	{
		node = new ListNode(val);
      if (node->val >= pre->val)
	  {
		pre->next = node;
		node->next = NULL;
	   }
	  //最大值，头插法
	else if (node->val <= root->val)
	  {
		node->next = root;
		pre->next = NULL;
	  }
     }
	return root;
}

int main()
{
	vector<int> A = { 1,3,4,5,7 };
	vector<int> nxt = { 1,2,3,4,0 };
	ListNode* tmp = createList(A,nxt);
	tmp=insert(A, nxt, 2);
	for (int i=0;i<5;i++)
	{
		cout << tmp->val<< endl;
	}
	
	getchar();
	return 0;
}