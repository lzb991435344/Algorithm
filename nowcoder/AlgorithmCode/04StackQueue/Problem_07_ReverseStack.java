package StackQueue;

import java.util.Stack;

public class Problem_07_ReverseStack {
    public Stack<Integer> stack = new Stack<>();
    // 因为这里使用数组代替栈，所以变成真正的栈的时候需要从末尾压栈
    public int[] reverseStack(int[] A, int n) {
        for (int i = n - 1; i >= 0; i--) {
            stack.push(A[i]);
        }

        // 倒序
        reverse(stack);

        // 把元素返回给数组
        for (int i = 0; i < n; i++) {
            A[i] = stack.peek();
            stack.pop();
        }
        return A;
    }

    // 递归函数，用来删除栈底元素并返回栈底元素
    public int get(Stack<Integer> s) {
        int result = s.pop();
        if (s.isEmpty()) {
            return result;
        } else {
            int last = get(s);
            s.push(result);
            return last;
        }
    }

    public void reverse(Stack<Integer> s) {// 倒序函数
        if (s.empty()) {
            return;
        }
        // 每次递归获取当前栈中的栈底元素，然后回溯时依次压入栈中就完成倒序的操作了。
        int last = get(s);
        reverse(s);
        s.push(last);
    }

    public static void main(String[] args) {

    }
}
