/**
  题目：实现一个栈的逆序，但是只能用递归函数和这个栈本身的pop操作来实现，
而不能自己申请另外的数据结构。 
给定一个整数数组A即为给定的栈，同时给定它的大小n，请返回逆序后的栈。
*/

#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
using namespace std;

class ReverseStack
{
public:

	stack<int> s1;
	// 因为这里使用数组代替栈，所以变成真正的栈的时候需要从末尾压栈
	vector<int> reverseStack(vector<int> A, int n) {
		int i;
		for (i = n - 1; i >= 0; i--)
		{
			//将vector中的元素压栈
			s1.push(A.at(i));
		}
		rev(s1);// 倒序
		vector<int> res;
		while (!s1.empty())// 把元素返回给数组
		{
			//先取得栈顶的元素并压入vector的尾部再弹出当前的栈顶，直至栈为空
			res.push_back(s1.top());
			s1.pop();
		}
		return res;
	}
	//原理：在回溯的时候使用栈返回上一层的值得到逆序的结果
	void rev(stack<int> &s)// 倒序函数
	{
		if (s.empty())
		{
			return;
		}
        // 每次递归获取当前栈中的栈底元素，然后回溯时依次
		//压入栈中就完成倒序的操作了。
		int val = getBottomValue(s);
		printf("888%d",val);
		rev(s);
		s.push(val);
	}
    // 递归函数，用来删除栈底元素并返回栈底元素
	int getBottomValue(stack<int> &s)
	{
		int res = s.top();
		printf("666%d\n", res);
		s.pop();
		if (s.empty())
		{
			return res;
		}
		else
		{
			//递归：获取栈底并删除栈底
			int val = getBottomValue(s);
			printf("777%d\n",val);
			s.push(res);
			return val;
		}
	}
};
int main()
{
	ReverseStack gm;
	vector<int> s = {1,4,2,5};
	vector<int> res;
	res = gm.reverseStack(s,4);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		printf("%d\t", *it);
	}
	getchar();
	system("pause");
	return 0;
}