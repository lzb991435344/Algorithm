package Others;

import java.util.HashMap;
import java.util.List;
import java.util.Stack;

public class Problem_05_UnionFind {

    public static class Node{

    }

    public static class UnionFindSet{
        public HashMap<Node, Node> fatherMap;//key--child   value--parent

        //某个节点所在的集合有几个节点，代表节点
        public HashMap<Node, Integer> sizeMap;//key--节点值     value--数量

        public UnionFindSet(){
            fatherMap = new HashMap<Node, Node>();
            sizeMap = new HashMap<Node, Integer>();
        }


        public void makeSets(List<Node> nodes){
            fatherMap.clear();
            sizeMap.clear();
            for(Node node:nodes){
                fatherMap.put(node, node);//自己组成的结合，父节点是自己
                sizeMap.put(node, 1);//代表节点，set中只有一个元素
            }
        }

        private Node findHead(Node node){
            Node father = fatherMap.get(node);

            if(father != node){
                //递归
                //将其中的节点直接连接代表节点
                father = findHead(father);
            }
            fatherMap.put(node, father);
            return father;
        }

        private Node findHead2(Node node){
            Node father = fatherMap.get(node);
            Stack<Node> stack = new Stack<Node>();

            Node cur = node;

            while(cur != father){
               stack.push(cur);
               cur = father;
               father = fatherMap.get(cur);
            }
            //此时头结点已经是最顶部的代表结点
            while(!stack.isEmpty()){
                fatherMap.put(stack.pop(), father);
            }
            return father;
        }

        public boolean isSameSet(Node a, Node b){
            return findHead(a) == findHead(b);
        }

        public void union(Node a, Node b){
            if(a == null || b == null){
                return ;
            }
            Node aFather = findHead(a);
            Node bFather = findHead(b);

            //不一样修改
            if(aFather != bFather){
                int aFsize = sizeMap.get(aFather);//集合的size
                int bFsize = sizeMap.get(bFather);

                if(aFsize <= bFsize){
                    //修改头结点
                    fatherMap.put(aFather, bFather);
                    sizeMap.put(bFather, aFsize + bFsize);
                } else{
                    fatherMap.put(bFather, aFather);
                    sizeMap.put(aFather, aFsize + bFsize);
                }
            }
        }
    }
    public static void main(String[] args){

    }
}
