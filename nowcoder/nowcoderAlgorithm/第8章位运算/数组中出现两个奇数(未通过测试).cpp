#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  给定一个整型数组arr，其中有两个数出现了奇数次，其他的数都出现了偶数次，找到这两个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。

给定一个整形数组arr及它的大小n，请返回一个数组，其中两个元素为两个出现了奇数次的元素,请将他们按从小到大排列。

测试样例：
[1,2,4,4,2,1,3,5],8
返回：[3,5]
*/
vector<int> findOddAppearce(vector<int> A, int n)
{
	int e = 0;
	for (int i = 0 ; i < n ; i++)
	{
		e = e ^ A[i];
	}
	
	int flag = 0;

	////寻找2个出现奇数次的数在第几位上不同 假设为第i位
	for (int i = 0 ; i < 32 ; i++)
	{
		flag = (i>>1);
		if (e & flag != 0 )
		{
			break;
		}
	}

	vector<int> res(2,0);
	for (int i = 0; i < n; i++)
	{
		//第一个出现奇数的地方
		if ((A[i] & flag) == flag)
		{
			    
		}
		else
			//第二个出现奇数的位置
		{
			res[1] = res[1] ^ A[i];
		}
	}
	sort(res.begin(),res.end());
	return res;
}
int main()
{
	vector<int> v;
	vector<int> v2;
	int arr[8] = { 1,2,4,4,2,1,3,5 };
	//int arr[8] = { 5,3,1,2,4,4,2,1 };
	for (int i = 0 ; i < 8 ; i++)
	{
		v.push_back(arr[i]);
	}
	v2 = findOddAppearce(v, 8);
	for (vector<int>::iterator it=v2.begin();it!=v2.end();it++)
	{
		cout << *it<< endl;
	}
	getchar();
	return 0;
}