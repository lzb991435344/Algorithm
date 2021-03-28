#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
 题目：
  有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上m级，
共有多少走法？注：规定从一级到一级有0种走法。
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。
为了防止溢出，请返回结果Mod 1000000007的值。
输入：
3
1
输出：
2
*/

const int N = 100000;
const int MOD = 1000000007;

//dp[i]=k 代表上i个台阶的方法数为k
int dp[N+1];
int getWays(int n)
{
	 dp[1] = 1;
	 dp[2] = 2;
	 /** 
	 第i级台阶可以依赖于两种情况得到:
			  1.一种就是上了i-1级之后再上一级
			  2.一种就是上了i-2级之后再上二级
			  两种相加即可得到
			  */
	for (int i = 3 ; i<= n ; i++ )
	{
		dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
	}
	return dp[n];
}

int main()
{

	cout <<getWays(4) << endl;
	getchar();
	return 0;
}