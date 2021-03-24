#include <iostream>
#include <string>
#include <algorithm>
/*
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
*/
int main(){
    std::string  str;
    std::cin>>str; //cin>>str遇到空格就结束
    reverse(str.begin(), str.end());

    std::cout<< str <<std::endl;
    return 0;
}
//abcd  --- dcba
//ps:测试通过