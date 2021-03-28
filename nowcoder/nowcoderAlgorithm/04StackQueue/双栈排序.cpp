/**
题目：双栈排序
 请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多
只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。

  给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，
请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到
第一个元素。

测试样例： 
[1,2,3,4,5] 
返回：[5,4,3,2,1]
*/

#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
#include <assert.h> 
using namespace std;

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) 
	{
		stack<int> s;// 原始数据栈,把数组变成栈
		stack<int> help;// 辅助栈
		//倒序将vector中的元素压入stack
		for (int i = numbers.size() - 1; i >= 0; i--) 
		{// 初始化栈
			s.push(numbers[i]);
		}

		while (!s.empty()) 
		{// 当数据栈不空时 一直弹出元素
			int top = s.top();
			s.pop();
            // 此时辅助栈中栈顶元素小于数据栈顶元素时，压栈
			//当help栈为空时是第一次去数据的时候，第二个条件是把辅助栈的元素全部压回数据栈的时候，
			//此时辅助栈是当前最小，比较时把数据栈中所有大于辅助栈中的元素放回辅助栈
			if (help.empty() || top >= help.top())
			{
				help.push(top);
				continue;
			}
           // 若辅助栈顶元素一直大于数据栈顶元素则一直弹出辅助栈元素
			while (!help.empty() && top < help.top()) 
			{
				s.push(help.top());
				help.pop();
			}
			//这步用于将弹出当前help栈中比数据栈栈顶大的元素值之后，
			//放入数据栈的栈顶（当前最小）
			help.push(top);
		}

		vector<int> res;
		//这个循环用于将辅助栈中的内容放入vector对象
		while (!help.empty())
		{
			res.push_back(help.top());
			help.pop();
		}
		return res;
	}
};

int main()
{
	//vector<int> s = { 1,2,3,0,4,0};
	//vector<int> s = { 1,2,3,0,4,0};
	vector<int> s = { 1,2,3,4,5 };
	TwoStacks ts;
	vector<int> res=ts.twoStacksSort(s);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		printf("%d\t", *it);
	}
	getchar();
	system("pause");
	return 0;
}