#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
  从尾到头打印链表
*/

struct ListNode
{
	int val;
	struct ListNode* link;
   // ListNode(int x): val(x),link(NULL) {}

};
class  printListFromTailToHead
{
public:
	//设置为成员变量，不可放在函数中定义，否则每次都要传入
    vector<int> res;
	//递归实现
	vector<int> printWithRecurrsion(struct ListNode* head)
	{		
		if (head != NULL)
		{
			printWithRecurrsion(head->link);
			res.push_back(head->val);
		}
		return res;
	}
	//使用栈实现
	vector<int> printWithRegular(struct ListNode* head)
	{
		ListNode* node = head;
		stack<int> s;
		int count = 0;

		while (node)
		{
			//数据压栈
			s.push(node->val);
			count++;//计算数据的总数
			node = node->link;
		}

		vector<int> res(count);
		for (int i = 0 ; (i < count) && (!s.empty()) ; i++ )
		{
			//取栈顶
			res[i] = s.top();
			s.pop();
		}
		return res;
	}

};

int main()
{

      ListNode list[4];
	//struct ListNode* list;
	
	list[0].val = 1;
	list[0].link = &list[1];
	list[1].val = 2;
	list[1].link = &list[2];
	list[2].val = 3;
	list[2].link = &list[3];
	list[3].val = 4;
	list[3].link = NULL;


	printListFromTailToHead pt;
	vector<int>  res;
	//res = pt.printWithRecurrsion(list);
	res = pt.printWithRegular(list);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]<< endl;
	}
	system("pause");
	getchar();
	return 0;
}