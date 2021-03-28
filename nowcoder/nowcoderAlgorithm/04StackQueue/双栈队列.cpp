/**
题目：双栈队列
  编写一个类,只能用两个栈结构实现队列,支持队列的基本操作(push，pop)。
给定一个操作序列ope及它的长度n，其中元素为正数代表push操作，
为0代表pop操作，保证操作序列合法且一定含pop操作，请返回pop的结果序列。
测试样例：
  [1,2,3,0,4,0],6
  返回：[1,2]
*/

/**
   ***程序中没有判断输入数据的合理性！***
*/
#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
#include <assert.h> 
using namespace std;

class TwoStack {
public:

	stack<int> s1;
	stack<int> s2;

	vector<int> twoStack(vector<int> ope, int n) {
		int i;
		vector<int> res;
		for (i = 0; i<n; i++)
		{
			//操作规则
			if (ope[i]>0)
			{
				push(ope[i]);
			}
		//假如在这里输入了不合理的数据呢？
		//如vector<int> s={0,1,2,0,3,4};这种测试数据应该要一个判断吧！
			if (ope[i] == 0)
			{
				//if (ope[0] == 0)
				//{
				//	printf("data error!\n");
				//	break;
				//}
			//	else
				//{
                 res.push_back(pop());
				//}	
			}
		}
		return res;
	}
	void push(int value)
	{
		s1.push(value);
	}
	//返回值是要放入res最终结果集的值
	int pop()
	{
    // 如果弹出栈为空，当发生弹出操作时，就要把压入栈中的
    //数据全部转到弹出栈中去
		if (s2.empty())
		{
			//要把s1中的元素压进s2，用循环一个个压入(取栈顶)，然后弹出
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
        // 然后再弹出弹出栈中的数据，返回栈顶数据先
		int t = s2.top();
		//弹出元素
		s2.pop();
		return t;
	}
};
int main()
{
	//vector<int> s = { 1,2,3,0,4,0};
	//vector<int> s = { 1,2,3,0,4,0};
	vector<int> s = { 1,0,3,0,0,0 };
	TwoStack ts;
	vector<int> res=ts.twoStack(s,6);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		printf("%d\t", *it);
	}
	getchar();
	system("pause");
	return 0;
}