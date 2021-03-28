#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  现在有一个行和列都排好序的矩阵，请设计一个高效算法，快速查找矩阵中是否含有值x。

  给定一个int矩阵mat，同时给定矩阵大小nxm及待查找的数x，请返回一个bool值，代表矩阵中是否存在x。
所有矩阵中数字及x均为int范围内整数。保证n和m均小于等于1000。

测试样例：
[[1,2,3],
[4,5,6],
[7,8,9]],
3,3,10
返回：false
*/

bool findX(vector< vector<int> > arr , int m , int n , int x)
{
	bool res = false;
	int col = n - 1;
	int row = 0;
	while (col > 0 && row < n )
	{
		if (x == arr[row][col])
		{
			return true;
		}
		
		if (x>arr[row][col])
		{
			//行数+1
			row++;
		}
		else
		 {  //列数+1
			col--;
		}
	}
	return res;
}
int main()
{
	vector<vector<int>> arr = 
	{{1,2,3},
	{4,5,6},
	{7,8,9}};
	cout << findX(arr,3,3,18) << endl;
	getchar();
	return 0;
}