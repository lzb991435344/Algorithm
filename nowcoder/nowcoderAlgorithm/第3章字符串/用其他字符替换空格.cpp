#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
   用'20%'替换空格
   
*/
string replaceBank(string s , int n)
{
	int blank = 0;
	//计算空格的数量
	for (int i = 0 ; i < n ; i++)
	{
		if (s[i]== ' ')
		{
			blank++;
		}
	}
	//重新计算字符串的长度
	int length = blank*2 + n;
	char* newString = new char[length];
	newString[n] = '\0';
	int k = length - 1;
	//循环的长度为源字符串的长度
	for (int j = n-1 ; j >= 0 ; j--)
	{
		if (s[j]==' ')
		{
         newString[k--] = '%';
		 newString[k--] = '0';
		 newString[k--] = '2';
		}
		else
		{
			newString[k--] = s[j];
		}
		
	}
	return newString;
}

int main()
{
	string s = "a ab cb";
	cout << replaceBank(s, 7)<< endl;
	getchar();
	return 0;
}