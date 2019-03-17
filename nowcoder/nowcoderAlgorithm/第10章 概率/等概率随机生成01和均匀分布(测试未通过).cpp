// TrainingCode.cpp: 定义控制台应用程序的入口点。
//
/**
1.有一个随机数发生器，能以概率p生成0，以概率1-p生成1，问如何做一个随机数发生器 
使得生成0和1的概率相等。 

  解析：可以用原发生器周期性地产生2个数，直到生成01或者10。 由于生成01和
10的概率均为p(1-p)，故预先任意指定01为0（或1），10为1（或0）即可。
即可等概率的产生0和1，但然，要考虑其他组合的不可用性。

2.用上面那个生成0和1的概率相等的随机数发生器，怎样做一个随机数发生器使得它生成 
的数在1...N之间均匀分布。 
	
  解析：想到位运算，因为i个二进制位随机的选择0或1，可以随机的构成0-2^i的数，
而这些数构成了所有的组合数。因此是等概率出现的。比如：2位二进制位，这两位可以
随机为0或1而互不影响，随机的构成了00 01 10 11，它们代表了四个数，且这四个数
是等概率的。 
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


/**class RandomP {
public:
	//随机池，使用的静态函数
	static int f();
};*/

/**
*   因为要等概率产生01 而p概率产生0 1-p产生1 那么若两者概率相乘
* 就是相等的 所以01和10的出现的概率都是p*(1-p)
* 此时生成函数生成01或者10即可
* 
*/
class Random01 {
public:
	
/***	//1. 用RandomP::f()实现等概率的01返回
	int random01()
	{
		int n1;
		int n2;
		while (true) {
			n1 = RandomP::f();
			n2 = RandomP::f();
			if (n1 == n2)continue;
			else if (n1 == 1 && n2 == 0)return 1;
			else break;
		}
		return 0;
	}*/
	//1.实现等概率的01返回
	int Rand()
	{
		int i1 = rand();
		int i2 = rand();
		if (i1 == 0 && i2 == 1)
			return 1;
		else if (i1 == 1 && i2 == 0)
			return 0;
		else
			//重新随机
			return Rand();
		return -1;
	}


	//2.实现等概率的1-N的分布
	int newRand()
	{
		int result = 0;
		int n = 10;
		int k = 5;
		for (int i = 0; i < k; ++i)
		{
			if (Rand() == 1)
				//i右移一位，i=i*0.5;
				//进行位的或运算，
				result |= (1 << i);
		}
		if (result > n)
			return newRand();
		return result;
	}
};
int main()
{
	Random01 r;
	printf("%d\t",r.Rand());
	getchar();
	system("pause");
	return 0;
}

