package String;

//字符串移位：将 helloworld 右移两位为 ldhellowor.
public class Problem_05_StringTranslation {
    public static String stringTranslation(String A, int n, int len) {
        String result = "";
        //在0和len-1之间反转
        // result = reverseString(A, 0, len - 1);
        result = reverseString(A, 0, len - 1 );
        //在len和n-1之间反转
        result = reverseString(result, 0,  n - 1);
        // result = reverseString(result, 0, n );
        //整体字符串反转
        result = reverseString(result, n, len - 1 );
        return result;
    }
    //字符串反转函数 在begin 和 end之间进行反转
    public static String reverseString(String str, int begin, int end) {

        char[] chars = str.toCharArray();
        while (begin < end) {
            char temp = chars[begin];
            chars[begin] = chars[end];
            chars[end] = temp;
            end--;
            begin++;
        }
        return String.valueOf(chars);
    }
    public static void main(String args[]){
        String str = "helloworld";
        int n = 2;
        int len = str.length();
        String res = " ";
        res = stringTranslation(str, n, len);
        System.out.println("The res is:" + res);
    }
}
