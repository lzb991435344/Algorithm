package String;
/**
 * 对于两个字符串A和B，如果A和B中出现的字符种类相同且每种字符出现的次数相同，则A和B互为变形词，
 * 请设计一个高效算法，检查两给定串是否互为变形词。给定两个字符串A和B及他们的长度，请返回一个bool值，
 * 代表他们是否互为变形词。
 * 测试样例：
 * "abc",3,"bca",3
 * 返回：true*/
public class Problem_02_ChkTransform {
    public static  boolean chkTransform(String A, int lena, String B, int lenb) {
        //长度不相等 ，直接返回false
        if (A == null||B == null||lena != lenb){
            return false;
        }
        //初始化数组，全部为0 数组用来计算字符出现的次数
        int [] map = new int[256];
        //字符串A出现的字符，在相应的ascii码位置上加1
        for (int i = 0; i < A.length(); i++){
            map[A.charAt(i)]++;
        }
        //字符串B出现的字符，在相应的位置减1，若最终都是0，则true 有一个不是就为false
        for (int i = 0; i < B.length(); i++){
            if (map[B.charAt(i)]-- == 0){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        boolean res = false;
        String str1 = "ab3g";
        int len1 = str1.length();

        String str2 = "a3bg";
        int len2 = str2.length();
        res = chkTransform(str1, len1, str2, len2);
        System.out.println("res is:" + res);
    }
}
