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
	reverse(s.begin(), s.end()); //“uoy evol i”
	cout << s<< endl;
	int i, j;
	//对每个局部调整 uoy--you ....
	//使用j变量确定需要翻转的单词的范围
	for (int i = 0 ; i < n ; i++)
	{
		j = i;
		//这个循环是寻找到需要翻转单词的实际位置
		while (j < n && s[j] != ' ')
		{
			j++;
		}
		//找到每个单词进行翻转
		reverse(s.begin() + i,s.begin() + j);
		//把j赋值给i，更新到最新的位置，查找下一个单词
		i = j; //更新i的位置
	}
	return s;
}

int main(int argc, char* argv[])
{
	string s = "i love you";
	cout << reverseString(s,10) << endl;
	getchar();
	return 0;
}