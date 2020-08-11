package String;

import java.util.HashMap;
import java.util.Map;

/**
 * 最长无重复子串
 *    对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。
 * 给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，
 * 且长度小于等于500。
 * 测试样例：
 * "aabcb",5
 * 返回：3
 * */
public class Problem_08_LongestSubstring {
    public static int longestSubstring(String A, int n) {
        //哈希表存储 字符a上次出现的位置i
        Map<Character, Integer> map = new HashMap<>();

        //字符i的前一个字符i-1的上次出现的位置
        int pre_index = -1;
        int temp = 0;

        //最长无重复长度
        int res = 0;

        //初始化第一个字符上次出现的位置就是0
        map.put(A.charAt(0), 0);
        for (int i = 1; i < n; i++) {
            char ch = A.charAt(i);
            int cur;

            //在哈希表中寻找上次出现的位置 找不到则为-1
            if (map.get(ch) != null) {
                cur = map.get(ch);
            } else {
                cur = -1;
            }

            //比较当前字符i和i-1字符的上次的出现的位置，
            //谁出现的位置更靠近i就用它计算长度.因为如果i-1字符上次出现的位置比i大，
            //那么说明i字符没到上次它出现的位置就会因为i-1字符重复而失败(否则i-1字符上次出现的位置就不会比i的大)
            //反之，则说明i字符可以到上次出现的字符的位置，在这中间i-1字符保证不会发生重复
            //map = {(a,1),(b,6),(c,3),(d,4),(e,5)}

            if (pre_index > cur) {
                temp = i - pre_index;
            } else {
                temp = i - cur;

                //用了新的位置计算，所以更新pre_index
                pre_index = cur;
            }

            //更新字符ch上次出现的位置
            map.put(ch, i);
            res = Math.max(res, temp);
        }
        return res;
    }
    public static void main(String args[]) {
        String str = "aabcdeb";
        int len = str.length();
        int res = longestSubstring(str, len);

        System.out.println("The res is:" + res);
    }
}
