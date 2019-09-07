// TrainingCode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

/**
  给定两个字符串str1和str2，再给定三个整数ic，dc，rc，分别代表插入、删除、替换一个字符的代价，
  返回将str1编辑成str2的最小代价。
举例：
str1="abc"   str2="adc"  ic=5    dc=3   rc=2，从"abc"编辑到"adc"把b替换成d代价最小，为2；
str1="abc"   str2="adc"  ic=5    dc=3   rc=10，从"abc"编辑到"adc"，先删除b再插入d代价最小，为8；


dp生成步骤：
1.dp[0][0]表示空串编辑成空串，故dp[0][0]=0;

2.求第一行dp[0][j]，空串编辑成str2[0....j-1]，则dp[0][j]=ic*j;

3.求第一列dp[i][0]，str1[0......i-1]编辑成空串，则dp[i][0]=dc*i;

4.求dp[i][j]，即str1[0....i-1]编辑成str2[0.....j-1]，四种可能的途径：

<1>str1[0....i-1]先编辑成str2[0.....j-2]，再由str2[0.....j-2]到str2[0.....j-1]，即dp[i][j-1]+ic;

<2>str1[0....i-1]先编辑成str1[0.....i-2]，再由str1[0.....i-2]到str2[0.....j-1]，即dc+dp[i-1][j];

<3>如果str1[i-1]==str2[j-1],则dp[i][j]=dp[i-1][j-1];

如果str1[i-1]!=str2[j-1],则dp[i][j]=dp[i-1][j-1]+rc;

选择上面四个中最小的值作为dp[i][j]，时间复杂度O(MN)，空间复杂度O(MN)。最小编辑距离为dp[M][N]。
  优化：利用空间压缩可将空间复杂度压缩至O(min{M,N})
*/

const int N = 300;

//dp[i][j]=k 代表字符串A[0..i-1]变成字符串B[0...j-1]需要的最小代价为k
int dp[N + 1][N + 1];
int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
	int i, j;
    //初始化第一列，字符串A[0..i-1]变成空串的代价就是删除i个字符
	for (i = 0; i <= n; i++)
	{
		dp[i][0] = i * c1;
	}
    //初始化第一行，空串A变成字符串B[0...i-1]的代价就是插入i个字符
	for (i = 0; i <= m; i++) 
	{
		dp[0][i] = i * c0;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (A.at(i - 1) == B.at(j - 1)) {//当i位置和j位置字符相等时，有3个可能值
				int val_1 = dp[i - 1][j - 1];//就等于i-1变成j-1的代价
				int val_2 = dp[i - 1][j] + c1;//等于i-1变成j串，然后删除一个i字符
				int val_3 = dp[i][j - 1] + c0;//等于i变成j-1串，插入一个j字符

				dp[i][j] = min(val_1, val_2);
				dp[i][j] = min(dp[i][j], val_3);
			}
			else {//当i位置和j位置字符不相等时，有3个可能值
				int val_1 = dp[i - 1][j] + c1;//等于i-1变成j串，然后删除一个i字符
				int val_2 = dp[i][j - 1] + c0;//等于i变成j-1串，插入一个j字符
				int val_3 = dp[i - 1][j - 1] + c2;//等于i-1变成j-1串，然后替换i字符变成j字符

				dp[i][j] = min(val_1, val_2);
				dp[i][j] = min(dp[i][j], val_3);
			}
		}
	}

	return dp[n][m];
}

int min(int a, int b) {
	return a > b ? b : a;
}
int main()
{
	
	getchar();
    return 0;
}

