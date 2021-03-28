#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/**
  对于两个32位整数a和b，请设计一个算法返回a和b中较大的。
  但是不能用任何比较判断。若两数相同，返回任意一个。

给定两个整数a和b，请返回较大的数。

测试样例：
1,2
返回：2


情况来讨论好理解：
1.a和b符号相同： diffab为0 sameab为1 此时看cs的符号 若a大于b cs为1 那么returnA为1returnB为0 结果正确 
2.a和b符号不相同： diffab为1 sameab为0 此时看as的符号 若a为正数b为负 那结果肯定为a大于b
看returnA为1 returnB为0 结果正确 a为负b为正 那肯定b大于a returnA为0 returnB为1 结果正确
*/

//取最大值
int getMax(int a,int b)
{
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(a - b);
	//异或，同0异1
	int difsab = sa^sb;
	//与difsab相反
	int samesab = flip(difsab);

	int returnA = sa*difsab + sc*samesab;
	int returnB = flip(returnA);
	return b*returnA + a*returnB;
}

//获取数的符号
int sign(int n)
{
	return (n>>31) & 1;
}

//取反
int flip(int n)
{
	return n ^ 1;
}
int main()
{
	
	getchar();
	return 0;
}