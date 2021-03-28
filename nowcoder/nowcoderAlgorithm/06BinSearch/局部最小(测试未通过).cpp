#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
    定义局部最小的概念。arr长度为1时，arr[0]是局部最小。arr的长度为N(N>1)时，如果arr[0]<arr[1]，那么arr[0]是局部最小；
  如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；如果0<i<N-1，既有arr[i]<arr[i-1]又有arr[i]<arr[i+1]，
  那么arr[i]是局部最小。 给定无序数组arr，已知arr中任意两个相邻的数都不相等，写一个函数，只需返回arr中任意一个局部最小出现的位置即可。
*/

//使用二分缩小范围进行查找


int getLessIndex(vector<int> arr)
{
	if (arr.size() < 0)
	{
		return -1;
	}
	
	int len = arr.size();
	if(arr.size() == 1)
	{
		return 0;
	}
	else	
	{ 
		if (arr[1] >  arr[0])
		{
			return 0;
		}
		if (arr[len-2] > arr[len-1])
		{
			return len - 1;
		}
	 }
	//以下是二分查找部分，加快查找的速度
	int low, high, middle;

	low = 0;
	high = len - 1;

	while (low < high)
	{
		middle = high + (low - high)/2;
		if (arr[middle - 1] > arr[middle - 2] && arr[middle + 1] > arr[middle])
		{
			return middle;
		}
		//优先缩小左边部分
		if (arr[middle] > arr[middle - 1])
		{
			high = middle;
		}
		else if (arr[middle] > arr[middle + 1])
		{
			low = middle;
		}
	}
	return -1;
}
int main()
{
	vector<int> v={6,5,2,4,5};
	cout << getLessIndex(v) << endl;
	getchar();
	return 0;
}