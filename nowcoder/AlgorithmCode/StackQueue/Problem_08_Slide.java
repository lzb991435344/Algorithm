package StackQueue;

import java.util.ArrayList;

//滑动窗口
public class Problem_08_Slide {
    public int[] slide(int[] arr, int n, int w) {
        // 双端队列 保存数组下标索引
        ArrayList<Integer> list = new ArrayList<>();

        // 存放最大值结果数组
        int[] res = new int[n - w + 1];

        for (int i = 0; i < n; i++) {
            // 当队列的头元素超出了当前滑动窗口的范围时，就移除。
            if (!list.isEmpty() && list.get(0) <= i - w) {
                list.remove(0);
            }
            // 当前队列的队尾元素的值小于数组值，移除队尾元素
            while (!list.isEmpty() && arr[list.get(list.size() - 1)] < arr[i]) {
                list.remove(list.size() - 1);
            }
            // 队尾元素大于数组元素，加入当前索引
            if (list.isEmpty() || arr[list.get(list.size() - 1)] > arr[i]) {
                list.add(i);
            }
            // 赋值最大值
            if (i >= w - 1) {
                res[i - w + 1] = arr[list.get(0)];
            }
        }
        return res;
    }
    public static void main(String[] args) {
       // test t = new test();
        int[] arr = {2,3,4,2,6,2,5,1};
        // int[] arr = {1,1,1,1,1,1,1,1};
        int len = arr.length;
        int w = 3;
        int[] res ={0};

       // res = t.slide(arr, len, w);
        for(int i = 0; i < res.length; ++i){
            System.out.println(res[i]);
        }
    }
}
