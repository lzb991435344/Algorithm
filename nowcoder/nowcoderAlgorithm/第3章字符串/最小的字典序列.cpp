#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/**
 拼接最小的字典序
   对于一个给定的字符串数组，请找到一种拼接顺序，使所有小字符串拼接成的大字符串是
  所有可能的拼接中字典序最小的。
给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。

测试样例： 
[“abc”,”de”],2 
“abcde”

比较A+B和B+A的大小
*/
void swap(vector<string> &str , int i , int j)
{
	string temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}
/**
  @param str：vector对象
  @param n:字符串的个数
  @param len：后一个要并结成的字典序的长度
*/
string findSmallest(vector<string> str, int n, int len)
{
	int i = n - 1;
	int pos = 0;

	while (i > 0)
	{
      pos = 0;
      for (int j = 0 ; j < i ; j++)
	  {
		 //先连接起来看两个字符串的大小比较
		 string  str1 = str[j] + str[j + 1];
		 string str2 = str[j + 1] + str[j];
		   if (str1 > str2)
		   {
			  swap(str, j,  j + 1);
           }
	  }
	 i = pos;
	}
	string s;
	for (i = 0; i < n; i++)
	{
		//将字符串连接
		s += str[i];
	}
	return s;
}

int main(int argc,char* argv[])
{
	vector<string> str{ "abc" ,"de" };
	string s1 = "abc";
	string s2 = "de";
	str.push_back(s1);
    str.push_back(s2);
	cout << findSmallest(str , 2 , 2)<< endl;
	getchar();
	return 0;
}