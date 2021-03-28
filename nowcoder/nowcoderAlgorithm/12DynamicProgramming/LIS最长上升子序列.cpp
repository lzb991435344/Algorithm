#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，
  请你帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、5、9、4、8）
  ，其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。

紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。


输出描述:
对应每一组数据，输出最长递增子序列的长度。
示例1
输入
7
1 7 3 5 9 4 8
6
1 3 5 2 4 6

输出
4
4

*/

const int N = 500;
//dp[i]=k代表以数组i索引位置结尾的最长上升子序列长度为k 
int dp[N + 1];

int getLIS(vector<int> s , int n)
{
	int max = 0;
	int temp;
    //数组第一个数的最长上升子序列就是本身，所以为1
	dp[0] = 1;
	for (int i = 0 ; i < n ; i++)
	{
		temp = 0;
		//从第i个数往前寻找比第i个数小的作为上升子序列，然后在这个过程
		//中找到已知序列最长的那个。这样再加上第i个数本身使得最长子序列最长
		for (int j = i ; j >= 0 ; j--)
		{
			//数组n+1位置的数和n位置的数比较，
			if (s[i] > s[j] && dp[j] > temp)
			{
				temp = dp[j];
			}
		}
		dp[i] = temp + 1;
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}

	return max;
}
int main()
{
	//vector<int> s = { 1, 7 ,3, 5, 9 ,4, 8 };
	vector<int> s = { 1, 3 ,5, 2, 4 ,6 };
	cout << getLIS(s,6)<< endl;
	getchar();
	return 0;
}