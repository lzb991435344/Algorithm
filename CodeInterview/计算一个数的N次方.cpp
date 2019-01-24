#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

/**
CodeInterview:
 >给定一个double类型的浮点数base和int类型的整数exponent。
  求base的exponent次方。
*/
class Power{
	public:
 //小白版本
  double power(double base , int expoent)
 {
	double res = 1.0;
	for(int i = 0 ; i < expoent ; i++)
	{
		res *= base;
    }
	return res;
  }

  //优化版
  /*
  指数幂的所有边界包括
*    指数为0的情况，不管底数是多少都应该是1
*    指数为负数的情况，求出的应该是其倒数幂的倒数
*    指数为负数的情况下，底数不能为0
  */
  //包含负数幂指的情况
  double power2(double base, int expoent)
  {
	  double res = 1.0;
	  if(expoent == 0)
	  {
		  return 0.0;
	  }
	  if (equal(base , 0.0) == true && expoent < 0)
	  {
		  printf("error!\n");
	  }
	  if (expoent > 0.0)
	  {
		  res = powerNormal(base, expoent);
	  }
	  else
	  {
		  res = powerNormal(base, -expoent);
		  res = 1 / res;
	  }
	  return res;
  }

  //更加高效的算法--使用位运算
  /**
  exg:
1. 写出指数的二进制表达，例如13表达为二进制1101。
2.举例:10^1101 = 10^0001*10^0100*10^1000。
3.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
  */
  double power3(double base, int expoent)
  {
	  if (expoent == 0)
	  {
		  return 1.0;
	  }
	  if (expoent == 1)
	  {
		  return base;
	  }

	  double res = 1.0;
	  int temp = base;
	  while (expoent != 0)
	  {
		  if ((expoent & 1) == 1)
		  {
			  //计算乘积值
			  res *= temp;
		  }
		  //temp翻倍，移动到下一个
		  temp *= temp;
		  //指数右移一位
		  expoent >>= 1;
	  }
  }

  //以上方法写成递归形式,使用函数栈实现
  double power4(double base, int expoent)
  {
	  if (expoent == 0)
	  {
		  return 1.0;
	  }
	  if (expoent == 1)
	  {
		  return base;
	  }

	  double res = power4(base, expoent >> 1);
	  res *= res; //翻倍
	  if ((expoent & 1) == 1)
	  {
		 //结果为1，累乘
		  res *= base;
	  }
	  return res;
  }
private:
	//该函数用于判断在指数为负数的情况下，底数是否为零
	double equal(double left , double right)
	{
		if (fabs(left - right) < 0.0000001)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//该函数用于普通的幂指计算
	double powerNormal(double base, int expoent)
	{
		double res =1.0;
		for (int i = 0 ; i < expoent ; i++ )
		{
			res *= base;
		}
		return res;
	}
};

int main()
{
	Power pp;
	printf("%f\n",pp.power(2,-3));
	//printf("%f\n", pp.power2(2, -3));
	//printf("%f\n", pp.power3(2,-3));
	//printf("%f\n", pp.power4(2, -3));
	system("pause");
	getchar();
	return 0;
}