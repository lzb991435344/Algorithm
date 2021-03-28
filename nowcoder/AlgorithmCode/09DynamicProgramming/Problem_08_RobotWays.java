package DynamicProgramming;

public class Problem_08_RobotWays {
    //N生成1....N的数
    //M初始停留的位置
    //P往左或者往右走P步
    //K停留在K位置上的种类
    //暴力递归方法
    public static  int robotWays(int N, int M, int P, int K){
        if(N < 2 || M < 1 || P < 0 || K < 1 || K > N){
            return 0;
        }
        if(P == 0){
            return M == K ?  1 : 0;
        }

        int res = 0;
        if(M == 1){
            res = robotWays(N, M + 1, P - 1, K);
        }else if(M == N){
            res = robotWays(N, M - 1, P - 1, K);
        }else{
            res = robotWays(N, M + 1, P - 1, K) + robotWays(N, M - 1, P - 1, K);
        }
        return res;
    }

    public static void main(String[] args){
        System.out.println(robotWays(4, 2, 2,2));
    }
}
