package String;

import java.util.Arrays;
import java.util.Comparator;

/**
 * 拼接最小的字典序
 *    对于一个给定的字符串数组，请找到一种拼接顺序，使所有小字符串拼接成的大字符串是
 *   所有可能的拼接中字典序最小的。
 * 给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。
 *
 * 测试样例：
 * [“abc”,”de”],2
 * “abcde”
 * 比较A+B和B+A的大小
 * */
public class Problem_04_FindSmallest {
    public static String findSmallest(String[] strs, int n) {
        if (strs == null || n == 0){
            return "";
        }
        Arrays.sort(strs, new Mycomparator());//排序

        //字符缓冲器进行字符串拼接
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < n; i++){
            builder.append(strs[i]);
        }
        return builder.toString();
    }
    //利用比较器进行自定义比较
    private static class Mycomparator implements Comparator<String> {
        @Override
        public int compare(String o1, String o2) {
            return (o1 + o2).compareTo(o2 + o1);
        }
    }
    public static  void main(String args[]){
        String[] str = {"abc","de"};
        int len = 2;
        String res = null;

        res =  findSmallest(str, len);
        System.out.println("The res is:" + res);
    }
}
