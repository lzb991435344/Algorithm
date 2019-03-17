#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
using namespace std;

/**
  对于两个字符串A和B，如果A和B中出现的字符种类相同且每种字符出现的次数相同，
则A和B互为变形词，请设计一个高效算法，检查两给定串是否互为变形词。

给定两个字符串A和B及他们的长度，请返回一个bool值，代表他们是否互为变形词。

测试样例：
"abc",3,"bca",3
返回：true
*/

bool chkTransform(string s1, string s2, int lena , int lenb)
{
	//用来计算字符出现的次数，初始化为0
	int letter[256];
	memset(letter,0,sizeof(letter));
	//长度不相等
	if (lena!=lenb)
	{
		return false;
	}
	//字符串A出现的字符，在相应的ascii码位置上加1
	for (int i = 0 ; i < lena ; i++)
	{
		//ascii码位置上加1
		letter[s1.at(i)]++;
	}
	//字符串B出现的字符，在相应的位置减1，若最终都是0，
	//则true 有一个不是就为false
	for (int j = 0 ; j < lenb ; j++)
	{
		//其中有一个为0，返回false,原来的字符串中位置为1
		//先比较完，再减1
		if (letter[s2.at(j)]-- == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s1 = "abc";
	string s2 = "bac";
	cout << chkTransform(s1 , s2 , 3 , 3)<< endl;
	getchar();
	return 0;
}