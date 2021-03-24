#include <iostream>
#include <string>
#include <algorithm>
int main(){
    std::string  str;
    std::cin>>str; //cin>>str遇到空格就结束
    reverse(str.begin(), str.end());

    std::cout<< str <<std::endl;
    return 0;
}
//abcd  --- dcba
//ps:测试通过