#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：足球比赛
 有2k只球队，有k-1个强队，其余都是弱队，随机把它们分成k组比赛，每组两个队，问两强相遇的概率是多大？ 
给定一个数k，请返回一个数组，其中有两个元素，分别为最终结果的分子和分母，请化成最简分数 
测试样例： 
  4 
返回：[3,7]

强强，强弱
(1)总的场数    num1=2*k的奇数阶乘 num1=(2k-1)*(2k-3)****1
(2)强队和弱队的组合数   num2=排列组合数  num2=C(2,k+1)A(k+1,k+1)
(3)两强相遇的概率 p=num2-num1/num1  
*/

class championship
{
public :
	// Cmn的排列组合 Cmn=m!/n!(m-n)!
	int C(int m, int n)
	{
		return jiecheng(m, n) / jiecheng(n, n);
	}
//求n的time次阶乘
	int jiecheng(int n ,int time)
	{
		int res = 1;
		for (int i = n; time > 0 ; i--)
		{
			res *= i;
			time--;
		}
		return res;
	}

//求阶乘,n的奇数次阶乘,1*3*5*****(2n-1)
	int jishujiecheng(int n )
	{
		int res = 1;
		for (int i = 1 ; i < n ; i+=2)
		{
			res *= i;
		}
		return res;
	}

//求最大公约数
int gcd(int m ,int n)
{
		while (1)
		{
			//注意返回值
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
//计算强强相遇的概率
	vector<int> caclTime( int k)
	{
		vector<int> res;
		int fenmu = jishujiecheng(2 * k);
		int fenzi = C(k + 1, k - 1)*jiecheng(k - 1, k - 1);
		int yue = gcd(fenmu, fenzi);
		fenmu = fenmu / yue;
		fenzi = fenzi / yue;
		res.push_back(fenmu - fenzi);
		res.push_back(fenmu);
		return res;
    }
};

int main()
{
	championship cs;
	vector<int> res;
	 int n = 4;
	res = cs.caclTime(n);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		cout << *it<< endl;
	}
	system("pause");
	getchar();
	return 0;
}