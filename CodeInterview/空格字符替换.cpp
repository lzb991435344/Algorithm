#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
   请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
>We Are Happy
>
>We%20Are%20Happy
*/

class relplaceSpace
{
public:

	void replacetest(char* str , int length)
	{
		int i ,j ;		
		int len = length;
		//反向遍历，遍历整个字符串
		for (i = length - 1 ; i >= 0 ; i--)
		{
			if (str[i] == ' ')
			{
				//替换空格实际上增加的长度为2
				len = len + 2;
				//循环将字符写入，复制字符串
				for (j = len - 1 ;j > i + 2 ; j--)
				{
					//当前的偏移位置，插入字符的时候
					//增加了两个长度的长度
					str[j] = str[j - 2];
				}
				//将要替换的字符串输入
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '\%';
			}

		}
		str[len] = '\0';
	}

	//有点在于减少了字符的移位操作
	void replaceBetter(char* str, int length)
	{
		int len = length;
		int i;
		int count = 0;
		//这里计算总的空格数
		for(i=0 ; i < length - 1 ; i++)
		{
			if (str[i] == ' ')
			{
				count++;
			}
		}

	    len = length + 2 * count;//计算增长的总长度
		int j;
		for (i = length -1 ,j = len -1 ; (i >= 0 && j >= 0);)
		{
			if (str[i] == ' ')
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
				i--;//**重要**//
			//当前i的位置要进行减1，当不是空格的位置的时候进行原来字符串中的字符复制
			}
			else
			{
				//不是空格，进行字符串的复制
				str[j--] = str[i--];
			}
		}
		str[len] = '\0';//字符数组后面加 '\0'
	}
};


int main()
{
	char str1[10 + 1] = "a b c d";
	char str2[11] = "a b c d";
	relplaceSpace rs;
	rs.replacetest(str1 , 10);
	cout << str1 << endl;
	cout << " " <<endl;

	rs.replaceBetter(str2, 10);
	cout << str2<< endl;
	system("pause");
	getchar();
	return 0;
}