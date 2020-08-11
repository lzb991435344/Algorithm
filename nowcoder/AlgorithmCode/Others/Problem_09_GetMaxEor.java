package Others;


//给定一个数，求子数组的最大异或和
//数组异或和为数组中所有的数异或起来的结果
public class Problem_09_GetMaxEor {


    //暴力解
    public int getMaxEor(int[] arr){
        int max = Integer.MIN_VALUE;

        for(int i = 0; i < arr.length; ++i ){
            for(int start = 0; start < i; start++){
                int res = 0;
                for(int k = start; k < i; k ++ ){
                    res ^= arr[k];
                }
                max = Math.max(res, max);
            }
        }
        return max;
    }


    //优化1
    //结论：0..i异或结果 = (0...start异或结果) ^ (start-1....i)
    public int getMaxEor2(int[] arr){
        int max = Integer.MIN_VALUE;
        int[] dp = new int[arr.length];
        int eor = 0;
        for(int i = 0 ; i < arr.length; ++i){
            eor ^= arr[i];//0...i
            max = Math.max(max, eor);
            for(int start = 1; start <= i; ++start){ //start...i
                int curEor = eor ^ dp[start - 1];
                max = Math.max(max, curEor);
            }
            dp[i] = eor;
        }
        return max;
    }

    public static class Node{
        public Node[] nexts= new Node[2];//路径
        //0和1的路
    }

    public  static class NumTrie{
        public Node head = new Node();
        public void add(int num){
            Node cur = head;
            for(int move = 31; move >= 0; move--){
                int path = ((num >> move) & 1);//符号位来到最后一位，得到 0 或 1
                //无则新建，有则等于本身
                cur.nexts[path] = cur.nexts[path] == null? new Node() :cur.nexts[path];
                //尝试下一个
                cur = cur.nexts[path];
            }
        }

        public int maxXor(int num){//从0....i的异或结果，选择一个最优的结果返回
            Node cur = head;
            int res = 0;

            for(int move = 31; move >= 0; move--){
                int path = (num >> move) & 1;//符号位
                int best = move == 31 ? path : (path ^ 1);//最好的路，符号位和非符号位
                best = cur.nexts[best] != null? best : (best ^ 1);//可能有1，可能没有，取反
                res |= (path ^ best) << move;
                cur = cur.nexts[best];
            }
            return res;
        }
    }


    public static int getMaxEorSubArray(int[] arr){
        if(arr == null || arr.length == 0){
            return 0;
        }
        int max = Integer.MIN_VALUE;
        int eor = 0;
        NumTrie numTrie = new NumTrie();
        numTrie.add(0);

        for(int i = 0; i < arr.length; ++i){
            eor ^= arr[i];
            max = Math.max(numTrie.maxXor(eor), max);
            numTrie.add(eor);
        }
        return max;
    }
    public static void main(String[] args){

    }
}
