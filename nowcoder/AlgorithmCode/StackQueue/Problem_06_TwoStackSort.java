package StackQueue;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

public class Problem_06_TwoStackSort {
    public ArrayList<Integer> twoStacksSort(int[] numbers) {
        // 原始数据栈,把数组变成栈
        Stack<Integer> stack = new Stack<>();
        // 辅助栈
        Stack<Integer> help = new Stack<>();

        // 初始化栈
        for (int i = numbers.length - 1; i >= 0; i--) {
            stack.push(numbers[i]);
        }

        // 当数据栈不空时 一直弹出元素
        while (!stack.empty()) {
            int top = stack.peek();
            stack.pop();

            // 此时辅助栈中栈顶元素小于数据栈顶元素时，压栈
            if (help.isEmpty() || top >= help.peek()) {
                help.push(top);
                continue;
            }
            // 若辅助栈顶元素一直大于数据栈顶元素则一直弹出辅助栈元素
            while (!help.empty() && help.peek() > top) {
                //将元素弹回数据栈
                stack.push(help.peek());
                help.pop();
            }
            help.push(top);
        }

        ArrayList<Integer> res = new ArrayList<>();
        while (!help.empty()) {
            res.add(help.peek());
            help.pop();
        }

        return res;
    }
    public static void main(String[] args) {

    }
}
