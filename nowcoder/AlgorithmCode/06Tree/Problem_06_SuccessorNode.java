package Tree;

//找一个节点的后继节点
public class Problem_06_SuccessorNode {
    public static class Node {
        public int value;
        public Node left;
        public Node right;
        public Node parent;

        public Node(int data) {
            this.value = data;
        }
    }

    public static Node getSuccessorNode(Node node){
        if(node == null){
            return null;
        }

        if(node.right != null){
            return getLeftMost(node.right);
        }else{
            Node parent = node.parent;//先找到node的parent节点
            //终止条件，(1)当前的node节点是node parent的左孩子
            //(2)parent为空
            while(parent != null && parent.left != node){
                node = parent;//node向上找，变成parent
                parent = node.parent;//parent指针也向上，直到为空
            }
        }
        return node;
    }
    public static Node  getLeftMost(Node node){ //node为树的头部
        if(node == null){
            return null;//右孩子的最左节点为空，返回自身
        }
        //循环找到
        while(node.left != null){
            node = node.left;
        }
        return node;
    }

    //前驱代码的实现
    //(1)有左子树，左子树最右
    //(2)无左子树，往上找 父节点是右孩子停止
    public static Node getPreNode(Node node){
        if(node == null){
            return null;
        }

        return node;
    }
    public static void main(String[] args){

    }
}
