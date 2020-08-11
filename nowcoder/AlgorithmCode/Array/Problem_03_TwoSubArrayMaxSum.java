package Array;

//04不相交数组的最大和
//0.....N-1
//0...1
//0...2
//0...3
//求出每一段的最大累加和
//类比map   (i==0,1)
//          (i==1,3)

//0......i arr1[0...i]
//i......n-1 arr2[i...N-1]
//2
//arr1[2] + arr2[3]

//只用一个数组（从右往左计算数组） + max
//结算的时候从左往右计算
public class Problem_03_TwoSubArrayMaxSum {
    public static int twoSubArrayMaxSum(int[] arr) {
        if (arr == null || arr.length < 2) {
            return 0;
        }
        //该数组保存逆向遍历过程中cur与max之间的最大值
        int[] rArray = new int[arr.length];
        int max = Integer.MIN_VALUE;
        int cur = 0;
        //逆向遍历
        for (int i = arr.length - 1; i > 0; i--) {
            //注意顺序，先加数组，比较大小，赋值，最后判断cur<0?
            cur += arr[i];
            max = Math.max(max, cur);
            rArray[i] = max;//记录其中的得到的最大值
            cur = cur < 0 ? 0 : cur;
        }
        int res = Integer.MIN_VALUE;
        max = Integer.MIN_VALUE;
        cur = 0;
        //正向遍历
        for (int i = 0; i < arr.length - 1; i++) {
            cur += arr[i];
            max = Math.max(max, cur);
            //从数组的第二个元素加，，，
            res = Math.max(res, max + rArray[i + 1]);
            cur = cur < 0 ? 0 : cur;
        }
        return res;
    }

    // for test
    //暴力解，答案一定对的那种
    public static int rightAnswer(int[] arr) {
        if (arr == null || arr.length < 2) {
            return 0;
        }
        int res = Integer.MIN_VALUE;
        for (int p = 0; p < arr.length - 1; p++) {
            res = Math.max(res, maxSum(arr, 0, p) + maxSum(arr, p + 1, arr.length - 1));
        }
        return res;
    }

    // for test
    public static int maxSum(int[] arr, int l, int r) {
        int max = Integer.MIN_VALUE;
        int cur = 0;
        for (int i = l; i <= r; i++) {
            cur += arr[i];
            max = Math.max(max, cur);
            cur = cur < 0 ? 0 : cur;
        }
        return max;
    }

    // for test
    public static int[] generateRandomArray() {
        int[] res = new int[(int) (Math.random() * 10) + 1];
        for (int i = 0; i < res.length; i++) {
            //[0,20) - 10 ----(-10, 10)
            res[i] = (int) (Math.random() * 20) - 10;
        }
        return res;
    }

    // for test
    public static void main(String[] args) {
        int testTime = 5000000;
        boolean hasErr = false;
        for (int i = 0; i < testTime; i++) {
            int[] test = generateRandomArray();
            if (twoSubArrayMaxSum(test) != rightAnswer(test)) {
                hasErr = true;
            }
        }
        if (hasErr) {
            System.out.println("23333333");
        } else {
            System.out.println("66666666");
        }
    }
}
