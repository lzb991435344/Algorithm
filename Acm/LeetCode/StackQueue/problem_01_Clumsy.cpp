#include <iostream>
#include <stack>
/*1006
题目： 将诸如4的阶层换算成x/+-操作，例如：5就等于5*4/3-2+1。
示例 1：
输入：4
输出：7
解释：7 = 4 * 3 / 2 + 1
*/

using namespace std;
class Solution {
public:
    int clumsy(int N){
        stack<int> st;
        st.push(N);
        N--;
        int index = 0;
        while (N) {
            int x;
            switch(index % 4) {
                case 0:
                    x = st.top();
                    st.pop();
                    st.push(x * N);
                    break;
                case 1:
                    x = st.top();
                    st.pop();
                    st.push(x / N);
                    break;
                case 2:
                    st.push(N);
                    break;
                case 3:
                    st.push(-N);
                    break;
            }
            index++;
            N--;
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }

    int clumsy2(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4){
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
private:

};

int main(){
    Solution s;
    int input;
    cin>>input;
    int res = s.clumsy(input);
    cout<< res <<endl;

    return 0;
}

//ps:测试通过