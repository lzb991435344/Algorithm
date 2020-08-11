package DynamicProgramming;

//最长的单调递增子序列

//dp[8] = {1, 2, 3, 2, 3, 4, 5, 6};
public class Problem_03_GetLIS {
    public int getLIS(int[] A, int n) {
        // dp[i] 表示最后一个字符为A[i]时的最长上升子序列的长度
        int dp[] = new int[n];

        dp[0] = 1;

        int res = 0;
        for (int i = 1; i < n; i++) {

            int j = i;
            int max = 0;
            // 每次从i位置向前遍历找到比i小的位置 取这些位置中子序列长度最长的作为上一个序列
            for (; j >= 0; j--) {
                if (A[j] < A[i] && dp[j] > max) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
            // 记录整个过程中最长的上升子序列
            res = Math.max(dp[i], res);
        }
        return res;
    }

    public static void main(String[] args) {
        int res = 0;
        int[] arr = {1,3,5,2,4,6,7,8};
        int len = arr.length;
       // test t = new test();

      //  res = t.getLIS(arr, len);
       // System.out.println("res is:"+ res);
    }
}
