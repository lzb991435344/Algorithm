package Greedy;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Problem_03_IPO {
    public static class Node{
        public int p;
        public int c;

        public Node(int p, int c){
            this.p = p;
            this.c = c;
        }
    }

    //花费比较器
    public static class MinCostComparator implements Comparator<Node>{
        @Override
        public int compare(Node o1, Node o2) {
            return o1.c - o2.c;
        }
    }

    //收益比较器
    public static class MaxCostComparator implements Comparator<Node>{
        @Override
        public int compare(Node o1, Node o2) {
            return o2.p - o1.p;
        }
    }

    public static int findMaximizerCapital(int k, int w, int[] profit, int[] capital ){
        Node[] node = new Node[profit.length];
        for(int i = 0; i < profit.length; ++i){
            node[i] = new Node(profit[i], capital[i]);
        }

        PriorityQueue<Node> minCostQ = new PriorityQueue<>(new MinCostComparator());
        PriorityQueue<Node> maxProfitQ = new PriorityQueue<>(new MaxCostComparator());

        for(int i = 0 ; i < node.length; ++i){
            minCostQ.add(node[i]);
        }

        for(int i = 0; i < k; ++i){
            //先查小根堆中有没有小于w的项目且i<k
            while(!minCostQ.isEmpty() && minCostQ.peek().c <= w){
                maxProfitQ.add(minCostQ.poll());//小于w的项目放入大根堆
            }
            if(maxProfitQ.isEmpty()){//大根堆为空，直接结束
                return w;
            }
            //否则计算收益
            w += maxProfitQ.poll().p; //收益组合
        }
        return w;
    }


    public static void main(String[] args){

    }
}
