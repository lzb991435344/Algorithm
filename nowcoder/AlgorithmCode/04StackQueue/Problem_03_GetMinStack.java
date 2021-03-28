package StackQueue;

import java.util.Stack;

public class Problem_03_GetMinStack {
    //设计一个特殊栈，实现getmin获取最小值
    public class myStack {
        private Stack<Integer> stackData;
        private Stack<Integer> stackMin;

        public myStack() {
            this.stackData = new Stack<Integer>();
            this.stackMin = new Stack<Integer>();
        }

        public void push(int newnum) {
            if (this.stackMin.isEmpty()) {
                this.stackMin.push(newnum);
            } else if (newnum < this.getmin()) {
                this.stackMin.push(newnum);
            } else {
                //取最小栈的栈顶重复压栈
                int newin = this.stackMin.peek();
                this.stackMin.push(newin);
            }
            //数据栈一直压栈
            this.stackData.push(newnum);
        }

        public int pop() {
            if (this.stackData.isEmpty()) {
                throw new IllegalArgumentException("the stack is empty");
            }

            //同步弹出
            this.stackMin.pop();
            return this.stackData.pop();

        }

        public Integer getmin() {
            if (this.stackMin.isEmpty()) {
                throw new IllegalArgumentException("the stack is empty");
            }
            return this.stackMin.peek();
        }

    }
    public static void main(String[] args) {

    }
}
