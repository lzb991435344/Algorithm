

#include <iostream>
using namespace std;

/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：

输入：x = 123 输出：321

示例 2：

输入：x = -123 输出：-321

*/



class Solution {
public:
    //直接采用long强制转换与int数进行比较，判断是否越界。
    int reverse(int x) {
        long n = 0;
        while (x) {
            n = n*10+x%10;
            x/=10;
        }
        return (int)n==n ? int(n) : 0;
    }

    /*
    int范围[-2^31,2^31-1]，即[-2147483648,2147483647]。
    在计算过程中，根据公式：n = n*10+yu，如果n>214748364 或者 n=214748364并且余数大于7，返回0；
    同样对于负数，如果n<-214748364 或者 n=-214748364并且余数小于8，返回0.
    */
    int reverseInteger(int x){
        int n = 0;
        while (x) {
            int yu = x%10;
            if (n > 214748364 || (n == 214748364 && yu > 7)) return 0;
            if (n < -214748364 || (n == -214748364 && yu < -8)) return 0;
            n = n*10 + yu;
            x/=10;
        }
        return n;
    }

    /*
    不用判断余数，直接判断n。
    */
    int reverseInteger2(int x) {
        int n = 0;
        while (x) {
            if (n > 214748364 || n<-214748364) return 0;
            int yu = x%10;
            n = n*10 + yu;
            x/=10;
        }
        return n;
    }

    private:
};

int main(){

    Solution s;
    int x;
    cin>>x;
    int res = s.reverse(x);
    cout<< res<<endl;
    return 0;
}

//ps:测试通过


