package String;

public class Problem_10_Manacher {

    public static char[] manacherString(String str){
        char[] charArr = str.toCharArray();
        char[] res = new char[str.length() *2 + 1];

        int index = 0;
        for(int i = 0; i != res.length; ++i){
            res[i] = (i & 1) == 0 ? '#' : charArr[index++];
        }
        return res;
    }

    public static int maxLcpsLength(String str){
        if(str == null){
            return 0;
        }

        char[] charArr = manacherString(str);
        int[] pArr = new int[charArr.length];//回文半径数组

        int c = -1;
        int r = -1;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < charArr.length; ++i){//找每一个i位置
            //i'的回文到r的距离，小的成为回文区间
            //2*c - i 回文半径
            //r - i 右边界
            //r > i i在r内
            //情况1，情况2
            pArr[i] = r > i ? Math.min(pArr[2*c - i], r - i) : 1;

            //有满足的区域之后还往外扩展，只有情况3需要外扩
            while(i + pArr[i] < charArr.length && i - pArr[i] > -1){
                if(charArr[i + pArr[i]]  == charArr[i - pArr[i]]){//字符相等
                    pArr[i]++;//回文半径++
                }else{//不等，结束外扩
                    break;
                }
            }
            //情况3
            if(i + pArr[i] > r){
                r = i + pArr[i];
                c = i;
            }
            max = Math.max(max,pArr[i]);
        }
        return max - 1;
    }

    public static void main(String[] args){
        String str = "123321";

        System.out.println(maxLcpsLength(str));
    }

}
