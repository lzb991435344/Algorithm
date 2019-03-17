#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
   句子逆序，“i love you”处理后变成 “you love i”
   
*/
string reverseString(string s , int n)
{
	cout << s<< endl;
	reverse(s.begin(), s.end());
	cout << s<< endl;
	int i, j;
	for (int i = 0 ; i < n ; i++)
	{
		j = i;
		while (j < n && s[j] != ' ')
		{
			j++;
		}
		//找到单词进行翻转
		reverse(s.begin() + i,s.begin() + j);
		//把j赋值给i，更新到最新的位置，查找下一个单词
		i = j;
	}
	return s;
}

int main()
{
	string s = "i love you";
	cout << reverseString(s,10) << endl;
	getchar();
	return 0;
}