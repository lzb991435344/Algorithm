#include <iostream>
#include <stdint.h>
using namespace std;

/* 190 颠倒二进制位
    颠倒给定的32位无符号整数的二进制位示例 1：

输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100
表示无符号整数 43261596， 因此返回 964176192，
其二进制表示形式为 00111001011110000010100101000000。

模拟： 直接模拟，对新数进行左移，对每一位取&，拿出当前数，加到新数中，旧数右移。

*/

class Solution{
public:
    //直接模拟
    uint32_t reverseBin(uint32_t n){
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans<<= 1;
            ans+=n & 1;
            n>>= 1;
        }
        return ans;
    }

private:

};

int main(){
    Solution s;
    uint32_t input;
    cin>>input;
    uint32_t res = s.reverseBin(input);
    cout<< res <<endl;
    return 0;
}


//ps:测试通过
/*
compile:g++ problem_02_ReverseBinary.cpp -o reverseBin
input:43261596
output:964176192

*/