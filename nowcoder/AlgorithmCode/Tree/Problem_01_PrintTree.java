package Tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Problem_01_PrintTree {
    public class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    };

    public static int[][] printTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        ArrayList<Integer> value = new ArrayList<>();
        TreeNode last = root;
        TreeNode nlast = null;
        while (!queue.isEmpty()) {
            TreeNode cur = queue.poll();
            value.add(cur.val);
            if (cur.left != null) {
                queue.add(cur.left);
                nlast = cur.left;
            }
            if (cur.right != null) {
                queue.add(cur.right);
                nlast = cur.right;
            }
            if (last == cur) {
                list.add(value);
                value = new ArrayList<>();
                last = nlast;
            }
        }

        int[][] res = new int[list.size()][];
        for (int i = 0; i < list.size(); i++) {
            ArrayList<Integer> t = list.get(i);
            res[i] = new int[t.size()];
            for (int j = 0; j < t.size(); j++) {
                res[i][j] = t.get(j);
            }
        }
        return res;
    }
    public static void main(String args[]){
        //TreeNode root = new TreeNode(0);
       /** TreeNode tree = new TreeNode(1);
        TreeNode node1= new TreeNode(2);
        TreeNode node2= new TreeNode(3);
        //System.out.println("The root value is:" + tree.val);
        tree.left = node1;
        tree.right = node2;

        int [][]res  = printTree(tree);
        for(int i = 0; i < res.length; ++i){
            for(int j = 0; j < res[0].length; ++j){
                System.out.println(res[i][j]);
            }
        }*/
    }

}
