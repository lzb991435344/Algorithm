#include <iostream>
#include <string>

/*
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
*/

void subStr(std::string s){
    if (s == "") {
        return ;
    }
    if (s.size() <= 8){
        s.append(8 - s.size(), '0');
        std::cout<< s <<std::endl;
        return ;
    }
    std::cout<<s.substr(0, 8)<<std::endl;
	//递归输出8位之后的数据
    subStr(s.substr(8, s.size()));
}

int main(){

    std::string str;
    std::cin>>str;
    subStr(str);
    return 0;
}

//ps:测试通过
//递归 + 字符串的使用
//方法  size(),substring(),append()