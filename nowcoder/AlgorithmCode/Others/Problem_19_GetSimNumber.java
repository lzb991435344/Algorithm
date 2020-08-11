package Others;

import java.util.Scanner;

/**找到相似的数列
 *性质3：
 * (1)长度为n
 * (2)数列中每个数都在1-k之间
 * (3)相邻位置A和B,有A<=B 或 A mol B != 0
 *
 * n = 4, k = 7
 *  1 7 7 2
 *
 *  4 4 4 2 (不满足)
 *
 * 2 2
 *3
 * */

public class Problem_19_GetSimNumber {

    public static long number1(int n, int k) {
        return process(1, n, k);
    }

    //pre前一个数
    //n 选择n个格子
    //k,1-k上
    public static long process(int pre, int n, int k) {
        if (n == 0) {//前面的位置都填满了，找到一种合法的可能性
            return 1L;
        }
        long sum = 0;

        //当前cur到k都合理
        //当前选择了cur,之后的解是多少
        for (int cur = pre; cur <= k; cur++) {
            sum += process(cur, n - 1, k);
        }

        // 1到pre
        for (int cur = 1; cur < pre; cur++) {
            //求余为0，则加0，否则加上前一个数
            sum += (pre % cur) != 0 ? process(cur, n - 1, k) : 0;
        }

        return sum % 1000000007L;
    }

    public static long number2(int n, int k) {
        long[][] dp = new long[k + 1][n];
        for (int i = 0; i < k + 1; i++) {
            dp[i][0] = 1L;
        }
        for (int col = 1; col < n; col++) {
            for (int row = 1; row < k + 1; row++) {
                long sum = 0L;
                for (int cur = row; cur <= k; cur++) {
                    sum += dp[cur][col - 1];
                }
                for (int cur = 1; cur < row; cur++) {
                    sum += (row % cur) != 0 ? dp[cur][col - 1] : 0;
                }
                dp[row][col] = sum % 1000000007L;
            }
        }
        long res = 0L;
        for (int i = 1; i <= k; i++) {
            res += dp[i][n - 1];
            res %= 1000000007L;
        }
        return res;
    }

    public static long number3(int n, int k) {
        long[][] dp = new long[k + 1][n];
        for (int i = 0; i < k + 1; i++) {
            dp[i][0] = 1L;
        }
        for (int col = 1; col < n; col++) {
            long sum = 0;
            for (int row = 1; row < k + 1; row++) {
                sum += dp[row][col - 1];
                sum %= 1000000007L;
            }
            for (int row = 1; row < k + 1; row++) {
                long noInclude = 0L;
                for (int cur = row * 2; cur <= k; cur += row) {
                    noInclude += dp[cur][col - 1];
                    noInclude %= 1000000007L;
                }
                dp[row][col] = (sum - noInclude) % 1000000007L;
            }
        }
        long res = 0L;
        for (int i = 1; i <= k; i++) {
            res += dp[i][n - 1];
            res %= 1000000007L;
        }
        return res;
    }

    public static long number4(int n, int k) {
        long[] dp = new long[k + 1];
        for (int i = 0; i < k + 1; i++) {
            dp[i] = 1L;
        }
        for (int col = 1; col < n; col++) {
            long sum = 0;
            for (int row = 1; row < k + 1; row++) {
                sum += dp[row];
                sum %= 1000000007L;
            }
            for (int row = 1; row < k + 1; row++) {
                long noInclude = 0L;
                for (int cur = row * 2; cur <= k; cur += row) {
                    noInclude += dp[cur];
                    noInclude %= 1000000007L;
                }
                dp[row] = (sum - noInclude) % 1000000007L;
            }
        }
        long res = 0L;
        for (int i = 1; i <= k; i++) {
            res += dp[i];
            res %= 1000000007L;
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(number1(6, 9));
        System.out.println(number2(6, 9));
        System.out.println(number3(6, 9));
        System.out.println(number4(6, 9));

        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            int k = in.nextInt();
            System.out.println(number2(n, k));
        }
        in.close();
    }

}
