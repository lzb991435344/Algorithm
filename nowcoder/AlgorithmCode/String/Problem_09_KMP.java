package String;

public class Problem_09_KMP {

    public static int getIndexOf(String s, String m) {
        if (s == null || m == null || m.length() < 1 || s.length() < m.length()) {
            return -1;
        }
        char[] ss = s.toCharArray();
        char[] ms = m.toCharArray();
        int si = 0;
        int mi = 0;
        int[] next = getNextArray(ms);
        while (si < ss.length && mi < ms.length) {
            if (ss[si] == ms[mi]) {//值相等
                si++;
                mi++;
            } else if (next[mi] == -1) {//不相等且0位置的字符为-1
                si++;//str2跳到开头但是配不上
            } else { // next[mi] != -1
                mi = next[mi];//可以继续匹配
            }
        }
        //返回str2在str1中的起始位置
        return mi == ms.length ? si - mi : -1;
    }

    public static int[] getNextArray(char[] ms) {
        if (ms.length == 1) {
            return new int[] { -1 };
        }
        int[] next = new int[ms.length];
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while (pos < next.length) {
            if (ms[pos - 1] == ms[cn]) {//字符相等
                next[pos++] = ++cn;//长度为cn + 1
            } else if (cn > 0) {//第一行没中，字符不等
                cn = next[cn]; //还可以往前跳位置，next数组值为目标位置
            } else {
                next[pos++] = 0;//无法跳
            }
        }
        return next;
    }

    public static void main(String[] args) {
        String str = "abcabcababaccc";
        String match = "ababa";
        System.out.println(getIndexOf(str, match));
    }
}
