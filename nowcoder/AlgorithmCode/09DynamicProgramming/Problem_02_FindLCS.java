package DynamicProgramming;

//最长的公共子序列（可以不连续）


/*
  0  1  2  3  4  5  6  7  8  9  10  11
0  0  1  1  1  1  1  1  1  1  1  1   1
1  0  1  1  1  1  1  2  2  2  2  2   2
2  0  1  1  2  2  2  2  2  2  2  2   2
3  0  1  1
4
5
6
7
8
9                                    6

* */
public class Problem_02_FindLCS {
    public int findLCS(String A, int n, String B, int m) {
        // dp[i][j] 代表 A字符串0..i和B字符串0..j的最长公共子序列长度
        int dp[][] = new int[n][m];

        for (int i = 0; i < n; i++) {// 赋值第一列 一旦遇上和B第一个字符相等的 就后面都赋值为1
            if (A.charAt(i) == B.charAt(0)) {
                dp[i][0] = 1;
                while (i < n) {
                    dp[i][0] = 1;
                    i++;
                }
                break;
            }
        }
        // 赋值第一行 一旦遇上和A第一个字符相等的 就后面都赋值1
        for (int i = 0; i < m; i++) {
            if (A.charAt(0) == B.charAt(i)) {
                dp[0][i] = 1;
                while (i < m) {
                    dp[0][i] = 1;
                    i++;
                }
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A.charAt(i) == B.charAt(j)) {// 此时i和j字符相等 则来自i-1 j-1字符加1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);// 取两者最大
                }
            }
        }

        return dp[n - 1][m - 1];
    }
    public static void main(String[] args) {
        String s1 = "1A2C3D4B56";
        String s2 = "B1D23CA45B6A";

        int res = 0;
        int n = s1.length();
        int m = s2.length();

      //  test t = new test();
       // res = t.findLCS(s1,n,s2,m);
    }
}
