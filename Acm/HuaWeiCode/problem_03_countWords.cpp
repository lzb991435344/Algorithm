#include <iostream>
#include <string>

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