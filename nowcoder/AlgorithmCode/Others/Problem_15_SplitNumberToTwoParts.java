package Others;

public class Problem_15_SplitNumberToTwoParts {

    // add some other improve strategies
    public static boolean isMagic(int number) {
        int sum = 0;
        int tmp = number;
        //拆分数字，计算数字累加和
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        //判断是否是奇数
        if ((sum & 1) == 1) {
            return false;
        }
        sum = sum / 2;
        //一维数组
        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;
        int cur = 0;
        while (tmp != 0) {
            cur = tmp % 10;
            for (int i = sum; i >= 0; i--) {
                dp[i] = dp[i] || (i - cur >= 0 ? dp[i - cur] : false);
            }
            if (dp[sum]) {
                return true;
            }
            tmp /= 10;
        }
        return false;
    }
    public static void main(String[] args) {
        int test = 242;
        System.out.println(isMagic(test));
    }

}

/**
 * 解析：
 * （1）将试每个数的代价降低，简化成背包问题
 *    2 , 2, 4  [2,2] [4]   sum   找sum/2
 * （2）单独判断一个数（降低代价），然后再判整体
 * （3）题目范围 10^9  数组长度为9位，最大为9个9，最大和为81，每个数判断为O(1)
 *
 *   	 0  1  2  3  4  5  6  7  8
 *   2  T  F  T  F  F	F  F  F  F     sum/2
 * 2  T  F  T  F	 T  F  F
 * 4  T  F  T  F  T  F  T
 * （i,j）含义：自由使用0-i所有的数字加起来，得到j
 * 	前i行推到i+1行
 *   a. T T (i，i+1)
 *   b. F T(i, )
 *
 *   sum/2 == T 满足
 * 优化：
 * （1）	奇数不可能
 * （2）	12（T）    21(F)
 * （3）	数组压缩技巧，数组滚动(只使用2个数组，下一行的判断结果关联上一行)
 * （4）	使用同一数组作为公共访问，使用前清0
 * （5）	只使用一个数组，更新策略将i行的值更新为i+1的值，从右到左更新(为什么不能从左到右更新)
 *
 *       0  1  2  3  4  5
 *   …  T  T   F  T  F  F
 *   2  T  T   T(2+0)  T  F  T(2+3)
 * */

