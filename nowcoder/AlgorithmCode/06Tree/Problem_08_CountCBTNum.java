package Tree;

public class Problem_08_CountCBTNum {
    public static class Node {
        public int value;
        public Node left;
        public Node right;

        public Node(int data) {
            this.value = data;
        }
    }

    public static int nodeNum(Node head){
        if(head == null){
            return 0;
        }
        return bs(head, 1, mostLeftLevel(head, 1));
    }

    //node 为当前节点，level节点在第几层，r为树的深度
    //整棵树的节点个数
    public static int bs(Node node, int level, int h){
        if(level == h){//最后一层
            return 1;
        }
        //右子树的左子树最高得高度
        if((mostLeftLevel(node.right, level + 1)) == h){//左子树满
            //2 ^ (h - level) ,计算以当前节点为头的右子树
            return 1 << (h - level)  + bs(node.right, level + 1, h);
        }else{
            //右子树满,递归左子树
            return 1 <<(h - level - 1) + bs(node.left, level +  1, h);
        }

    }
    public static int mostLeftLevel(Node node, int level){
        while(node != null){
            level++;
            node = node.left;
        }
        return level - 1;
    }
    public static void main(String[] args){

    }
}
