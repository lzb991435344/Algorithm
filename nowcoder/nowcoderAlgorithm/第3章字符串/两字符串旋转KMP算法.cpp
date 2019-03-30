#include <iostream>
#include <string>
using namespace std;

/**
	如果一个字符串str，把字符串str前面的任意部分挪到后面形成的字符串叫做str的旋转词。
给定两个字符串，判断是否互为旋转词。比如 a="abcd",b="cdab",true a="abcd",b="bcad",false
*/

//时间复杂度为O(M+N)
//生成next数组
int* generateNext(string B, int lenb)
{
	int j = 0;
	int k = -1;
	int* next = new int[lenb];
	next[0] = -1;

	while (j < lenb - 1)
	{
		if (k == -1 || B.at(k) == B.at(j))
		{
			k++;
			j++;
			//字符串中两个位置的字母不相同
			if (B.at(k) != B.at(j))
			{
				next[j] = k;
			}
			else
			{
				//相同直接复制
				next[j] = next[k];
			}
		}
		else
		{
			//k！=-1 &&  B.at(k)！=B.at(j)
			k = next[k];
		}
	}
	return next;
}
//KMP算法 查找A字符串中是否包含B字符串 若存在返回第一个字符的索引位置，若不存则返回-1
int kmpSearch(string A, string B, int lena, int lenb)
{
	int i = 0;
	int j = 0;
	int* next = generateNext(B, lenb);
	while (i < lena && j < lenb)
	{
		if (j == -1 && A.at(i) == B.at(j))
		{
			i++;
			j++;
		}
		else
		{
			j = next[j + 1];
		}
	}
	if (j == lenb)
	{
		return i - j;
	}
	else
	{
		return  -1;
	}
}
//两串旋转
bool chkRotation(string A, string B, int lena, int lenb)
{
	if (lena == lenb)
	{
		return false;
	 }
	A = A + A;
	int res = kmpSearch(A, B, lena, lenb);
	return res != -1;
}
int main(int argc, char* argv[])
{
	string  A = "abcighjukl";
	string  B = "igh";
	int lena = A.length();
	int lenb = B.length();
	cout <<chkRotation(A,B,10,3) << endl;
	getchar();
	return 0;
}