#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  有一个整型数组A，其中只有一个数出现了奇数次，其他的数都出现了偶数次，请打印这个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。

给定整形数组A及它的大小n，请返回题目所求数字。

测试样例：
[1,2,3,2,1],5
返回：3
*/
int findOddAppearce(vector<int> A, int n)
{
	int e = 0;
	//按位异或运算
	for (int i=0 ; i < n ; i++)
	{
		e = e ^ A[i];
		/*1 3 0 2 3*/ //3
		cout << e<< endl;
	}
	return e;
}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2); 
	v.push_back(1);
	cout << findOddAppearce(v,5)<< endl;
	getchar();
	return 0;
}