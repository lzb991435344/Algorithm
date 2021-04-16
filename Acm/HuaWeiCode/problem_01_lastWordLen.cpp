#include <iostream>
//#include <string>

/*

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
*/

int main(){
    std::string s;
    //cin>>s 字符，遇到空格就停止
    //geiline(cin, s) 输入完成整个串
    while(getline(std::cin, s)){
        int len = 0;
        int flag = 1;

        for (int i = s.length() - 1; i >= 0; i--){
            if (flag && s[i] == ' '){
                continue;
            }else if(s[i] != ' '){
                flag = 0;
                ++len;
            }else{
                break;
            }
        }
        std::cout<<len<<std::endl;
    }
    return 0;
}
//get the last world length
//ps:已测试