#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  
给定两个字符串A和B，返回两个字符串的最长公共子序列的长度。例如，A="1A2C3D4B56”，B="B1D23CA45B6A”，
”123456"或者"12C4B6"都是最长公共子序列。
给定两个字符串A和B，同时给定两个串的长度n和m，请返回最长公共子序列的长度。保证两串长度均小于等于300。

测试样例：
"1A2C3D4B56",10,"B1D23CA45B6A",12
返回：6

*/

const int N = 300;
//dp[i][j]=k 代表字符串A[0...i-1]和字符串B[0...j-1]的最长公共子序列长度为k
int dp[N+1][N+1];

int max(int a , int b)
{
	return (a) > (b) ? (a) : (b);
}
int findLCS(string s1 , string s2 , int n , int m )
{
	//标记位，对应位置标志位设为1
	int flag = 0;

	//初始化第一列
	for (int i = 0 ; i < n ; i++)
	{
		if (flag == 1 || s1.at(i) == s2.at(0))
		{
			dp[i][0] = 1;
			flag = 1;
		}
		else
		{
			dp[i][0] = 0;
		}
	}

	flag = 0;//初始化重置标志位
	//初始化第一行
	for (int j = 0 ; j < m ; j++) 
	{
		//标志位为1或者当前值为0
		if (flag == 1 || s1.at(0) == s2.at(j))
		{
		
		}	dp[0][j] = 1;
			flag = 1;
		else
		{
			dp[0][j] = 0;
		}
	 }
	for (int i = 1 ; i< n ; i++)
	{
		for (int j = 1 ; j < m ; j++)
		{
           //i位置字符和j位置字符相等，有3个可能值
			if (s1.at(i) == s2.at(j)) 
			{
				int val_1 = dp[i - 1][j - 1] + 1;//等于i-1和j-1的长度+1
				int val_2 = dp[i - 1][j];//等于i-1和j的长度，因为可能在i-1处就已经和j处有最长公共了，
				int val_3 = dp[i][j - 1];//等于i和j-1的长度，可能在j-1处就有和i最长的公共了

				dp[i][j] = max(val_1, val_2);
				dp[i][j] = max(dp[i][j], val_3);
			}
			else
            //i位置字符和j位置字符不相等，有2个可能值，就少了第一种情况
			{
				int val_1 = dp[i - 1][j];
				int val_2 = dp[i][j - 1];
				dp[i][j] = max(val_1, val_2);
			}
		}
	}
	//数组中存的是最长的公共子序列
	return dp[n-1][m-1];
}

int main()
{
	string s1 = "1A2C3D4B56";
	string s2 = "B1D23CA45B6A";
	//string s1 = "ABCBDAB";
	//string s2 = "BDCABA";
	int n = 10;
	int m = 12;
	cout <<findLCS(s1,s2,n,m) << endl;
	getchar();
	return 0;
}