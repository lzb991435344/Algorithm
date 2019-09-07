// TrainingCode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

/**
  【题目】
给定数组arr，arr中所有的值都为正数且不重复。每个值代表一种面值的货币，
每种面值的货币可以使用任意张，再给定一个整数aim代表要找的钱数，求换钱有多少种方法。
【举例】
arr=[5,10,25,1]，aim=0。
组成0元的方法有1种，就是所有面值的货币都不用。所以返回1。
arr=[5,10,25,1]，aim=15。 
组成15元的方法有6种，分别为3张5元，1张10元+1张5元，1张10元+5张1元，10张1元+1张5元，2张5元+5张1元，15张1元。所以返回6。
arr=[3,5]，aim=2。
任何方法都无法组成2元。所以返回0。


*/
//暴力递归解决
/**
@function 换零钱的方法总数
@param1 钱币的种类
@param2 数组的下标索引
@param3 换钱的目标总数 
@return  换钱的方法总数 
@author Blake
@date 2019/09/07


*/

int process(vector<int> arr , int index , int  aim)
{
	int res = 0;
	int i;
	//递归出口，当索引等于数组的最大下标索引时，递归结束
	if (index == arr.size())
	{
		return (aim == 0 ? 1 : 0);
	}
	else
	{
		for (i = 0; aim >= (arr[index] * i); i++)
		{
			/**
				递归进行：arr[index]   index++  数组中的每一个种类尝试
				@param1 换钱的种类
				@param2 index++，使用每一个换钱种类进行计算
				@param3 使用当前的种类换钱之后剩余的钱数
			*/
			res += process(arr, index + 1, aim - arr[index] * i);
		}
	}  
	return res;
}

//0-aim的所有可能
int getCoinSort(vector<int> arr , int aim)
{
	//递归出口
	if (arr.empty() || aim < 0)
	{
		return 0;
	}
	//递归开始，从数组下标0开始
	return process(arr , 0 , aim);
}

//dp解决
const int max_n = 50;
const int max_aim = 1000;
//dp[i][j] 使用0..i种货币组成钱数J的方法数
int dp[max_n + 1][max_aim + 1];

int countWays(vector<int> penny , int n , int aim)
{
	int i;
	//初始化第一列
	//使用0...i个货币组成钱数0的方法数为1 就是都不使用
	for (i=0;i<n;i++)
	{
		dp[i][0] = 1;
	}
	//初始化第一行
	//使用第0个货币组成钱数i的方法数，那就是说只有当钱数刚好能够
	//整除第0个货币的面值时有一种方法
	for (i=0;i<=aim;i++)
	{
		//说明能够使用该面额
		if (i % penny[0]==0)
		{
			dp[0][i] = 1;
		}
		else
		{
			dp[0][i] = 0;
		}
	}
	for (i=1;i<n;i++)
	{
		for (int j=0;j<=aim;j++)
		{

			if(j>=penny[i])
			{
			/*
			dp[i][j]意义:
			1.使用m张(m=0,1,2...)i货币组成j的方法数(使用0张dp[i-1][j-0*penny[i]],
			使用1张dp[i-1][j-1*penny[i]],使用2张dp[i-1][j-2*penny[i]].....)
			上面的公式其实就是把m=0和情况拆分了出来，后面的dp[i][j-penny[i]]表示m=1开始的情况
			为什么dp[i][j-penny[i]]能表示m=1的情况呢？ 使用m张i货币组成j-penny[i]的方法数
				*/
				dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
			}
			else
			{
				//钱数小于penny[i]，不能使用i货币 只能使用i-1个货币去组成钱数J
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n-1][aim];
}

int main()
{
	vector<int> arr = {5,10,25,1};
	int aim = 15;
	//cout<< getCoinSort(arr,aim)<<endl;
	cout<<countWays(arr,4,aim) <<endl;
	getchar();
    return 0;
}

