#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：生成特定范围之内的随机数
 * 首先有一个随机产生1-5的函数 然后利用5*函数+函数 生成一个随机数在1-30之间的随机函数
 * 然后若生成的数不在7-20的范围内就再次随机的方式来控制随机函数等概率的生成数字在7-20的范围内
 * 之后再%7+1就能等概率随机生成1-7的数字了

  int rand(void)；
  返回一个[0,RAND_MAX]间的随机整数。

*/

class Random5
{
public:
	//封装好的静态函数--用于生成随机数
	static int randomNumber();
};

class Random7
{
	int rand5()
	{
		Random5::randomNumber();
	}
	int randomNumber()
	{
		int num = rand5() * 5 + rand5();
		while (num > 20 || num < 7)
		{
			num = rand5() * 5 + rand5();
		}
		return (num % 7) + 1;
	}
};

int main()
{
	system("pause");
	getchar();
	return 0;
}