#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  有一个矩阵map，它每个格子有一个权值。从左上角的格子开始每次只能向右或者向下走，
  最后到达右下角的位置，路径上所有的数字累加起来就是路径和，返回所有的路径中最
  小的路径和。
 给定一个矩阵map及它的行数n和列数m，请返回最小路径和。保证行列数均小于等于100.
测试样例：
[[1,2,3],
[1,1,1]],2,3

*/
const int N = 100;
int  dp[N+1][N+1];
int getMinPath(vector<vector<int>> map , int m ,int n)
{
	int i;
	//初始化第一行
	for ( i = 0; i < n; i++)
	{
		dp[0][i] = (i == 0) ? map[0][i] : dp[0][i-1] + map[0][i];
	}
	//初始化第一列
	for ( i = 0 ; i < m ; i++)
	{
		dp[i][0] = (i == 0) ? map[i][0] : dp[i - 1][0] + map[i][0];
	}
	//dp[i][j]可以由上一列向右走或者上一行向下走得到，选最小的即可
	for ( i = 1 ; i< n ; i++)
	{
		for (int j = 1 ; j < m ; j++)
		{
			if (dp[i-1][j] > dp[i][j-1])
			{
				dp[i][j] = dp[i][j - 1] + map[i][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
		}
	}
	return dp[n-1][m-1];
}
int main()
{

	vector<vector<int>> map ;
	//vector<vector<int>> map = { { 1,1,1,1 },{2,3,5,4},{1,7,2,3},{1,3,3,4},{2,3,4,1} };
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	map.push_back(tmp);
	tmp[0] = 1;
	tmp[1] = 1;
	tmp[2] = 1;
	map.push_back(tmp);
	int n = 2;
	int m = 3;
	cout << getMinPath(map,n,m)<< endl;
	getchar();
	return 0;
}