#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：蚂蚁习题
  n只蚂蚁从正n边形的n个定点沿着边移动，速度是相同的，问它们碰头的概率是多少？
给定一个正整数n，请返回一个数组，其中两个元素分别为结果的分子和分母，请化为最简分数。
测试样例：
   3
返回：[3,4]

(1)公式 2^n-1/2^n ，只有两种情况不会碰头，顺时针和逆时针
(2)辗转相除法求最大公约数
*/

class Ants
{
public :

int gcd(int m ,int n)
{
		while (1)
		{
			if ((m = m % n) == 0)
			{
				return n;
			}
			if ((n = n % m) == 0)
			{
				return m;
			}
		}
	}
	vector<int> collision( int n)
	{
		vector<int> res;

		int fenmu = pow(2, n);
		int fenzi = fenmu - 2;
		//用辗转相处法求最大公约数
		int yue = gcd(fenmu,fenzi);
		//约分
		fenmu = fenmu / yue;
		fenzi = fenzi / yue;
		res.push_back(fenzi);
		res.push_back(fenmu);

		return res;
    }
};

int main()
{
	Ants ant;
	vector<int> res;
	 int n = 3;
	res = ant.collision(n);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		cout << *it<< endl;
	}
	system("pause");
	getchar();
	return 0;
}