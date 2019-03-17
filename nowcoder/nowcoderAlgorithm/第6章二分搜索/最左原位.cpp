#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**

有一个有序数组arr，其中不含有重复元素，请找到满足arr[i]==i条件的最左的位置。如果所有位置上的数都不满足条件，返回-1。
给定有序数组arr及它的大小n，请返回所求值。

测试样例：

[-1,0,2,3],4
返回：2
	
*/

int findPos(vector<int> arr, int n) {

	if (arr[0] > n - 1 || arr[n - 1] < 0)
	{
		return -1;
	}

	int res = -1;

	int low, high, middle;

	low = 0;
	high = n - 1;

	while (low <= high)// 二分搜索
	{
		middle = low + (high - low) / 2;

		if (arr[middle] == middle)// 当i==arr[i]时记录 下标 继续左半部分搜索
		{
			//左边部分有可能还会存在
			res = middle;
			high = middle - 1;
		}
		// 因为是有序无重复元素数组 若此时元素大于下标 而下标的增加是1 
		//元素最小的变化也是1索引不可能再出现相等的情况
		else if (arr[middle] > middle)
		{
			high = middle - 1;
		}
		else if (arr[middle] < middle)// 同理 缩小范围到右半部分
		{
			low = middle + 1;
		}
	}
	return res;
}

int main()
{
	vector<int> arr = { -1,0,2,3 };
	cout << findPos(arr,3) << endl;
	getchar();
	return 0;
}