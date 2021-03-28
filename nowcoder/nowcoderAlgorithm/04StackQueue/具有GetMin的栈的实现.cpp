/**
  题目：实现一个带有取最小值min方法的栈，min方法将返回当前栈中的最小值。

你实现的栈将支持push，pop 和 min 操作，所有操作要求都在O(1)时间内完成
*/

#include <iostream>
#include<stdio.h>
#include <stack>
using namespace std;

class GetMin
{
public:
	//两个栈中的元素相等
	stack<int> stack_data;
	stack<int> stack_min;

	void push(int value)
	{
		stack_data.push(value);
		//min栈不为空或者当前push入栈的值小于min的栈顶
		if (stack_min.empty() || value < stack_min.top())
		{
			stack_min.push(value);
		}
		else
		{
			//放入min栈的栈顶
			stack_min.push(stack_min.top());
		}
	}
	void pop()
	{
		if (!stack_data.empty())
		{
			stack_data.pop();
			stack_min.pop();
		}

	}
	int top()
	{
		return stack_data.top();
	}
	int  min()
	{
		return stack_min.top();
	}
};
int main()
{
	GetMin gm;
	gm.push(4);
	gm.push(2);
	gm.push(1);
	gm.push(9);

	printf("%d\n", gm.min());
	getchar();
	system("pause");
	return 0;
}