#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
1.斐波那契数列的第n项。
2.一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 求该青蛙跳上一个n级的台阶总共有多少种跳法。
3.一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
  求该青蛙跳上一个n级的台阶总共有多少种跳法。
 4.我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1
 的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Recurssion
{
public:
	//爆炸 O(2^n)
	int Fibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}
		else
		{
			return Fibonacci(n-2) + Fibonacci(n-1);
		}
	}

	//迭代 O(N)
	int Fibonacci2(int n)
	{
		long one = 0;
		long  two = 1;
		long res = 0;
		for (int i = 2 ; i <= n ; i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}

	//O(logN)
	static int pre;//保存的是f(n)的值
	static int post;//保存的是f(n-1)的值
	int temp;
	int Fibonacci3(int n)
	{
		if (n < 2)
		{
			if (n == 0)
			{
				return 0;
			}
			pre = 1;
			post = 1;
			return pre;
		}
		// n 为奇数， 则做减一操作， 函数回调时
		//  pre：    f(n) = f(n - 1) + f(n - 2)
		//  post：   f(n - 1) = f(n) - f(n - 2)
		if (n % 2 == 1)
		{
			Fibonacci3(n - 1);
			pre = pre + post;
			post = pre - post;
			return pre;
		}

		// n为偶数时不断除二
		// 函数回调时,f(n) 通过 f(n/2) 来计算:
		//
		//  设 n = 2k：//n为2k时推导公式
		//          f(2k) = f(k)  * f(k + 1) + f(k-1) * f(k)
		//                = f(k) * [f(k) + f(k - 1)] + f(k-1) * f(k)
		//                = f(k) ^ 2 + 2 * f(k) * f(k - 1)
		// 设 n = 2k-1：//n为 2k-1时推导公式
		//      f(2k - 1) = f(k) * f(k) + f(k - 1)  * f(k - 1)
		//                = f(k)^2 + f(k - 1)^2
		//偶数实现
		Fibonacci3(n / 2);
		temp = pre;
		pre = pre * pre + 2 * pre * post;
		post = temp *temp + post * post;
		return pre;
	}

	//跳台阶，只能跳1,2级
	int jumpFloor(int n)
	{
		if (n <= 2)
		{
			return n;
		}
		long one = 1;
		long two = 2;
		long res = 0;
		for (int i = 3 ; i <= n ;i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}

	//方法1：跳台阶的阶数不限
	//*1, (n = 0)
	//* 1, (n = 1)
	//* 2 * f(n - 1), (n >= 2)
	int jumpFloor2(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		else if (n == 1)
		{
			//一级台阶
			return 1;
		}
		else
		{
			//总的方法数
			return 2 * jumpFloor2(n - 1);
		}
	}
	//方法2：使用幂次方函数
	int jumpFloor3(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		else
		{
			return pow(2 , n-1);
		}
	}
	//高效：移位指令只需要2个指令周期
	int jumpFloor4(int n)
	{
		long long res;
		//大于8字节，分两次移位
		if (n >= 32)
		{
			res = 1 << 30;
			res = res << (n - 31);
		}
		else
		{
			//右移一位
			res = 1 << (n - 1);
		}
		return res;
	}
	//矩形覆盖

	/**
	2*n的矩形方法数定义为f(n).

   第一个2*1的小矩形覆盖大矩形的左边，

   *要么竖着放，转化成f(n-1),

   *要么横着放两次，转化成f(n-2),

   因此f(n) = f(n-1) + f(n-2)
   *	1 n = 0
   *	1 n = 1
   *	f(n - 1) + f(n - 2)
	*/
	int retCover(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		else if(n == 1)
		{
			return 1;
		}

		long one=1;
		long two=1;
		long res = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}
};
int Recurssion::pre = 0;
int Recurssion::post = 0;
int main()
{
	Recurssion rs;
	//printf("%d\t", rs.Fibonacci(5));
	//printf("%d\t", rs.Fibonacci2(5));
	//printf("%d\t", rs.Fibonacci3(5));

	//printf("%d\t",rs.jumpFloor(5));
	//printf("%d\t", rs.jumpFloor2(5));
	//printf("%d\t", rs.jumpFloor3(5));
	//printf("%d\t", rs.jumpFloor4(5));
	system("pause");
	getchar();
	return 0;
}