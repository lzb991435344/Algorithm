#include <iostream>
#include <string>

/*
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
*/
int main(){
    std::string str;
    std::cin>>str;
    char c;
    std::cin>>c;

    int i = 0;
    int res = 0;
    while(str[i] != '\0'){
        if (c == str[i]){
            res++;
        }else if((c >= 'a' && c <= 'z') && (c - str[i] == 32)){
            res++;
        }else if ((c >= 'A' && c <= 'Z') && (str[i] - c == 32)) {
            res++;
        }

        i++;
    }

    std::cout<< res <<std::endl;
    return 0;
}

//ps:测试通过
//主要考察点：字母大小写的转换