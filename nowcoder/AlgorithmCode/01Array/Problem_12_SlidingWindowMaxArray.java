package Array;

import java.util.LinkedList;

//生成窗口的最大值数组
// arr = {4,3,5,4,3,3,6,7}  w = 3
public class Problem_12_SlidingWindowMaxArray {
    public static int[] getMaxWindow(int[] arr, int w) {
        if (arr == null || w < 1 || arr.length < w) {
            return null;
        }
        LinkedList<Integer> qmax = new LinkedList<Integer>();
        int[] res = new int[arr.length - w + 1];
        int index = 0;
        for (int i = 0; i < arr.length; i++) {
            //arr[qmax.peekLast()] 尾部节点存的值
            //while循环一直弹出或者尾部的值>遍历到的值
            while (!qmax.isEmpty() && arr[qmax.peekLast()] <= arr[i]) {
                qmax.pollLast();
            }

            qmax.addLast(i);//加到尾部

            if (qmax.peekFirst() == i - w) {//头部过期
                qmax.pollFirst(); //头部弹出
            }

            //收集最大值
            if (i >= w - 1) {
                res[index++] = arr[qmax.peekFirst()];
            }
        }
        return res;
    }
    // for test
    public static void printArray(int[] arr) {
        for (int i = 0; i != arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = { 4, 3, 5, 4, 3, 3, 6, 7 };
        int w = 3;
        printArray(getMaxWindow(arr, w));
    }

}
