package Array;

//02 子矩阵的最大累加和问题
//（1）1；1 2；1 2 3；1 2 3 4；上下两行累加
//（2）2； 2 3； 2，3 4；
//（3）3； 3，4；
//（4）4
//增加一个辅助数组
//复杂度O(M*M*N) 优化：当M>N时，M和N进行转换
public class Problem_06_MaxRectSum {
    public static int maxSum(int[][] m) {
        if (m == null || m.length == 0 || m[0].length == 0) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        int cur = 0;
        int[] s = null;
        for (int i = 0; i != m.length; i++) {
            s = new int[m[0].length];//辅助数组，每次新循环开始时重置
            for (int j = i; j != m.length; j++) {
                cur = 0;
                for (int k = 0; k != s.length; k++) {
                    s[k] += m[j][k];
                    cur += s[k];
                    max = Math.max(max, cur);
                    cur = cur < 0 ? 0 : cur;
                }
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[][] matrix = { { -90, 48, 78 }, { 64, -40, 64 }, { -81, -7, 66 } }; //209
        System.out.println(maxSum(matrix));
    }
}
