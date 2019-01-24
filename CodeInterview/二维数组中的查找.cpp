#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
  二维数组中的查找
*/

class findInArray
{
public:
	//暴力，时间复杂度O(N*N)
	//使用vector模拟二维数组
	bool bruteforce(vector<vector<int>> arr , int number)
	{
		bool isfind = false;
		int row = arr.size();
		int col = arr[0].size();

		for (int i = 0 ; i < row ; i++)
		{
			for (int j = 0 ; j < col ; j++)
			{
				if (arr[i][j] == number)
				{
					 isfind = true;//标志位设为true
				}
			}
		}
		return isfind;
   }
	//从左上角开始
	bool divideleftup(vector<vector<int>> arr, int number)
	{
		bool isfind = false;

		int row = arr.size();//数组行的长度
		int col = arr[0].size();//数组列的长度
		int i, j;
		// 0=< i <row,正向遍历; 0=< j < col,逆向遍历 
		for (i = 0,j = col-1;(i >= 0 && i < row) && (j >= 0 && j < col);)
		{
			if (arr[i][j] == number)
			{
				isfind = true;
				break;
			}
			else if(arr[i][j] > number)
			{
				j--;//列数减一
			}
			else
			{
				i++;//行数加1
			}
		}
	   return isfind;
   }
};


int main()
{
	//vector模拟二维数组的初始化方法
	int a1[] = { 1, 2, 8, 9, };
	int a2[] = { 2, 4, 9, 12,};
	int a3[] = { 4, 7, 10, 13,};
	int a4[] = { 6, 8, 11, 15,};
	vector<vector<int>> arr;
	arr.push_back(vector<int>(a1, a1 + 4));
	arr.push_back(vector<int>(a2, a2 + 4));
	arr.push_back(vector<int>(a3, a3 + 4));
	arr.push_back(vector<int>(a4, a4 + 4));
	findInArray fa;
	printf("%d\n",fa.bruteforce(arr,7));
	printf("%d\n",fa.divideleftup(arr,7));
	system("pause");
	getchar();
	return 0;
}