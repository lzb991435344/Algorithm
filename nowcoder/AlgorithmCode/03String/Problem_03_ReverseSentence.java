package String;
/**
 * 句子逆序，“i love you”处理后变成 “you love i”
 * */
public class Problem_03_ReverseSentence {
    public static String reverseSentence(String A, int n) {
        StringBuilder bulider = new StringBuilder();
        //切分字符串
        String[] split = A.split(" ");

        //将字符串倒序拼接
        for (int i = split.length - 1; i >= 0; i--) {
            bulider.append(split[i] + " ");
        }
        return bulider.substring(0, bulider.length() - 1).toString();
    }
    public static void main(String args[]) {
        String str1 = "i love you";
        int len = str1.length();

        String res = null;
        res = reverseSentence(str1, len);
        System.out.println("The res is:" + res);
    }
}
