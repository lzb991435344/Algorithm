/**
题目：滑动窗口
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共
存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组
{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

  思路：用双端队列，实现窗口最大值的更新，生成双端队列，qmax={},
双端队列中存放着数组中的下标值，假设当前数为arr[i]，放入规则如下：
1、如果qmax为空，直接把下标i放入qmax中
2、如果qmax不为空，去当前qmax存放的下标j，如果arr[j]>arr[i]，
直接把下标i放进qmax的队尾，放入过程直接结束。
3、如果arr[j]<=arr[i]，则一直从amax的队尾弹出下标，知道某个下标
在array中对应的值大于arr[i]，把i放入qmax的队尾。
假设当前数组arr[i]，弹出规则为：
如果qmax对头的下标等于i-w,说明当前队头下标已经过期，则弹出qmax
当前队头下标，根据如上放入弹出规则，可知qmax成为一个维护窗口为w的
子数组最大值的更新结构。
*/

#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
#include <assert.h> 
using namespace std;

class SlideWindow 
{
public:
	vector<int> slide(vector<int> arr, int n, int w)
	{
		vector<int> res;
		deque<int> dq;
		for (int i = 0; i<n; i++) 
		{
           //当队列为空或者队尾索引下的元素大于数组元素，则入队索引
			if (dq.empty() || arr[dq.back()]>arr[i])
				dq.push_back(i);
			else
			{
           //否则就一直出队
				while (!dq.empty() && arr[dq.back()]<arr[i]) {
					dq.pop_back();
				}
				dq.push_back(i);
			}
			//赋值最大值数组
			if (i >= w - 1) 
			{
				while (!dq.empty() && i - dq.front() > w - 1)
					dq.pop_front();
				res.push_back(arr[dq.front()]);
			}
		}
		return res;
	}
};

int main()
{
	//vector<int> s = { 1,2,3,0,4,0};
	//vector<int> s = { 1,2,3,0,4,0};
	vector<int> s = { 1,2,3,4,5 };
	SlideWindow sw;
	vector<int> res = sw.slide(s,5,3);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		printf("%d\t", *it);
	}
	getchar();
	system("pause");
	return 0;
}