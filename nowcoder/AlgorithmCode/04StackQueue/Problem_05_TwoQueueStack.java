package StackQueue;

import java.util.LinkedList;
import java.util.Queue;

public class Problem_05_TwoQueueStack {
    //两队列实现栈
    public class TwoQueueStack{
        private Queue<Integer> data;
        private Queue<Integer> help;

        public TwoQueueStack(){
            data = new LinkedList<Integer>();
            help = new LinkedList<Integer>();
        }

        public void push(int num){
            data.add(num);
        }

        public int peek(){
            if(data.isEmpty()){
                throw new IllegalArgumentException("the stack is empty");
            }

            while(data.size() > 1){
                help.add(data.poll());
            }
            int res = data.poll();
            help.add(res);
            swap();
            return res;
        }

        public int pop(){
            if(data.isEmpty()){
                throw new IllegalArgumentException("the stack is empty");
            }

            while(data.size() > 1){gorithm
                help.add(data.poll());
            }
            int res = data.poll();
            swap();
            return res;
        }

        private void swap(){
            Queue<Integer> tmp = help;
            help = data;
            data = tmp;
        }
    }
    public static void main(String[] args) {

    }
}
