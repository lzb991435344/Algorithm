
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：
    假设函数f()等概率随机返回一个在[0,1)范围上的浮点数，那么我们知道，
  在[0,x)区间上的数出现的概率为x(0<x≤1)。给定一个大于0的整数k，并且
  可以使用f()函数，请实现一个函数依然返回在[0,1)范围上的数，但是在[0,x)区间
  上的数出现的概率为x的k次方。
    思路：调用k次，返回较大的数即可。相当于伯努利试验，在[0,x)区间上的数出现的概率为x，
  因为概率的独立的，所以重复k次，最终的概率就是x的k次方。
*/
class RandomSeg
{
public:
	double f()
	{
		return rand()*1.0 / RAND_MAX;
	}
	double Random(int k,double x)
	{
		double res = -1;
		for (int i = 0 ; i < k ; k++)
		{
			//在0到k-1范围内，取到最大值
			res = max(res,f());
		}
		return res;
	}
};



int main()
{
	RandomSeg rs;
	printf("%f\n",rs.Random(10,2));
	system("pause");
	getchar();
	return 0;
}