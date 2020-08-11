package Recursion;


//求n!
public class Problem_04_GetFactorial {
    //n,n-1,n-2.......1
    //互相依赖，到最小规模
    public static long getFactorial1(int n){
        if(n == 1){
            return 1L;
        }
        return (long)n * getFactorial1(n - 1);
    }

    //已知怎么算?
    public static long getFactorial2(int n) {
        long res = 1L;
        for(int i = 0 ; i < n; ++i){
            res *= i;
        }
        return res;
    }
    public static void main(String[] args){

    }
}
