package String;

//判断括号的有效性
public class Problem_06_ChkParenthesis {

    public static boolean chkParenthesis(String A, int n) {
        int num = 0;
        for(int i = 0; i < n; i++){
            if (A.charAt(i) == '(') {
                num++;
            }
            if (A.charAt(i) == ')') {
                num--;
            }
            if (num < 0) {
                return false;
            }
        }
        return num == 0;
    }

    //返回最长有效括号子串的长度
    //dp:必须以某个位置字符结尾的情况下，最长的有效子串
    //（）（）（）
    // 0 1 2 3 4 5
    // 0 2 0 4 0 6 dp
    //dp[0…i] --> dp[i + 1]  加速
    //（（ ）（ ））
    // 0 1 2 3 4 5  dp[5] = dp[4] + 2(看0位置是不是‘（’)
    //特殊情况：（ ）（ （ ）（ ） ）
    //          0 1  2 3 4  5 6  7
    //          0 2  0 0 2  0 4  6(8)
    //dp[i] + 2 + dp[k](被忽略的部分，往前移一个位置)
    public static int maxLength(String str) {
        if (str == null || str.equals("")) {
            return 0;
        }
        char[] chas = str.toCharArray();
        int[] dp = new int[chas.length];
        int pre = 0;
        int res = 0;
        for (int i = 1; i < chas.length; i++) {
            if (chas[i] == ')') {
                pre = i - dp[i - 1] - 1;
                if (pre >= 0 && chas[pre] == '(') {
                    dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }

    public static void main(String args[]){
        String A = "(())(";
        String B = "(";
        String C = "()(()";
        String D = "()";
        boolean res = false;
        int len = C.length();
        res = chkParenthesis(C, len);
        System.out.println("The res is:" + res);
    }
}
