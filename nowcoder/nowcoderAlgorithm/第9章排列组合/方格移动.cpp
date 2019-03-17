#include <iostream>
#include <stdio.h>
using namespace std;

/**方格移动
  在XxY的方格中，以左上角格子为起点，右下角格子为终点，每次只能向下走或者向右走，
请问一共有多少种不同的走法

给定两个正整数int x,int y，请返回走法数目。保证x＋y小于等于12。

测试样例：
2,2
返回：2
--简单的排列组合数，考虑可以往左走的时候的次数？
*/
class Root
{
public:
	int countWays(int x ,int y)
	{
		//先判参数
		if (x <= 0 ||  y <= 0 || x + y > 12)
		{
			return -1;
		}
		return C(x-1+y-1,x-1);
	}
	//计算n的time次阶乘
	int jiecheng(int n ,int time)
	{
		int res = 1;
		//当time=0是结束循环
		for (int i = n ; time > 0 ; i--)
		{
			res *= i;
			time--;
		}
		return res;
	}

	int C(int m , int n)
	{
		//计算排列组合数
		return jiecheng(m , n) / jiecheng(n,n);
	}
};
int main()
{

	Root root;
	printf("%d\n",root.countWays(3,3));
	getchar();
	system("pause");
	return 0;
}


