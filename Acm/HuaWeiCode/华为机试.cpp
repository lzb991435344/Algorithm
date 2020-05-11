
1.最后一个单词的长度
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

示例1
输入
hello world
输出
5

方法1：
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
	
	//这里注意cin>>str 和 使用getline(cin,str)的区别
    while(getline(cin,s)){
        int l=0,flag=1;
        for(int i=s.length()-1;i>=0;--i){
            if(flag && s[i]==' '){
                continue;
            }
            else if(s[i]!=' '){
                flag = 0;
                ++l;
            }
            else{
                break;
            }
        }
        cout << l<< endl;
    }
    return 0;
}

方法2：
/*使用动态数组来做，输入的字符串依次存入数组中，
最后返回数组中最后一个元素（字符串）的长度*/
#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
int main(){
    string input;
    vector<string>arr;
while(cin>>input){
   //从vector的尾部加一个元素
        arr.push_back(input);
}
//输出该字符的长度
    cout<<arr[arr.size()-1].length()<<endl;     
    return 0;
}


2.输出反转的字符串
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串

示例1
输入
abcd
输出
dcba

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cin>>str;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}

3.输出特定字符个数
题目描述
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

示例1
输入
ABCDEF
A
输出
1

#include <iostream>
using namespace std;
int main()
{
    string s;
    char c;
    int i=0,res=0;
    cin>>s;
    cin>>c;
    while(s[i]!='\0')
    {
        if(c == s[i])
            res++;
		//大小写转换
        else if((c >= 'A' && c <= 'Z')&&(c == s[i] - 32)) //大写字母 + 32 = 小写字母
            res++;
       else if((c >= 'a' && c <= 'z')&&(c == s[i] + 32))
          res++;                
        i++;
    }
     cout<<res<<endl;
}

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
