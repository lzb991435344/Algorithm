

5.题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

示例1
输入
abc
123456789
输出
abc00000
12345678
90000000

#include <iostream>
#include <string>

using namespace std;

void subString(string str)
{
    if(str=="")
    {
        return ;
    }
    if(str.size() <= 8)
    {
        str.append(8 - str.size(), '0');
        cout<<str<<endl;
        return;
    }
    cout<<str.substr(0, 8)<<endl;
	//递归输出8位之后的数据
    subString(str.substr(8, str.size()));   
}
int main()
{
    string string1,string2;
    cin>>string1;
    cin>>string2;
    subString(string1);
    subString(string2);
    return 0;  
}

6.题目描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

示例1
输入
0xA
输出
10

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;  
    while(getline(cin,str))
    { 
        int num = 0;
        int index = 16;
        if(str.length()== 0)
        {
            break;
        }
        for(int i = 2; i < str.length(); i++)
        {
            if(str[i] >= '0'&& str[i] <= '9')
            {
                num = num * 16 + (str[i] - '0');
            }
            else
            {
                num = num * 16 + (str[i] - 'A' + 10);
            }
        }
       cout<< num <<endl;
    }
}
