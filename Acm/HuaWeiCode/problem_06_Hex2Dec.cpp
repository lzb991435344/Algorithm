/*
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
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    //输入整个完整的串
    while(getline(cin,str))
    {
        int num = 0;
        int index = 16;
        if(str.length()== 0)
        {
            break;
        }
        //剔除 ox字符
        for(int i = 2; i < str.length(); i++)
        {
            if(str[i] >= '0'&& str[i] <= '9') //数字的情况
            {
                num = num * 16 + (str[i] - '0');
            }
            else //字母转换成十进制，包含大小写
            {
                num = num * 16 + (str[i] - 'A' + 10);
            }
        }
    cout<< num <<endl;
    }
}

//ps:测试通过
//进制之间的转换
