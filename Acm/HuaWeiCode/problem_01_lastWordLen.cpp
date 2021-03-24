#include <iostream>
//#include <string>


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

//ps:已测试