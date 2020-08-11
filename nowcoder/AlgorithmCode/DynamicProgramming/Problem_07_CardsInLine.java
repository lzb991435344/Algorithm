package DynamicProgramming;

//纸牌博弈问题
public class Problem_07_CardsInLine {
    public static int win1(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        //代替递归函数
        //int sum = arr[1…..n];//for循环计算累加和
        //int f = f(arr, 0, arr.length - 1);
        //return Math.max(f, sum - f);
        return Math.max(f(arr, 0, arr.length - 1), s(arr, 0, arr.length - 1));
    }

    //先发过程
    //（1）依赖关系，fs之间的依赖关系
    //（2）i==j 斜线往右上角推，斜线左下角部信息完全不用
    public static int f(int[] arr, int i, int j) {
        //i == j 只有一个数
        if (i == j) { //二维表的斜线，即arr[i]
            return arr[i];
        }
        return Math.max(arr[i] + s(arr, i + 1, j), arr[j] +
                s(arr, i, j - 1));
    }

    //后发过程
    public static int s(int[] arr, int i, int j) {
        if (i == j) {
            return 0;
        }
        //i + 1 – j
        //i,j - 1
        return Math.min(f(arr, i + 1, j), f(arr, i, j - 1));
    }

    //递归过程会重复计算
    //用map存储过程中出现的值，只需要二维表上最右上角的值f(0, n-1)
    //递归函数的返回值可以被二维表代替
    public static int win2(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int[][] f = new int[arr.length][arr.length];
        int[][] s = new int[arr.length][arr.length];
        for (int j = 0; j < arr.length; j++) {
            f[j][j] = arr[j];//对角线
            for (int i = j - 1; i >= 0; i--) {
                //ex:j = 5,i=4,3,2,1
                //(4,5),(3,5),(2,5),(1,5) 右上角垂直往上推
                f[i][j] = Math.max(arr[i] + s[i + 1][j], arr[j] +
                        s[i][j - 1]);
                s[i][j] = Math.min(f[i + 1][j], f[i][j - 1]);
            }
        }
        return Math.max(f[0][arr.length - 1], s[0][arr.length - 1]);
    }

    //一张表
    public static int win3(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        int scores = p(arr, 0, arr.length - 1);
        return Math.max(sum - scores, scores);
    }

    public static int p(int[] arr, int i, int j) {
        if (i == j) {//1个数
            return arr[i];
        }
        if (i + 1 == j) { //2个数，先发者拿最大的数
            return Math.max(arr[i], arr[j]);
        }
        return
                Math.max(arr[i] + Math.min(p(arr, i + 2, j),p(arr, i + 1, j - 1)),
                        arr[j] + Math.min(p(arr, i + 1, j - 1), p(arr, i, j - 2)));
    }

    public static int win4(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        if (arr.length == 1) {
            return arr[0];
        }
        if (arr.length == 2) {
            return Math.max(arr[0], arr[1]);
        }
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        int[][] dp = new int[arr.length][arr.length];
        for (int i = 0; i < arr.length - 1; i++) {
            dp[i][i] = arr[i];
            dp[i][i + 1] = Math.max(arr[i], arr[i + 1]);
        }
        dp[arr.length - 1][arr.length - 1] = arr[arr.length - 1];
        for (int k = 2; k < arr.length; k++) {
            for (int j = k; j < arr.length; j++) {
                int i = j - k;
                dp[i][j] =
                        Math.max(arr[i] + Math.min(dp[i + 2][j], dp[i + 1][j - 1]),
                                arr[j] + Math.min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
        return Math.max(dp[0][arr.length - 1], sum - dp[0][arr.length - 1]);
    }

    public static int[] generateRondomArray() {
        int[] res = new int[(int) (Math.random() * 20) + 1];
        for (int i = 0; i < res.length; i++) {
            res[i] = (int) (Math.random() * 20) + 1;
        }
        return res;
    }

    public static void main(String[] args) {
        int testTime = 50000;
        boolean err = false;
        for (int i = 0; i < testTime; i++) {
            int[] arr = generateRondomArray();
            int r1 = win1(arr);
            int r2 = win2(arr);
            int r3 = win3(arr);
            int r4 = win4(arr);
            if (r1 != r2 || r1 != r3 || r1 != r4) {
                err = true;
            }
        }
        if (err) {
            System.out.println("2333333333");
        } else {
            System.out.println("6666666666");
        }
    }

}

