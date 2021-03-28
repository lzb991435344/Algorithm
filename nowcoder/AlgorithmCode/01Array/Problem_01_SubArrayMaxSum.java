package Array;

//子数组的最大累加和
//拓展  子数组的最大乘积和  分析分成3种情况
//以0....i(包含i位置)的情况下的最大累乘积和
//（1）必须含i - 1 位置  100 10(i - 1) 2(i)
//（2）i-1 和i位置       100 -10(i - 1) -2(i)
//（3）只含有位置i       0.1  0.001  100(i)
// max记录全局最大  两个变量 a i-1最大的累乘积  b i-1最小的累乘积  变量复用

public class Problem_01_SubArrayMaxSum {
    public static int maxSum(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        int cur = 0;
        for (int i = 0; i != arr.length; i++) {
            cur += arr[i];
            max = Math.max(max, cur);
            cur = cur < 0 ? 0 : cur;
        }
        return max;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i != arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr1 = { -2, -3, -5, 40, -10, -10, 100, 1 };
        int res = maxSum(arr1);
        System.out.println("res is:" + res);

        // 0   1   2   3   4   5   6    7
        //-2  -3  -5  40  -10 -10  100  1
        //cur 0   0   0  40   30  20  120  121
        //max -2  -2  -2  40  40  40  120  121

        //特例 arr={-1, -1, -1, -1}   max = -1;
        int[] arr2 = { -2, -3, -5, 0, 1, 2, -1 };
        System.out.println(maxSum(arr2));//

        int[] arr3 = { -2, -3, -5, -1 };
        System.out.println(maxSum(arr3));//-1

        int[] arr4 ={6, -5, -2, 3};
        System.out.println(maxSum(arr4)); //6
    }
}
