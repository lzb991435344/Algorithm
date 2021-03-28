package Tree;

import java.util.Stack;
/**
 * 对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。
 *  给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。
 * */
public class Problem_02_ChkIdentical {
    public static class TreeNode {
        int val = 0;
       TreeNode left = null;
       TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    };

    public static boolean chkIdentical(TreeNode A, TreeNode B) {
        // write code here
        StringBuilder builder = new StringBuilder();
        String s = convertTreeToStr(A, builder);
        builder.delete(0, builder.length());
        String s1 = convertTreeToStr(B, builder);
        //判断在A串中是否有B串存在
        return kmp(s, s1) != -1;
    }
    //kmp算法 具体详解请看http://www.jianshu.com/p/826480d851ee

    private static int kmp(String a,String b){
        int a_len = a.length();
        int b_len = b.length();
        int i = 0,j = 0;
        int [] next = next(b);
        while (i < a_len && j < b_len){
            //单个字符的比较
            //相等则进行下一个位置
            if (j == -1 || a.charAt(i) == b.charAt(j)){
                i++;
                j++;
            }else {
                //将模式串移动到next[当前位置]
                j = next[j];
            }
        }
        if (j == b_len){
            return i - j;
        }else {
            return -1;
        }
    }
    //生成next数组
    // 有两个指针 j和k。 当k=-1或者在J和K位置的字符相等时，两指针同时向前一位。
    // 否则k回退到next[k]位置（寻找更短的前后缀相等位置）。若两指针同时向前一位时 ，
    // 比较新的J和K位置字符是否相等，若相等则next[j]=next[k] ，不等 next[j]=k.
    private static int [] next(String b){
        int b_len = b.length();
        int j = 0, k = -1;
        int [] next = new int[b_len];
        next[0] = -1;
        while (j < b_len-1){
            if (k == -1 || b.charAt(j) == b.charAt(k)){
                k++;
                j++;
                if (b.charAt(j) != b.charAt(k)){
                    next[j] = k;
                }else {
                    next[j] = next[k];
                }
            }else {
                //回退到next[k]的位置
                k = next[k];
            }
        }
        return next;
    }
    //序列化字符串,前序遍历
    public static String convertTreeToStr(TreeNode head,StringBuilder builder){
        Stack<TreeNode> stack = new Stack<>();
        stack.push(head);
        while (!stack.isEmpty()){
            TreeNode poll = stack.pop();
            builder.append(poll.val + "!");

            if (poll.right != null){
                stack.push(poll.right);
            }else {
                builder.append("#!");
            }

            if (poll.left != null){
                stack.push(poll.left);
            }else {
                builder.append("#!");
            }
        }
        return builder.toString();
    }

    public static void main(String args[]){
        TreeNode root1 = new TreeNode(1);
        TreeNode left1 = new TreeNode(2);
        TreeNode right1 = new TreeNode(3);
        TreeNode left2 = new TreeNode(4);
        TreeNode right2 = new TreeNode(5);
        TreeNode left3 = new TreeNode(6);
        TreeNode right3 = new TreeNode(7);

        root1.left = left1;
        root1.right = right1;
        root1.left.left = left2;
        root1.left.right = right2;
        root1.right.left = left3;
        root1.right.right = right3;

        TreeNode root2 = new TreeNode(2);
        TreeNode left4 = new TreeNode(4);
        TreeNode right4 = new TreeNode(5);

        root2.left = left4;
        root2.right = right4;

        boolean res = chkIdentical(root1, root2);
        System.out.println("res is:" +res);
    }
}
