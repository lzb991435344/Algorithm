package DynamicProgramming;
/*打气球
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it
represented by array nums. You are asked to burst all the balloons. If the you burst
balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right
are adjacent indices of i. After the burst, the left and right then becomes adjacent.

        Find the maximum coins you can collect by bursting the balloons wisely.

        Note:

        You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
        0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
        Example:

        Input: [3,1,5,8]
        Output: 167
        Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
        coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

public class Problem_10_MaxConins {
    public static int maxCoins1(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        if (arr.length == 1) {
            return arr[0];
        }
        //辅助数组
        int[] help = new int[arr.length + 2];
        help[0] = 1;
        help[help.length - 1] = 1;
        //中间拷贝
        for (int i = 0; i < arr.length; i++) {
            help[i + 1] = arr[i];
        }

        // 1 ~ N-2
        return process(help, 1, help.length - 2);
    }

    //选择打的位置
    public static int process(int[] arr, int l, int r) {
        if (l == r) {//范围内只有一个数
            return arr[l - 1] * arr[l] * arr[r + 1];
        }

        //单独尝试l,r
        //arr[l - 1] * arr[l] * arr[r + 1] + process(arr, l + 1, r) 最后打l
        //arr[l - 1] * arr[r] * arr[r + 1] + process(arr, l, r - 1) 最后打r
        int max = Math.max(arr[l - 1] * arr[l] * arr[r + 1] + process(arr, l + 1, r),
                arr[l - 1] * arr[r] * arr[r + 1] + process(arr, l, r - 1));

        //(L,R)之间的数进行尝试
        for (int i = l + 1; i < r; i++) {
            // process(arr, l, i - 1)  l---i
            //process(arr, i + 1, r)   i+1---r
            //总共的收益
            max = Math.max(max, arr[l - 1] * arr[i] * arr[r + 1] + process(arr, l, i - 1) + process(arr, i + 1, r));
        }

        //取最大值
        return max;
    }


    //dp[][]
    public static int maxCoins2(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int size = arr.length;
        int[] all = new int[size + 2];
        all[0] = 1;
        all[size + 1] = 1;
        for (int i = 0; i < size; i++) {
            all[i + 1] = arr[i];
        }
        int[][] dp = new int[size][size];
        for (int i = size - 1; i >= 0; i--) {
            dp[i][i] = all[i] * all[i + 1] * all[i + 2];
            for (int j = i + 1; j < size; j++) {
                int coins = 0;
                for (int k = i; k <= j; k++) {
                    coins = all[i] * all[k + 1] * all[j + 2];
                    coins += k != i ? dp[i][k - 1] : 0;
                    coins += k != j ? dp[k + 1][j] : 0;
                    dp[i][j] = Math.max(dp[i][j], coins);
                }
            }
        }
        return dp[0][size - 1];
    }

    public static void main(String[] args) {
        int[] arr = { 3, 2, 6, 4, 2, 7, 4, 7, 9 };
        System.out.println(maxCoins1(arr));
        System.out.println(maxCoins2(arr));
    }
}
