#include <iostream>
#include <string>
using namespace std;

/**
 判断输入的括号是否合法？
*/
bool isValid(string s , int n)
{
	int num = 0;
	for (int i = 0 ;i < n ; i++)
	{
		if (s[i] ==  '(')
		{
			num++;
		}
		if(s[i] == ')')
		{ 
			num--;
		}
		if (num < 0)
		{
			return false;
		}

	}
	return num == 0;
}

int main()
{
	string s = "(()())";
	cout << isValid(s,6) << endl;
	getchar();
	return 0;
}