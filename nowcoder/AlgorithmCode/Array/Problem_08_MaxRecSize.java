package Array;

import java.util.Stack;

//单调栈 MaxRecSize ,MaxTree
//左右两边离他最近的比它大或小的数

//01矩阵为1的最大矩阵--单调栈（数组中无重复元素，求右边或左边离它最近的比它小或大的）
//（1）暴力解法   3 2 1 6 5 7 0  O(N*N)
//  左   右   最近小
// 3   无   2
// 2   无   1
//  1   无   0
//（2）O(N) 保持栈底最小，栈顶最大，依次递增
//  1 2 3 4 5 6  栈中为123456，结算时为空
//  1 2 3 5 6 4  结算完成为1234

//解决问题：行0 1 2 3...N-1 ，必须含有这一行(以这一行为底)情况下的矩阵
//1 0 1 1 1 直方图   1 0 1 1 1   压缩数组，只用一个数组
//1 1 0 1 0         2 1 0 2 0
//1 0 1 1 1         3 0 1 3 1
//最后，以n-1的数组，一直往右括，看能括哪里最大
//单调栈不能出现重复的数值，位置：放入数组的下标值 得到值：直接数组寻址
//O(N*M)

public class Problem_08_MaxRecSize {
    public static int maxRecSize(int[][] map) {
        if (map == null || map.length == 0 || map[0].length == 0) {
            return 0;
        }
        int maxArea = 0;//

        //定义数组为map二维数组列数的一维数组
        int[] height = new int[map[0].length];//直方图数组
        //遍历map数组，确定h[j]的更新策略
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                //更新策略：map[i][j]为0，则h[j]为0，否则为当前数+1
                height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
            }
            //得到直方图数组
            maxArea = Math.max(maxRecFromBottom(height), maxArea);
        }
        return maxArea;
    }
    //从底部开始的符合要求的最大矩阵
    public static int maxRecFromBottom(int[] height) {//heigh为直方图数组
        if (height == null || height.length == 0) {
            return 0;
        }
        int maxArea = 0;
        Stack<Integer> stack = new Stack<Integer>();
        //遍历数组中的数
        for (int i = 0; i < height.length; i++) {
            //java stack.peek()
            //1.	E peek()
            // 2.	查看堆栈顶部的对象，但不从堆栈中移除它。
            //小于等于的时候结算
            while (!stack.isEmpty() && height[i] <= height[stack.peek()]) {//弹出结算时机
                int j = stack.pop();
                //左边界：栈为空时为-1，否则为弹出之后的栈顶
                int k = stack.isEmpty() ? -1 : stack.peek();
                //出来的下标弹出的值 计算面积
                int curArea = (i - k - 1) * height[j];
                maxArea = Math.max(maxArea, curArea);//求最大值
            }
            //栈空，直接压栈
            stack.push(i);
        }
        //栈中剩余数时的结算逻辑
        while (!stack.isEmpty()) {
            int j = stack.pop();
            int k = stack.isEmpty() ? -1 : stack.peek();
            int curArea = (height.length - k - 1) * height[j];
            maxArea = Math.max(maxArea, curArea);
        }
        return maxArea;
    }

    public static void main(String[] args) {
        int[][] map = { { 1, 0, 1, 1 },
                        { 1, 1, 1, 1 },
                        { 1, 1, 1, 0 }, };
        System.out.println(maxRecSize(map));
    }
}
