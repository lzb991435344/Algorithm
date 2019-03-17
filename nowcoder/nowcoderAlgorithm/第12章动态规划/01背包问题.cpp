#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  
    动态规划：dp
  现有n件物品和一个容量为c的背包。第i件物品的重量是重量为w[i]，
  价值是v[i]。已知对于一件物品必须选择取（用1表示）或者不取（用0表示），
  且每件物品只能被取一次（这就是“0-1”的含义）。求放置哪些物品进背包，
  可使这些物品的重量总和不超过背包容量，且价值总和最大。

*/

#include <vector>
int max(int a , int b)
{
	return (a) > (b) ? (a) : (b);
}

/***/
int maxValue(vector<int> w , vector<int> v , int n , int cap)
{
	int** dp = new int*[n+1];
	int i , j;
	//初始化dp数组
	for (i = 0 ;i < n ; i++)
	{
		dp[i] = new int[cap + 1];
	}

	//dp更新策略
	//dp[i][j]=k 表示在最大承重j下使用0..i件物品组成的最大总价值为k
	//初始化第一行，当背包容量大于w[0]时，可以放入，否则背包重量为0
	for (i = 0 ; i <= cap ; i++)
	{
		if (i >= w[0])
		{
			dp[0][i] = v[0];
		}
		else
		{
			dp[0][i] = 0;
		}
	}

	//dp可用于保存上一次存在的状态值
	for (i = 1 ; i < n ; i++)
	{
		//j从最小容量开始计算，一直到最大的承重量
		for(j = 0 ; j <= cap ; j++)
		{
			//比较使用第i件物品和不使用第i件物品的总价值，取大的那个，
			//前提是当前背包承重能放入第i件物品的重量
			if (j - w[i] >= 0)
			{
				//dp[i][j]上方的值dp[i-1][j]，在最大承重的情况下，
				//比较放和不放第i件物品的最大价值量，取较大值
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			//当前背包承重不能放入第i件物品，所以只能默认不使用第i件物品
			else
			{
				//取上方的值，放不下第i件物品
				dp[i][j] = dp[i - 1][j];
			}

		}
	}
	return dp[n - 1][cap];
}
int main()
{
	vector<int> w = { 1,2,3 };
	vector<int> v = { 1,2,3 };
	cout << maxValue(w,v,3,6)<< endl;
	getchar();
	return 0;
}