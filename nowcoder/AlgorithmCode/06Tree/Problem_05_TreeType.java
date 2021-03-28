package Tree;

import java.util.LinkedList;
import java.util.Queue;

public class Problem_05_TreeType {
    public static class Node {
        public int value;
        public Node left;
        public Node right;

        public Node(int data) {
            this.value = data;
        }
    }

    //树处理问题的套路--树型dp,在树上做动态规划
    public static class ReturnData{
        public boolean isBalance;
        public int heigh;
        public ReturnData(boolean isBalance, int heigh){
            this.isBalance = isBalance;
            this.heigh = heigh;
        }
    }

    public static boolean isBalanceTree(Node head){
        return process(head).isBalance;
    }

    public static ReturnData process(Node head){
        if(head == null)
            return new ReturnData(true, 0);

        ReturnData leftData = process(head.left);
        if(!leftData.isBalance){
            return new ReturnData(false, 0);
        }

        ReturnData rightData = process(head.right);
        if(!rightData.isBalance){
            return new ReturnData(false, 0);
        }

        if(Math.abs(leftData.heigh - rightData.heigh) > 1){
            return new ReturnData(false ,0);
        }

        return new ReturnData(true, Math.max(leftData.heigh, rightData.heigh) + 1);
    }




    //平衡二叉树判断
    //左右子树的高度差不超过1 <= 1
    public static boolean isBalance(Node head) {
        return getHeight(head, 0) != -1;
    }

    public static int getHeight(Node head, int level) {
        if (head == null) {
            return level;
        }
        int lh = getHeight(head.left, level + 1);
        int rh = getHeight(head.right, level + 1);

        //lh和rh的返回值为-1，将不是平衡树的信息转换成你一个整型的返回值
        if (lh == -1 || rh == -1 || Math.abs(lh - rh) > 1) {
            return -1;
        }
        return Math.max(lh, rh);
    }

    //搜索二叉树，头结点，左子树比它小，右子树比它大
    //中序遍历依次升序，不含重复节点
    //molis遍历判断
    public static boolean isBST(Node head) {
        if (head == null) {
            return true;
        }
        boolean res = true;
        Node pre = null;
        Node cur1 = head;
        Node cur2 = null;
        while (cur1 != null) {
            cur2 = cur1.left;
            if (cur2 != null) {
                while (cur2.right != null && cur2.right != cur1) {
                    cur2 = cur2.right;
                }
                if (cur2.right == null) {
                    cur2.right = cur1;
                    cur1 = cur1.left;
                    continue;
                } else {
                    cur2.right = null;
                }
            }
            if (pre != null && pre.value > cur1.value) {
                res = false;
            }
            pre = cur1;
            cur1 = cur1.right;
        }
        return res;
    }


    //基于非递归和递归的套路修改作为判断 --作业

    //完全二叉树的判断
    public static boolean isCBT(Node head) {
        if (head == null) {
            return true;
        }
        Queue<Node> queue = new LinkedList<Node>();
        boolean leaf = false;//是否是叶子节点
        Node l = null;
        Node r = null;
        queue.offer(head);
        while (!queue.isEmpty()) {
            head = queue.poll();
            l = head.left;
            r = head.right;

            //左右孩子都是叶子节点
            if ((leaf && (l != null || r != null)) ||
                    (l == null && r != null)) {//右孩子不为空，左孩子为空
                return false;
            }
            //先加左
            if (l != null) {
                queue.offer(l);
            }

            //再加右
            if (r != null) {
                queue.offer(r);
            } else { //l == null || r == null
                leaf = true;
            }
        }
        return true;
    }

    // for test -- print tree
    public static void printTree(Node head) {
        System.out.println("Binary Tree:");
        printInOrder(head, 0, "H", 17);
        System.out.println();
    }

    public static void printInOrder(Node head, int height, String to, int len) {
        if (head == null) {
            return;
        }
        printInOrder(head.right, height + 1, "v", len);
        String val = to + head.value + to;
        int lenM = val.length();
        int lenL = (len - lenM) / 2;
        int lenR = len - lenM - lenL;
        val = getSpace(lenL) + val + getSpace(lenR);
        System.out.println(getSpace(height * len) + val);
        printInOrder(head.left, height + 1, "^", len);
    }

    public static String getSpace(int num) {
        String space = " ";
        StringBuffer buf = new StringBuffer("");
        for (int i = 0; i < num; i++) {
            buf.append(space);
        }
        return buf.toString();
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        head.left = new Node(2);
        head.right = new Node(6);
        head.left.left = new Node(1);
        head.left.right = new Node(3);
        head.right.left = new Node(5);

        printTree(head);
        System.out.println(isBST(head));
        System.out.println(isCBT(head));
    }

}
