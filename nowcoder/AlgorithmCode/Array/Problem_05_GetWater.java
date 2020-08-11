package Array;

import java.util.HashMap;
import java.util.Map;

//03 容器装水的数量
//思路：确定i位置的左边最大值和右边的最大值，两者取小值，然后减去当前i位置的高度，得到水柱的高度
//0...i-1  i+1...N-1


//时间复杂度O(N*N)
public class Problem_05_GetWater {
    public static int getWater1(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0;
        }
        int value = 0;
        for (int i = 1; i < arr.length - 1; i++) {
            int leftMax = 0;
            int rightMax = 0;
            for (int l = 0; l < i; l++) {
                leftMax = Math.max(arr[l], leftMax);
            }
            for (int r = i + 1; r < arr.length; r++) {
                rightMax = Math.max(arr[r], rightMax);
            }
            value += Math.max(0, Math.min(leftMax, rightMax) - arr[i]);
        }
        return value;
    }
    // 3 - 1 = 2
    // 3 - 2 = 1
    //value = 2 + 1 = 3

    //优化 O(N) O(N)
    // 1 2 3 0 1 6 2 3 4 5
    //1  2 3 3 3 6 6 6 6 6 提前记录最大的值，l[i]是0...i的最大值 r[i]是 i...n-1的最大值  遍历一遍O(N)，取O(1)
    public static int getWater2(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0;
        }
        int n = arr.length - 2;
        int[] leftMaxs = new int[n];
        leftMaxs[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMaxs[i] = Math.max(leftMaxs[i - 1], arr[i]);
        }
        int[] rightMaxs = new int[n];
        rightMaxs[n - 1] = arr[n + 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMaxs[i] = Math.max(rightMaxs[i + 1], arr[i + 2]);
        }
        int value = 0;
        for (int i = 1; i <= n; i++) {
            value += Math.max(0, Math.min(leftMaxs[i - 1], rightMaxs[i - 1]) - arr[i]);
        }
        return value;
    }

    public static int getWater3(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0;
        }
        int n = arr.length - 2;
        int[] rightMaxs = new int[n];
        rightMaxs[n - 1] = arr[n + 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMaxs[i] = Math.max(rightMaxs[i + 1], arr[i + 2]);
        }
        int leftMax = arr[0];
        int value = 0;
        for (int i = 1; i <= n; i++) {
            value += Math.max(0, Math.min(leftMax, rightMaxs[i - 1]) - arr[i]);
            leftMax = Math.max(leftMax, arr[i]);
        }
        return value;
    }
    //O(N)
    //头尾指针 lmax从左往右滑记录最大值   rmax从右往左滑动的最大值  lmax，rmax那边小结算那边的值，直到相遇
    // 6 13 4 .....5 10
    //lmax
    public static int getWater4(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0;
        }
        int value = 0;
        int leftMax = arr[0];
        int rightMax = arr[arr.length - 1];
        int l = 1;
        int r = arr.length - 2;
        while (l <= r) {
            if (leftMax <= rightMax) {
                value += Math.max(0, leftMax - arr[l]);
                leftMax = Math.max(leftMax, arr[l++]);
            } else {
                value += Math.max(0, rightMax - arr[r]);
                rightMax = Math.max(rightMax, arr[r--]);
            }
        }
        return value;
    }

    public static int[] generateRandomArray() {
        int[] arr = new int[(int) (Math.random() * 98) + 2];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int) (Math.random() * 200) + 2;
        }
        return arr;
    }

    public static void main(String[] args) {
        for (int i = 0; i < 1000000; i++) {
         int[] arr = generateRandomArray();
         int r1 = getWater1(arr);
         int r2 = getWater2(arr);
         int r3 = getWater3(arr);
         int r4 = getWater4(arr);
         if (r1 != r2 || r3 != r4 || r1 != r3) {
         System.out.println("What a fucking day! fuck that! man!");
         }
         }

         HashMap<String,String> map = new HashMap<String,String>();

         for(Map.Entry<String,String> entry : map.entrySet()){
         System.out.println(entry.getKey()+" , "+ entry.getValue());
         }
         int[] arr={3,1,2,4};
         int r1 = getWater2(arr);
         System.out.println("res is:"+ r1);
    }
}
