package StackQueue;

public class Problem_01_ArrayStack {
    //用数组实现固定大小的栈
    public class ArrayStack{
        private Integer[] arr;
        private Integer index;

        public ArrayStack(int initSize){
            if(initSize < 0){
                throw new IllegalArgumentException("The init size less than 0");
            }
            arr = new Integer[initSize];
            index = 0;
        }

        public Integer peek(){
            if(index == 0){
                return null;
            }
            //返回index - 1 下标位置的数
            return arr[index - 1];
        }

        public void push(int obj){
            if(index == arr.length){
                throw new IllegalArgumentException("the stack is full");
            }
            arr[index++] = obj;
        }

        public Integer pop(){
            if(index == 0){
                throw new IllegalArgumentException("The stack is empty");
            }
            return arr[--index];
        }
    }
    public static void main(String[] args) {

    }
}
