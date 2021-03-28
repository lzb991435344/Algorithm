#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
   用'20%'替换空格
   ps：假设空格的数量是s,原来字符串的长度是n,增加的字符串的长度为2*s,总的长度是2*s+n
   需要重新分配空间
*/
string replaceBank(string s , int n)
{
	int blank = 0;
	//计算空格的数量，便于计算总字符串的长度
	for (int i = 0 ; i < n ; i++)
	{
		if (s[i]== ' ')
		{
			blank++;
		}
	}
	//重新计算字符串的长度
	int length = blank*2 + n;
	//重新申请字符数组，需要加‘\0’
	char* newString = new char[length];
	newString[n] = '\0';
	int k = length - 1;
	//循环的长度为源字符串的长度
	//从后往前复制
	for (int j = n-1 ; j >= 0 ; j--)
	{
		if (s[j]==' ')
		{
         newString[k--] = '%';
		 newString[k--] = '0';
		 newString[k--] = '2';
		}
		else //复制原来的字符串
		{
			newString[k--] = s[j];
		}		
	}
	return newString;
}

int main(int argc, char* argv[])
{
	string s = "a ab cb";
	cout << replaceBank(s, 7)<< endl;
	getchar();
	return 0;
}