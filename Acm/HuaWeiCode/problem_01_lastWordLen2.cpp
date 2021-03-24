#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> s;
    std::string str;
    while(std::cin>>str){
        s.push_back(str);
    }
    std::cout<< s.size() <<std::endl;
    std::cout<< s.max_size() <<std::endl;
    std::cout<< s[s.size() - 1].length() <<std::endl;
    return 0;
}

//ps:测试通过