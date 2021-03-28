package Tree;

import java.util.HashMap;

public class Problem_10_TrieTree {
    public static class TrieNode{
        public  int path;//该节点到达过几次
        public int end;//有多少个字符串以这个结尾
        public TrieNode[] nexts;//路径
        //public HashMap<Character, TrieNode> map;


       public TrieNode(){
            path = 0;
            end = 0;
            nexts = new TrieNode[26];//a - z
        }
    }

    public static class Trie{
        private TrieNode root;//头结点
        public Trie(){
            root = new TrieNode();
        }

        public void insert(String str){
            if(str == null){
                return;
            }
            char[] chs = str.toCharArray();
            TrieNode node = root;
            int index = 0;
            for(int i = 0 ; i < chs.length; ++i){
                index = chs[i] - 'a';//abc 0 1 2
                if(node.nexts[index] == null){//无路，建立
                    node.nexts[index] = new TrieNode();
                }
                //有路，往下走
                node = node.nexts[index];
                node.path++;//下一个结点
            }
            //最后结点的end + 1
            node.end++;
        }

        public void delete(String str){
            if(search(str) != 0){
                char[] chs = str.toCharArray();
                TrieNode node = root;
                int index = 0;
                for(int i = 0; i < chs.length; ++i){
                   index = chs[i] - 'a';

                   //下面若节点的值为0，底下的节点变为空，设置为null
                   if(--node.nexts[index].path == 0){
                       node.nexts[index]  = null;
                   }
                   node = node.nexts[index];
                }
                node.end--;
            }
        }

        //以该字符串的为结尾的字符串是否存在，插入过多少次str
        public int search(String str){
            if(str == null){
                return 0;
            }

            char[] chs = str.toCharArray();
            TrieNode node = root;
            int index = 0;
            for(int i = 0; i < chs.length; ++i){
                index = chs[i] - 'a';
                //空说明不存在
                if(node.nexts[index] == null){
                    return 0;
                }
                //不为空继续下一个查询
                node = node.nexts[index];
            }
            return node.end;
        }

        public int prefitNumber(String pre){
            if(pre == null){
                return 0;
            }
            char[] chs = pre.toCharArray();
            TrieNode node = root;
            int index = 0;
            for(int i = 0; i < chs.length; ++i){
                index = chs[i] - 'a';
                if(node.nexts[index] == null){
                    return 0;
                }
                node = node.nexts[index];
            }
            return node.path;
        }
    }
    public static void main(String[] args){

    }

}
