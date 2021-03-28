package Greedy;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;


//拼接字符数组中的字符串，找出字典序中最小的
public class Problem_01_LowestLexicography {
    public static class MyComparator implements Comparator<String>{

        //该题比较策略就是贪心策略
        //证明排序策略是有传递性的
        public int compare(String a, String b) {
            return (a + b).compareTo(b + a);
        }

        public static  String lowestString(String[] strs){
            if(strs == null || strs.length == 0){
                return "";
            }
            Arrays.sort(strs, new MyComparator());
            String res = "";

            for(int i = 0; i < strs.length; ++i){
                res += strs[i];
            }
            return res;
        }
    }

    public static void main(String[] args){

    }
}
