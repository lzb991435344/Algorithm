#include <iostream>
#include <string>
using namespace std;

/**
 判断输入的括号是否合法？
*/
bool isValid(string s , int n)
{
	int num = 0; //做计数使用
	for (int i = 0 ;i < n ; i++)
	{
		if (s[i] ==  '(')
		{
			num++;//不断增加，计算左边括号的总数
		}
		if(s[i] == ')')
		{ 
			num--;
		}
		if (num < 0) //说明左右括号数量不匹配
		{
			return false;
		}
	}
	return num == 0;
}

int main(int argc, char* argv[])
{
	string s = "(()())";
	cout << isValid(s,6) << endl;
	getchar();
	return 0;
}