package StackQueue;

import java.util.Stack;

public class Problem_04_TwoStackQueue {
    //两栈实现队列
    public class TwoStackQueue{
        private Stack<Integer> stackPush;
        private Stack<Integer> stackPop;

        public TwoStackQueue(){
            stackPush = new Stack<Integer>();
            stackPop = new Stack<Integer>();
        }

        public void push(int num){
            stackPush.push(num);
        }

        public int poll(){
            if(stackPush.empty() && stackPop.empty()){
                throw  new RuntimeException("queue is empty");
            }else if (stackPop.empty()){
                while(!stackPush.empty()){
                    stackPop.push(stackPush.pop());
                }
            }
            return stackPop.pop();
        }

        public int  peek(){
            if(stackPush.empty() && stackPop.empty()){
                throw  new RuntimeException("queue is empty");
            }else if (stackPop.empty()){
                while(!stackPush.empty()){
                    stackPop.push(stackPush.pop());
                }
            }
            return stackPop.peek();
        }
    }
    public static void main(String[] args) {

    }

}
