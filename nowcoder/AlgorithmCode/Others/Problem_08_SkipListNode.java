package Others;

import java.util.ArrayList;
import java.util.Iterator;

public class Problem_08_SkipListNode {

    public static class SkipListNode{
        public Integer value;
        //node[0]第一层上下一个节点是...
        public ArrayList<SkipListNode> nextNodes;

        public SkipListNode(Integer value){
            this.value = value;
            nextNodes = new ArrayList<>();
        }
    }

    public static abstract class SkipListIterator implements Iterator<Integer>{

        SkipList list;
        SkipListNode current;

        public boolean hasNext() {
            return false;
        }
    }

    public static class SkipList{
        private SkipListNode head; //巨小
        private int maxLevel;//所有数据最大的层数
        private int size;//加进多少个key
        private static final double PROBABILY = 0.5;//以0.5概率产生0，剩下产生1

        public SkipList(){
            size = 0;
            maxLevel = 0;
            head = new SkipListNode(null);
            head.nextNodes.add(null);
        }

        public SkipListNode getHead(){
            return head;
        }

        public void add(Integer newValue){
            if(!contains(newValue)){
                size++;
                int level = 0;

                // 小于0.5加层
                while(Math.random() < PROBABILY){
                    level++;
                }

                while(level > maxLevel){
                    //扩充list
                    head.nextNodes.add(null);
                    maxLevel++;
                }

                SkipListNode newNode = new SkipListNode(newValue);
                SkipListNode cur = head;//从头开始找

                do{
                    cur = findNext(newValue, cur, level);
                    newNode.nextNodes.add(0, cur.nextNodes.get(level));
                    cur.nextNodes.set(level, newNode);
                }while(level-- > 0);

            }
        }

        private SkipListNode findNext(Integer e, SkipListNode cur, int level){
            //当前层的下一个节点
            SkipListNode next = cur.nextNodes.get(level);

            while(next != null){
                Integer value = next.value;
                if(lessThan(e, value)){
                    break;
                }
                //往下走
                cur = next;
                next = cur.nextNodes.get(level);
            }
            return cur;
        }

        public int size(){
            return size;
        }

        public boolean lessThan(Integer e, Integer a){

            return false;
        }

        public boolean equalTo(Integer value, Integer value2 ){
            return false;
        }

        public SkipListNode find(Integer e){
            return find(e, head, maxLevel);
        }
        public SkipListNode find(Integer e, SkipListNode cur, int level) {
            return cur;
        }

        public boolean contains(Integer value){
            SkipListNode node = find(value);
            return node != null && node.value != null && equalTo(node.value, value);
        }

        public void delete(Integer deleteValue){
            if(contains(deleteValue)){
                SkipListNode deleteNode = find(deleteValue);
                size--;
                int level = maxLevel;
                SkipListNode cur = head;
                do{
                    cur = findNext(deleteNode.value, cur, level);
                    if(deleteNode.nextNodes.size() > level){
                        cur.nextNodes.set(level, deleteNode.nextNodes.get(level));
                    }
                }while(level-- > 0);
            }
        }
    }

    public static void main(String[] args){

    }

}
/**
public class Code_02_SkipList {

    public static class SkipListNode {
        public Integer value;
        public ArrayList<SkipListNode> nextNodes;

        public SkipListNode(Integer value) {
            this.value = value;
            nextNodes = new ArrayList<SkipListNode>();
        }
    }

    public static class SkipListIterator implements Iterator<Integer> {
        SkipList list;
        SkipListNode current;

        public SkipListIterator(SkipList list) {
            this.list = list;
            this.current = list.getHead();
        }

        public boolean hasNext() {
            return current.nextNodes.get(0) != null;
        }

        public Integer next() {
            current = current.nextNodes.get(0);
            return current.value;
        }
    }

    public static class SkipList {
        private SkipListNode head;
        private int maxLevel;
        private int size;
        private static final double PROBABILITY = 0.5;

        public SkipList() {
            size = 0;
            maxLevel = 0;
            head = new SkipListNode(null);
            head.nextNodes.add(null);
        }

        public SkipListNode getHead() {
            return head;
        }

        public void add(Integer newValue) {
            if (!contains(newValue)) {
                size++;
                int level = 0;
                while (Math.random() < PROBABILITY) {
                    level++;
                }
                while (level > maxLevel) {
                    head.nextNodes.add(null);
                    maxLevel++;
                }
                SkipListNode newNode = new SkipListNode(newValue);
                SkipListNode current = head;
                do {
                    current = findNext(newValue, current, level);
                    newNode.nextNodes.add(0, current.nextNodes.get(level));
                    current.nextNodes.set(level, newNode);
                } while (level-- > 0);
            }
        }

        public void delete(Integer deleteValue) {
            if (contains(deleteValue)) {
                SkipListNode deleteNode = find(deleteValue);
                size--;
                int level = maxLevel;
                SkipListNode current = head;
                do {
                    current = findNext(deleteNode.value, current, level);
                    if (deleteNode.nextNodes.size() > level) {
                        current.nextNodes.set(level, deleteNode.nextNodes.get(level));
                    }
                } while (level-- > 0);
            }
        }

        // Returns the skiplist node with greatest value <= e
        private SkipListNode find(Integer e) {
            return find(e, head, maxLevel);
        }

        // Returns the skiplist node with greatest value <= e
        // Starts at node start and level
        private SkipListNode find(Integer e, SkipListNode current, int level) {
            do {
                current = findNext(e, current, level);
            } while (level-- > 0);
            return current;
        }

        // Returns the node at a given level with highest value less than e
        private SkipListNode findNext(Integer e, SkipListNode current, int level) {
            SkipListNode next = current.nextNodes.get(level);
            while (next != null) {
                Integer value = next.value;
                if (lessThan(e, value)) { // e < value
                    break;
                }
                current = next;
                next = current.nextNodes.get(level);
            }
            return current;
        }

        public int size() {
            return size;
        }

        public boolean contains(Integer value) {
            SkipListNode node = find(value);
            return node != null && node.value != null && equalTo(node.value, value);
        }

        public Iterator<Integer> iterator() {
            return new SkipListIterator(this);
        }



        private boolean lessThan(Integer a, Integer b) {
            return a.compareTo(b) < 0;
        }

        private boolean equalTo(Integer a, Integer b) {
            return a.compareTo(b) == 0;
        }

    }

    public static void main(String[] args) {

    }

}*/