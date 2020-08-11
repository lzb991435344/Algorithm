package Recursion;

public class Problem_06_PrintAllSubString {
    //字符数组
    //当前位置
    //已经形成的字符串
    public static void printAllSubString(char[] str, int i, String res){
        if(i == str.length){
            System.out.println("res is:" + res);
            return;
        }
        printAllSubString(str, i + 1, res);//不要当前字符
        printAllSubString(str, i + 1, res + String.valueOf(str[i]));//要当前字符
    }


    //打印字符的全排列--实现

    //打印字符的全排列，要求不要出现重复的排列

    public static void main(String[] args){
        String str = "abc";
        printAllSubString(str.toCharArray(), 0, "");
    }
}
