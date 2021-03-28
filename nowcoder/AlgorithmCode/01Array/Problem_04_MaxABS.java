package Array;

//05 划分数组，左部减去右部的最大值
public class Problem_04_MaxABS {
    public static int maxABS1(int[] arr) {
        //res设为系统最小
        int res = Integer.MIN_VALUE;
        //定义变量maxLeft,maxRight分别为左部最大，右部最大，并设为0
        int maxLeft = 0;
        int maxRight = 0;
        for (int i = 0; i != arr.length - 1; i++) {
            maxLeft = Integer.MIN_VALUE;
            //小循环寻找左边部分最大，j从0开始，到i+1结束
            for (int j = 0; j != i + 1; j++) {
                maxLeft = Math.max(arr[j], maxLeft);
            }
            maxRight = Integer.MIN_VALUE;
            //小循环找右部最大，j从i+1开始，到N-1结束
            for (int j = i + 1; j != arr.length; j++) {
                maxRight = Math.max(arr[j], maxRight);
            }
            //取值为左边最大减去右边最大的绝对值与res中的最大值
            res = Math.max(Math.abs(maxLeft - maxRight), res);
        }
        return res;
    }

    public static int maxABS2(int[] arr) {
        //定义数组lArr，rArr
        int[] lArr = new int[arr.length];
        int[] rArr = new int[arr.length];
        //初始化lArr的第一个元素
        lArr[0] = arr[0];
        //初始化rArr的最后一个元素
        rArr[arr.length - 1] = arr[arr.length - 1];
        //更新策略，维持左部最大
        for (int i = 1; i < arr.length; i++) {
            lArr[i] = Math.max(lArr[i - 1], arr[i]);
        }
        //维持右部最大
        for (int i = arr.length - 2; i > -1; i--) {
            rArr[i] = Math.max(rArr[i + 1], arr[i]);
        }
        int max = 0;
        //max的更新，两个数组之差的abs
        for (int i = 0; i < arr.length - 1; i++) {
            max = Math.max(max, Math.abs(lArr[i] - rArr[i + 1]));
        }
        return max;
    }
    //直接找数组中的最大最小值，最大减去最小值即结果
    public static int maxABS3(int[] arr) {
        int max = Integer.MIN_VALUE;
        //max有两种可能性，为全局最大 |max左 - max右|
        //（1）max被划分为左部分，目标是让右部分的最大值尽量小，一定包含最后一个数，
        // 只含有最后一个数的时候，max - arr[N - 1]
        //（2）max被划分为右部分，左部分的最大值尽量小，只包含第一个数，最大值尽量小
        // （max）13,43
        //  max - Math.min(arr[0], arr[arr.length - 1])
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(arr[i], max);
        }
        return max - Math.min(arr[0], arr[arr.length - 1]);
    }
    //生成随机数组的算法
    //1.	int num=(int)(Math.random()*n);         //返回大于等于0小于n之间的随机数
    //2.	int num0= m + (int)(Matn.randon()*n);      //返回大于等于m小于m+n（不包括m+n）之间的随机数

    public static int[] generateRandomArray(int length) {
        int[] arr = new int[length];
        for (int i = 0; i != arr.length; i++) {
            arr[i] = (int) (Math.random() * 1000) - 499;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = generateRandomArray(200);
        System.out.println(maxABS1(arr));
        System.out.println(maxABS2(arr));
        System.out.println(maxABS3(arr));
    }
}
