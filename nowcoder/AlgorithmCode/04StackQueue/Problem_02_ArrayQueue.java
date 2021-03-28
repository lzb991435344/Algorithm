package StackQueue;

public class Problem_02_ArrayQueue {
    public class ArrayQueue{
        private Integer[] arr;
        private Integer size;
        private Integer start;
        private Integer end;

        public  ArrayQueue(int initSize){
            if(initSize < 0){
                throw new IllegalArgumentException("the initSize less than 0");
            }

            arr = new Integer[initSize];
            size = 0;
            start = 0;
            end = 0;
        }

        public Integer peek(){
            if(size == 0){
                return null;
            }
            return arr[start];
        }

        public void push(int obj){
            if(size == arr.length){
                throw new IllegalArgumentException("the queue is full");
            }
            size++;
            arr[end] = obj;
            //end回到最后的位置，变成0
            end = end == arr.length? 0 : end + 1;
        }

        public Integer poll(){
            if(size == 0){
                throw new IllegalArgumentException("The queue is empty");
            }

            size--;
            int tmp = start;
            start = start == arr.length - 1 ? 0 : start + 1;
            return  arr[tmp];
        }
    }
    public static void main(String[] args) {

    }
}
