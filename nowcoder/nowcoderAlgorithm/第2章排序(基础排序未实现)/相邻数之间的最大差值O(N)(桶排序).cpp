#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
 有一个整形数组A，请设计一个复杂度为O(n)的算法，算出排序后相邻两数的最大差值。
给定一个int数组A和A的大小n，请返回最大的差值。保证数组元素多于1个。

测试样例：[1,2,5,4,6],5
返回：2
  设我们需要N+1个桶来存储N个数，找出N个数中的最大值max和最小值min，将[min,max]区间划分为N个桶，
每个桶的宽度是(max-min)/N。在遍历数组的过程中将数字放到相应的桶中，由于我们用N+1个桶来存放N个数，
所以必然会出现空桶，显然空桶两侧的数字的差值是大于桶内的数字的差值的，所以我们需要找到空桶两侧的桶，
用左侧的桶的最大值和右侧的桶的最小值进行比较。
*/

//返回最大值
int _max(int a , int b)
{
	return a > b ? a : b;
}

//返回最小值
int _min(int a , int b)
{
	return a < b ? a : b;
}


int maxGap(vector<int> A , int n)
{
	int max = A[0];
	int min = A[0];
	//找出数组中的最大最小值
	for (int i = 0 ; i <  n ; i++)
	{
		if (A[i]>max)
		{
			max = A[i];
		}
		if (A[i]<min)
		{
			min = A[i];
		}
	}
	if (max == min)
	{
		return 0;
	}

	    vector<int> maxs(n,INT_MIN);
		vector<int> mins(n,INT_MAX);

        
		int len = max - min;
		for (int i = 0 ; i < n ; i++)
		{
			int bid = (double)(A[i]-min) / len*(n - 1);
			//更新最大最小值
			maxs[bid] = _max(maxs[bid] , A[i]);
			mins[bid] = _min(mins[bid] , A[i]);
		}

		int res = 0;
		int pre = maxs[0];
		for (int i = 0 ; i < n ; i++)
		{
			//桶中含有元素
			if (mins[i] != INT_MAX)
			{
				res = _max(res, mins[i] - pre);//后一个桶最小值-前一个桶最大值
				pre = maxs[i];//更新最大值为当前桶最大值，然后i+1那么就变成前一个桶
			}
		}
		return res;
}

int main()
{
	vector<int> v;
	int arr[] = { 1,2,5,4,6 };
	for (int i = 0 ; i < 5 ; i++)
	{
		v.push_back(arr[i]);
	}
	cout << maxGap(v,5)<< endl;
	getchar();
	return 0;
}