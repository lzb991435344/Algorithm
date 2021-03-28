package String;

//用字符替换空格
public class Problem_07_ReplaceSpace {
    public static String replaceSpace(String iniString, int length) {
        int numOfblank = 0;// 空格数量

        // 计算空格数量
        for (int i = 0; i < length; i++) {
            if (iniString.charAt(i) == ' ') {
                numOfblank++;
            }
        }
        // 新的字符串长度
        int len = length + numOfblank * 2;

        // 开辟新的空间
        char str[] = new char[len];
        int k = len - 1;

        // 倒序赋值
        for (int i = length - 1; i >= 0; i--) {
            //string.charAt()取到字符串中的字符
            if (iniString.charAt(i) == ' ') {
                str[k--] = '0';
                str[k--] = '2';
                str[k--] = '%';
            } else {
                str[k--] = iniString.charAt(i);
            }
        }
        //String.valueOf() 返回指定数组中的字符串序列
        return String.valueOf(str);
    }

    public static void main(String args[]) {
        String str = "i love you ";
        String res = "";
        int len = str.length();
        res = replaceSpace(str, len);
        System.out.println("The res is:" + res);
    }
}
