
4.明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个
1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，
不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
请你协助明明完成“去重”与“排序”的工作


输入描述:
输入多行，先输入随机整数的个数，再输入相应个数的整数

输出描述:
返回多行，处理后的结果

示例1
输入
3
2
2
1
11
10
20
40
32
67
40
20
89
300
400
15
输出
1
2
10
15
20
32
40
67
89
300
400




#include<iostream>
#include<set>
  
using namespace std;
  
int main(){
    int l = 0;
    while (cin >> l)                  
    {
        int a[1000], tem, i = 0;
        for (int i = 0; i < l; i++) cin >> a[i];
		//去重 + 排序
        set<int> num(a, a + l);
        for (set<int>::iterator it = num.begin(); it != num.end(); it++){
            cout << *it << endl;
        }
    }
    return 0;
}

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
