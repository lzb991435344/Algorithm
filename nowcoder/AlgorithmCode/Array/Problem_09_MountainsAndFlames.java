package Array;


import java.util.Scanner;
import java.util.Stack;

//单调栈
//数组表示环形的山峰，返回观察到哨岗的数量
// 5 arr = 1 2 4 5 3
//返回7
//数组中含有相等数字的时候怎么计算的，单调栈结算的逻辑
public class Problem_09_MountainsAndFlames {

    //环形数组中，i下标的位置
    public static int nextIndex(int size, int i) {
        return i < (size - 1) ? (i + 1) : 0;
    }

    //计算C(k,2)
    public static long getInternalSum(int n) {
        return n == 1L ? 0L : (long) n * (long) (n - 1) / 2L;
    }

    public static class Pair {
        public int value;//遇到的值
        public int times;//相等的值的个数

        public Pair(int value) {
            this.value = value;
            this.times = 1;
        }
    }

    public static long communications(int[] arr) {
        if (arr == null || arr.length < 2) {
            return 0;
        }
        int size = arr.length;
        int maxIndex = 0;
        for (int i = 0; i < size; i++) {
            //找到最大值的位置
            maxIndex = arr[maxIndex] < arr[i] ? i : maxIndex;
        }
        int value = arr[maxIndex];
        //最大值的下一个数
        int index = nextIndex(size, maxIndex);
        long res = 0L;
        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(value));
        while (index != maxIndex) {//回到最大值说明遍历完成
            value = arr[index];//数组中的当前值
            while (!stack.isEmpty() && stack.peek().value < value) {
                int times = stack.pop().times;
//				res += getInternalSum(times) + times;
//				res += stack.isEmpty() ? 0 : times;
                //C(k,2) + n * 2
                res += getInternalSum(times) + times*2;
            }
            //栈不为空，进行计数
            if (!stack.isEmpty() && stack.peek().value == value) {
                stack.peek().times++;
            } else {//栈为空，重新建新的pair
                stack.push(new Pair(value));
            }
            //继续处理下一个值
            index = nextIndex(size, index);
        }

        //计算栈中的最后的值
        while (!stack.isEmpty()) {
            int times = stack.pop().times;
            //C(k,2)
            res += getInternalSum(times);
            if (!stack.isEmpty()) {
                res += times;
                if (stack.size() > 1) {
                    res += times;
                } else { //stack.size() <= 1
                    res += stack.peek().times > 1 ? times : 0;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int size = in.nextInt();
            int[] arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = in.nextInt();
            }
            System.out.println(communications(arr));
        }
    }
}
