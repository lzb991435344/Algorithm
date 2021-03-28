#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**

如果更快的求一个整数k的n次方。如果两个整数相乘并得到结果的时间复杂度为O(1)，
得到整数k的N次方的过程请实现时间复杂度为O(logN)的方法。

给定k和n，请返回k的n次方，为了防止溢出，请返回结果Mod 1000000007的值。

测试样例：
2,3
返回：8
	
*/

const int MOD = 1000000007;
int getPower(int k, int n)
{
	long res = 1;
	long temp = k;
	for (; n > 0 ; n >>= 1)
	{
	// 位运算 若不等于0 说明此时i的二进制末尾为1 要进行计算
		if (n & 1 == 1)
		{
			res *= temp;
		}
		temp = (temp*temp) % MOD;
		res  = res % MOD;
	}
	return res;
}
int main()
{
	cout << getPower(2,6)<< endl;
	getchar();
	return 0;
}