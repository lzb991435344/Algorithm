/**
题目：滑动窗口
对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，
MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对
于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，
对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数
和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么
它就是树根。请设计O(n)的算法实现这个方法。

给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素
为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。

测试样例：
[3,1,4,2],4
返回：[2,0,-1,2]

*/

#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
#include <assert.h> 
using namespace std;
class MaxTree {
public:
	vector<int> buildMaxTree(vector<int> A, int n) {

		vector<int> res;
		for (int i = 0; i<n; i++) {//遍历每个值去获取结果
			res.push_back(getIndex(i, A, n));
		}

		return res;
	}

	int getIndex(int target, vector<int>A, int n) {
		int right = n;//右边第一个比它大的数索引
		int left = -1;//左边第一个比它大的数索引
		int i;
		//更新右索引
		for (i = target + 1; i<n; i++) {
			if (A[i]>A[target]) {
				right = i;
				break;
			}
		}
        //更新左索引
		for (i = target - 1; i >= 0; i--) {
			if (A[i]>A[target]) {
				left = i;
				break;
			}
		}
       //当两个索引都没变化，说明左右两边都没有比它大的数，
		//根节点返回-1
		if (left == -1 && right == n) 
		{
			return -1;
		}
		//两个索引都发生变化了，此时返回元素更小的那个索引
		else if (left != -1 && right != n) 
		{
			return A[left]>A[right] ? right : left;
		}
		else if (left == -1 && right != n) 
		{//右索引有变化，左索引没有。说明右边更小并返回
			return right;
		}
		else if (left != -1 && right == n)
		{//同理 返回左边
			return left;
		}
		return 0;//为了牛客网OJ需要一个返回值
	}
};

int main()
{
	//vector<int> s = { 1,2,3,0,4,0};
	//vector<int> s = { 1,2,3,0,4,0};
	vector<int> s = { 3,1,4,2 };
	MaxTree mt;
	vector<int> res = mt.buildMaxTree(s,4);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		printf("%d\t", *it);
	}
	getchar();
	system("pause");
	return 0;
}