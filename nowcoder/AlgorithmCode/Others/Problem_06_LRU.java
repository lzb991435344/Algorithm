package Others;

import java.util.HashMap;

public class Problem_06_LRU {
    public static class Node<V>{
        //Key k;
        //V v;
        public V value;
        public Node<V> last;
        public Node<V> next;

        public Node(V value){
            this.value = value;
        }
    }

    public static class NodeDoubleLinkList<V>{
        private Node<V> head;
        private Node<V> tail;

        public NodeDoubleLinkList(){
            this.head = null;
            this.tail = null;
        }

        public void addNode(Node<V> newNode){
            if(newNode == null){
                return;
            }
            if(this.head == null){
                this.head = newNode;
                this.tail = newNode;
            }else{
                this.tail.next = newNode;
                newNode.last = this.tail;
                this.tail = newNode;
            }
        }

        public void moveNodeToTail(Node<V> node){
            if(this.tail == null){
                return;
            }
            if(this.head == node){
                this.head = node.next;//设置新的头结点
                this.head.last = null;//last指针设置为空
            }else{
                node.last.next = node.next;//node的last指向下一个节点
                node.next.last = node.last;//node的下一个节点的last指针指向node.last
            }

            node.last = this.tail;//尾节点赋值给node.last
            node.next = null;//node的next设置为空
            this.tail.next = node;
            this.tail = node;//node节点做为新的尾
        }

        public Node<V> removeHead(){
            if(head == null){
                return null;
            }
            Node<V> res = this.head;//指向原来的头结点
            if(this.head == this.tail){
                this.head = null;
                this.tail = null;
            }else{
                this.head = res.next;//头结点指向当前节点的下一个节点
                res.next = null;
                this.head.last = null;//前驱设置为null
            }
            return res;
        }
    }

    public static class MyCache<K, V>{
        private HashMap<K, Node<V>> keyNodeMap;//Node<V>记录内存地址
        private HashMap<Node<V>, K> nodeKeyMap;
        private NodeDoubleLinkList<V> nodeList;
        private int capacity;

        public MyCache(int capacity){
            if(capacity < 1){
                throw new RuntimeException("capicity error");
            }

            this.keyNodeMap = new HashMap<K, Node<V>>();
            this.nodeKeyMap = new HashMap<Node<V>, K>();
            this.nodeList = new NodeDoubleLinkList<V>();
            this.capacity = capacity;
        }

        public V get(K key){
            if(this.keyNodeMap.containsKey(key)){
                Node<V> res = this.keyNodeMap.get(key);
                this.nodeList.moveNodeToTail(res);//改变优先级
                return res.value;
            }
            return null;
        }

        public void set(K key, V value){
            if(this.keyNodeMap.containsKey(key)){
                Node<V> node = this.keyNodeMap.get(key);
                node.value = value;
                this.nodeList.moveNodeToTail(node);
            }else{
                Node<V> newNode = new Node<V>(value);
                this.keyNodeMap.put(key,newNode);
                this.nodeKeyMap.put(newNode, key);
                this.nodeList.addNode(newNode);
                if(this.keyNodeMap.size() == this.capacity + 1){
                    this.removeMostUnusedCache();
                }
            }
        }

        private void removeMostUnusedCache(){
            Node<V> removeNode = this.nodeList.removeHead();
            K removeKey = this.nodeKeyMap.get(removeNode);
            this.keyNodeMap.remove(removeNode);
            this.nodeKeyMap.remove(removeKey);
        }
    }

    public static void main(String[] args){

    }
}
