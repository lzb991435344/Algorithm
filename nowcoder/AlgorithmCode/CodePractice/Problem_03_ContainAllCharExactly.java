package CodePractice;

import java.util.Arrays;

public class Problem_03_ContainAllCharExactly{

    //O(N^3 * logN)
    public static int containExactly1(String s, String a){
        if(s == null || a == null || s.length() < a.length()){
            return -1;
        }

        char[] aim = a.toCharArray();
        Arrays.sort(aim);

        //排序之后组成的字符串
        String aimSort = String.valueOf(aim);

        //枚举所有的子串
        //0-0, 0-1.....0-N-1
        //1-1,,,
        for(int l = 0; l < s.length(); l++){//枚举每一个字符串的开头

            //
            for(int r = l ; r < s.length(); r++){
                //substring 左闭右开
                char[] cur = s.substring(l,  r + 1).toCharArray();
                Arrays.sort(cur);
                String curSort = String.valueOf(cur);
                if(curSort.equals(aimSort)){
                    return l;
                }
            }
        }
        return -1;
    }


    //O(M*N)
    //检查长度一样的子串即可
    public static int containExactly2(String s, String a){
        if(s == null || a == null || s.length() < a.length()){
            return -1;
        }

        char[] str = s.toCharArray();
        char[] aim = a.toCharArray();
        //枚举str中长度为m的所有可能的开头
        //尾部长度 str.length - aim.length
        for(int l = 0; l < str.length - aim.length; l++){
            if(isCountEqual(str, l, aim)){
                return l;
            }
        }
        return -1;
    }

    //假设aim的长度为m
    //str[l...m个字母]
    public static boolean isCountEqual(char[] str, int l, char[] aim){
        int[] count = new int[256];
        for(int i = 0; i < aim.length; i++){
            count[aim[i]]++;
        }

        for(int i = 0; i < aim.length; i++){
            if(count[str[l + i]]-- == 0){
                return false;
            }
        }
        return true;
    }


    public static int containExactly3(String s, String a){
        if(s == null || a == null || s.length() < a.length()){
            return -1;
        }

        char[] aim = a.toCharArray();
        int[] count = new int[256];

        for(int i = 0; i < aim.length; i++){
            count[aim[i]]++;
        }

        int m = aim.length;
        char[] str = s.toCharArray();
        int inValidTimes = 0;
        int r = 0;

        //窗口有m字符
        for(; r < m; r++){
            if(count[str[r]]-- <= 0){//说明多给了字符
                inValidTimes++;
            }
        }
        //第一次形成了长度为m的窗口
        for(; r < str.length; r++){
            if(inValidTimes == 0){//无效点数为0
                return r - m;
            }
            //[0...M-1]
            //[1...M]
            //[2...M]
            if(count[str[r]]-- <= 0){
                inValidTimes++;
            }

            //拿回，无效点数 + 1
            if(count[str[r - m]]++ < 0){
                inValidTimes--;
            }
        }
        return inValidTimes == 0? r - m : 1;
    }
    public static void main(String[] args){

    }
}
