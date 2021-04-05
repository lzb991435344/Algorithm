

#include <iostream>

using namespace std;

/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

示例 1：
输入：x = 121 输出：true 示例 2：
输入：x = -121 输出：false 解释：从左向右读, 为 -121 。从右向左读, 为 121- 。因此它不是一个回文数。
题解：
如果是回文数，那么不会溢出，负数直接返回false，其他的便是上述题目解法，比较上述题的结果与原始值即可。
*/



class Solution {
public:

bool isPalindrome(int x){
    if (x<0) return false;
        long n = 0;
        int raw_x = x;
        while (x) {
            n = n*10+x%10;
            x/=10;
        }
        int y = ((int)n==n ? int(n) : 0);
        return raw_x == y;
    }
private:

};

int main(){
    Solution s;
    int input;
    cin>>input;
    bool flag = s.isPalindrome(input);

    cout<< flag<<endl;
    return 0;

}

//ps:测试通过