package Array;

import java.util.LinkedList;

//子数组和小于等于num的数量
//维持窗口最大最小值的结构
//分别代表子数组中的最大最小值
// max(arr[i...j]) - min(arr[i....j]) <= num
//o(N^3)
public class Problem_11_AllLessNumSubArray {
    public static int getnum1(int[] arr, int num){
        int res = 0;
        for(int start = 0; start < arr.length; ++start){
            for(int end = start; end < arr.length; ++end){
                if(isvalid(arr, start, end, num)){
                    res++;
                }
            }
        }
        return res;
    }
    public static boolean isvalid(int[] arr, int start, int end, int num){
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for(int i = 0; i < arr.length; ++i){
            max = Math.max(max, arr[i]);
            min = Math.min(min, arr[i]);
        }
        return max - min <= num;
    }

    //O(N)
    public static int getNum(int[] arr, int num) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        LinkedList<Integer> qmin = new LinkedList<Integer>();
        LinkedList<Integer> qmax = new LinkedList<Integer>();
        int i = 0;//start
        int j = 0;//end
        int res = 0;
        while (i < arr.length) {
            while (j < arr.length) {
                //qmin的更新策略
                while (!qmin.isEmpty() && arr[qmin.peekLast()] >= arr[j]) {
                    qmin.pollLast();
                }
                qmin.addLast(j);

                //qmax更新策略
                while (!qmax.isEmpty() && arr[qmax.peekLast()] <= arr[j]) {
                    qmax.pollLast();
                }
                qmax.addLast(j);

                //是否满足
                if (arr[qmax.getFirst()] - arr[qmin.getFirst()] > num) {
                    break;
                }
                j++;
            }

            //是否过期
            if (qmin.peekFirst() == i) {
                qmin.pollFirst();
            }
            if (qmax.peekFirst() == i) {
                qmax.pollFirst();
            }


            res += j - i;
            i++;
        }
        return res;
    }

    // for test
    public static int[] getRandomArray(int len) {
        if (len < 0) {
            return null;
        }
        int[] arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = (int) (Math.random() * 10);
        }
        return arr;
    }

    // for test
    public static void printArray(int[] arr) {
        if (arr != null) {
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] arr = getRandomArray(30);
        int num = 5;
        printArray(arr);
        System.out.println(getNum(arr, num));

    }

}
