#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

/**
 请编写一个算法，不用任何额外变量交换两个整数的值。

给定一个数组num，其中包含两个值，请不用任何额外变量交换这两个值，
并将交换后的数组返回。

测试样例：
[1,2]
返回：[2,1]
*/

vector<int> getSwap(vector<int> num)
{
	swap(num[0],num[1]);
	return num;
}

//参数传引用
void swap(int& a , int& b)
{
	//example：a = 01  b= 10
	a = a^b; //a = 11
	b = a^b; //b = 01
	a = a^b; //a = 10
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
    getSwap(num);
	cout << num[1];
	getchar();
	return 0;
}