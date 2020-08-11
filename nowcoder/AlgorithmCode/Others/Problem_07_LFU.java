package Others;

import java.util.HashMap;

//实现LFU的set和get方法
//操作频度低的换出
public class Problem_07_LFU {
    public static class Node{
        public Integer key;
        public Integer value;
        public Integer times;

        public Node up;
        public Node down;

        public Node(int key, int value, int times){
            this.key = key;
            this.value = value;
            this.times = times;
        }
    }

    public static class LFUCache{
        //内部节点
        //nodelist1(Node head, Node tail, Nodelist last, Nodelist next)   nodelist2
        public static class NodeList{
            public Node head;
            public Node tail;

            public NodeList last;
            public NodeList next;

            public NodeList(Node node){//不接受空参数
                head = node;
                tail = node;
            }

            public void  addNodeFromHead(Node newNode){
                newNode.down = head;
                head.up = newNode;
                head = newNode;
            }

            public boolean isEmpty(){
                return head == null;
            }

            public void deleteNode(Node node){
                if(head == tail){
                    head = null;
                    tail = null;
                }else{
                    if(node == head){
                        head = node.down;
                        head.up = null;
                    }else if(node == tail){
                        tail = node.up;
                        tail.down = null;
                    }else{//中间节点
                        node.up.down = node.down;
                        node.down.up = node.up;
                    }
                }

                node.up = null;
                node.down = null;
            }
        }

        //外部节点
        private int capacity;
        private int size;
        private HashMap<Integer, Node> records;//key---->node
        private HashMap<Node, NodeList> heads;//任何一个node都找到nodelist
        private NodeList headList;//大结构中的nodelist

        public LFUCache(int capacity){
            this.capacity = capacity;
            this.size = 0;//实际数量
            this.records = new HashMap<>();
            this.heads = new HashMap<>();
            headList = null;
        }

        public void set(int key, int value){
            if(records.containsKey(key)){
                Node node = records.get(key);//拿到内存地址，设置结构
                node.value = value;
                node.times++;
                NodeList curNodeList = heads.get(node);//大链表结构
                move(node, curNodeList);//移动位置
            }else{//不包含key
                if(size == capacity){//找到应该删除的节点
                    Node node = headList.tail;
                    headList.deleteNode(node);//大结构的节点
                    modifyHeadList(headList);//查看是否需要换头节点
                    records.remove(node.key);//每个key对应的node
                    heads.remove(node);//node 对应的nodelist
                    size--;
                }
                Node nodes = new Node(key, value , 1);
                if(headList == null){//添加到头结点
                    headList.addNodeFromHead(nodes);
                }else{//频度比较
                    //头结点的频度
                    if(headList.head.times.equals(nodes.times)){
                        headList.addNodeFromHead(nodes);
                    }else{//新的newList
                        NodeList newList = new NodeList(nodes);
                        newList.next = headList;
                        headList.last = newList;
                        headList = newList;
                    }
                }
                //修改record和heads
                records.put(key, nodes);
                heads.put(nodes, headList);
                size++;

            }
        }

        public void move(Node node, NodeList oldNodeList){
             oldNodeList.deleteNode(node);
             //oldlist的上一个节点
            //可能老的链表都没有了
             NodeList preList =  modifyHeadList(oldNodeList)? oldNodeList.last : oldNodeList;
             NodeList nextList = oldNodeList.next;
             if(nextList == null){
                 NodeList newList = new NodeList(node);
                 if(preList != null){
                     preList.next = newList;
                 }
                 newList.last = preList;
                 if(headList == null){
                     headList = newList;
                 }
                 heads.put(node, newList);
             }else{
                 if(nextList.head.times.equals(node.times)){
                     nextList.addNodeFromHead(node);
                     heads.put(node, nextList);
                 }else{
                     //新建节点
                     NodeList newList = new NodeList(node);
                     if(preList != null){
                         preList.next = newList;
                     }
                     //更大times,新加
                     newList.last = preList;
                     newList.next = nextList;
                     nextList.last = newList;

                     //头结点
                     if(headList == nextList){
                         headList = newList;
                     }
                     heads.put(node, newList);
                 }
             }
        }



        public int get(int key){
            if(!records.containsKey(key)){
                return -1;
            }

            Node node = records.get(key);
            node.times++;
            //先找到nodelist的头结点
            NodeList curNodeList = heads.get(key);
            move(node, curNodeList);//移动
            return node.value;
        }

        //是否删掉该头结点，换头操作
        public boolean modifyHeadList(NodeList nodeList){
            if(nodeList.isEmpty()){
                if(headList == nodeList){//新节点等于NodeList的头结点
                    headList = nodeList.next;//新头部等于老头部的下一个
                    if(headList != null){//新头无数据
                        headList.last = null;
                    }
                }else{//非头结点,删除频度
                    nodeList.last.next = nodeList.next;//删除中间空节点，连接到新节点
                    if(nodeList != null){
                        nodeList.next.last = nodeList.last;
                    }
                }
                return true;
            }
            return false;
        }
    }
}
