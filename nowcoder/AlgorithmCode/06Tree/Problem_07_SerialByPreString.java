package Tree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Problem_07_SerialByPreString {
    public static class Node {
        public int value;
        public Node left;
        public Node right;

        public Node(int data) {
            this.value = data;
        }
    }

    public static String serialByPreRecursion(Node head){
        if(head == null){
            return "#!";
        }

        String res = head.value + "!";
        serialByPreRecursion(head.left);
        serialByPreRecursion(head.right);
        return res;
    }

    public static String serialByPreUnRecursion(Node head){
        if (head == null) {
            return "#!";
        }
        Stack<Node> stack = new Stack<Node>();
        stack.push(head);
        StringBuilder builder = new StringBuilder();

        while (!stack.isEmpty()) {
           Node cur = stack.peek(); //取出栈顶元素
            stack.pop();
            if (cur == null) {
                builder.append("#!");
                continue;//跳出当前循环
            } else {
                builder.append(cur.value);
                builder.append("!");
            }
            stack.push(cur.right);
            stack.push(cur.left);
        }

        return builder.toString();
    }

    //反序列化
    public static Node reconByPreString(String preString){
        String[] values = preString.split("!");//按！进行分割
        Queue<String> queue = new LinkedList<String>();
        for(int i = 0; i != values.length; ++i){
            queue.offer(values[i]);//依次弹出
        }
        return reconPreOrder(queue);
    }
    public static Node reconPreOrder(Queue<String> queue){
        String value = queue.poll();//取队头
        if(value.equals("#")){
            return null;
        }

        Node head = new Node(Integer.valueOf(value));
        head.left = reconPreOrder(queue);
        head.right = reconPreOrder(queue);
        return head;
    }

    //按层序列化
    public static String serialByLevel(Node head){
        if(head == null){
            return "#!";
        }
        String res = head.value + "!";
        Queue<Node> queue = new LinkedList<Node>();
        queue.offer(head);//添加头结点

        while(!queue.isEmpty()){
            head = queue.poll();

            if(head.left != null){
                res += head.value + "!";
                queue.offer(head.left);
            }else{
                res += "#!";
            }

            if(head.right != null){
                res += head.value + "!";
                queue.offer(head.right);
            }else{
                res += "#!";
            }
        }
        return res;
    }

    //按层反序列化
    public static Node reconByLevelString(String preString){
        String[] values = preString.split("!");
        int index = 0;

        Node head = generateNodeByString(values[index++]);
        Queue<Node> queue = new LinkedList<Node>();
        if(head != null){
            queue.offer(head);
        }

        Node node = null;
        while(!queue.isEmpty()){
            node = queue.poll();
            node.left = generateNodeByString(values[index++]);
            node.right = generateNodeByString(values[index++]);

            if(node.left != null){
                queue.offer(node.left);
            }

            if(node.right != null){
                queue.offer(node.right);
            }
        }
        return head;
    }

    public static Node generateNodeByString(String value){
        if(value.equals("#")){
            return null;
        }
        return new Node(Integer.valueOf(value));
    }

    public static void main(String[] args){

    }
}
