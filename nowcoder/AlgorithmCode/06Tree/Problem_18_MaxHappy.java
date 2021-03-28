package Tree;

import java.util.ArrayList;
import java.util.List;

//求最大的活跃度
public class Problem_18_MaxHappy {
    public static class Node{
        public int huo;
        public List<Node> nexts;//存子关系
        public Node(int huo){
            this.huo = huo;
            nexts = new ArrayList<>();
        }
    }

    public static class ReturnType{
        public int lai_huo;
        public int bu_lai_huo;
        public ReturnType(int lai_huo, int bu_lai_huo){
            this.lai_huo = lai_huo;
            this.bu_lai_huo = bu_lai_huo;
        }
    }

    public static int getMaxHuo(Node head){
        ReturnType data = process(head);
        return Math.max(data.lai_huo, data.bu_lai_huo);
    }

    public static ReturnType process(Node head){
        int lai_huo = head.huo;
        int bu_lai_huo = 0;

        for(int i = 0; i < head.nexts.size() ; ++i){
            Node next = head.nexts.get(i);
            ReturnType nextData = process(next);//下一个节点中来的节点的数据，包含数组和活跃度

            lai_huo += nextData.bu_lai_huo;
            bu_lai_huo = Math.max(nextData.lai_huo, nextData.bu_lai_huo);
        }
        return new ReturnType(lai_huo, bu_lai_huo);
    }


    //dp
    public static int maxHappy2(int[][] m){
        int[][] dp = new int[m.length][2];
        boolean[] visited = new boolean[m.length];

        int root = 0;
        for(int i = 0; i < m.length; i++ ){
            if(i == m[i][0]){
                root = i;
            }
        }
        process2(m, dp, visited, root);
        return Math.max(dp[root][0], dp[root][1]);
    }

    public static void process2(int[][] m, int[][] dp, boolean[] visited, int root){
        visited[root] = true;
        dp[root][1] = m[root][1];
        for(int i = 0; i < m.length; i++){
            if(m[i][0] == root && !visited[i]){
                process2(m, dp, visited, i);
                dp[root][1] += dp[i][0];
                dp[root][0] += Math.max(dp[i][1], dp[i][0]);
            }
        }
    }
    public static void main(String[] args){
        int[][] m = {{1,8},{1, 9}, {1, 10}};
        System.out.println(maxHappy2(m));

        Node head = new Node(1);

        head.nexts.add(9, head);
        head.nexts.add(10, head);
        System.out.println(getMaxHuo(head));
    }
}
