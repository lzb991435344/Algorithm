#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
    循环有序数组的最小值

	对于一个有序循环数组arr，返回arr中的最小值。有序循环数组是指，有序数组左边任意长度的部分放到右边去，
	右边的部分拿到左边来。比如数组[1,2,3,3,4]，是有序循环数组，[4,1,2,3,3]也是。
	给定数组arr及它的大小n，请返回最小值。

	测试样例：
	[4,1,2,3,3],5
	返回：1
*/

int min(int a , int b)
{
	return a < b ? a : b;
}

int getMin(vector<int> arr,int n)
{
	if (n == 1 )
	{
		return arr[0];
	}
	int low = 0;
	int high = n - 1;
	int middle;
	//表明有序
	if (arr[low] < arr[high])
	{
		return arr[0];
	}
	int res = 0;
	while (low <= high)
	{
		middle = high+(low-high) / 2;
		if (high-low == 1)
		{
			// 当数组中只有两个元素时 返回小的那个
			res = min(arr[high],arr[low]);
			break;
		}
		//缩小范围
		if (arr[low]> arr[middle])
		{
			high = middle;
		}
		//缩小范围
		else if (arr[high]>arr[middle])
		{
			low = middle;
		}
		//介于两者之间
		else if (arr[middle]>arr[low] && arr[middle]<arr[high])
		{
			res = arr[low];
			//在low-high 之间找出最小值
			for (int i = low ; i < high ; i++)
			{
				if (res>arr[i])
				{
					res = arr[i];
				}
			}
		}
	}
	return res;
}
int main()
{
	vector<int> v = { 4,1,2,3,3 };
	cout << getMin(v,5) << endl;
	getchar();
	return 0;
}