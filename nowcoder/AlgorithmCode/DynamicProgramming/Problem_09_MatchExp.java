package DynamicProgramming;

public class Problem_09_MatchExp {

    public static boolean process(char[] str, char[] exp, int i, int j){
        if(j == exp.length){
            return i == str.length;
        }

        //j后面还有字符， 考察j + 1的情况
        if(j + 1 == exp.length || exp[j + 1] != '*'){
            return i != str.length && (str[i] == exp[j] || exp[j] == '.')
                    && process(str, exp,i + 1, j + 1);
            //i为最大长度无法匹配
            //i + 1, j + 1位置匹配上
        }

        //exp的j+1位置有字符，且为*
        //aaab
        //c*...
        while(i != str.length && (exp[j] == str[i] || exp[j] == '.')){
            //j + 2位置匹配，默认0个c
            //假设为0个a，第二行 (a*)......
            if(process(str, exp, i , j + 2)){
                return true;
            }
            //原来i的下一个位置，和j + 2开始匹配
            i ++;
        }
        return process(str, exp, i , j + 2);
    }

    //最后一排和倒数两列
    public static boolean[][] initDPMap(char[] s, char[] e){
        int slen = s.length;
        int elen = e.length;
        boolean[][] dp = new boolean[slen + 1][elen + 1];
        dp[slen + 1][elen + 1] = true;
        for(int j = elen - 2; j > -1; j--){
            if(e[j] != '*' && e[j + 1] == '*'){
                dp[slen][j] = true;
            }else{
                break;
            }
        }

        if(slen > 0 && elen > 0){
            if(e[elen - 1] == '.' || s[slen - 1] == e[elen - 1]){
                dp[slen - 1][ elen - 1] = true;
            }
        }

        return dp;
    }

    public static boolean isMatchDP(String str, String exp){
        if(str == null || exp == null){
            return false;
        }
        char[] s = str.toCharArray();
        char[] e = str.toCharArray();
        if(!isValid(s, e)){
            return false;
        }
        boolean[][] dp  = initDPMap(s,e);
        for(int i = s.length - 1; i > -1; i--){
            for(int j = e.length - 2; j > -1; j--){
                if(e[j + 1] != '*'){
                    dp[i][j] = (s[i] == s[j] || e[j] == '.') &&dp[i + 1][j + 1];
                }else{
                    int si = i;
                    while(si != s.length && (s[si] == e[j] || e[j] == '.')){
                        if(dp[si][j + 2]){
                            dp[i][j] = true;
                            break;
                        }
                        si++;
                    }
                    if(dp[i][j] != true){
                        dp[i][j] = dp[si][j + 2];
                    }
                }
            }
        }
        return true;
    }

    public static boolean isValid(char[] s, char[] e){
        for(int i = 0; i < s.length; ++i){
            if(s[i] == '*' || s[i] == '.'){
                return false;
            }
        }
        for(int i = 0 ; i < e.length; ++i ){
            //前一个出现*的地方，下一个不能是*
            if(e[i] == '*' && (i == 0 || e[i - 1] == '*')){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args){


    }
}
