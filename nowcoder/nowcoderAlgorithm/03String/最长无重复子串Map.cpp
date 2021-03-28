#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 最长无重复子串
   对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。
给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，
且长度小于等于500。
测试样例：
"aabcb",5
返回：3
   
  图形解析：
  https://www.cnblogs.com/haozhengfei/p/d0906ebc98f7b6eaecb3ecd738dc78ac.html
*/

int max(int a , int b )
{
	return a > b ? a : b;
}
int longestSubString(string s, int n)
{
	//存储字符在上次出现的位置
	map<int, char> m;

	int pre_index = -1;
	int res = 0;
	int tmp = 0;
	m[s[0]] = 0;

	//遍历字符串和map中的字符串做比较
	for (int i = 0 ; i < n ; i++)
	{
		int cur;
		char ch = s[i];
		//获取map中最早出现该字符的位置
		if (m.find(ch) != m.end())
		{
			cur = m[ch];
		}
		else
		{
			cur = -1;
		}
		/*
		比较当前字符i和i-1字符的上次的出现的位置，
		谁出现的位置更靠近i就用它计算长度.因为如果i-1字符上次出现的位置比i大，
		那么说明i字符没到上次它出现的位置就会因为i-1字符重复而失败(否则i-1字符上次出现的位置就不会比i的大)
		反之，则说明i字符可以到上次出现的字符的位置，在这中间i-1字符保证不会发生重复
		*/
		if (pre_index > cur)
		{
			tmp = i - pre_index;
		}
		else
		{
			tmp = i - cur;
			pre_index = cur;
		}
		m[ch] = i;
		res = max(res,tmp);
	}
	return res;
}

int main(int argc, char* arv[])
{
	string s = "aabcb";
	cout << longestSubString(s,5) << endl;
	getchar();
	system("pause");
	return 0;
}