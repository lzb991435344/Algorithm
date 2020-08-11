package Others;

public class Problem_03_PrintMatrixZigZag {

    //zigzag打印矩阵
    public void printMatrixZigZag(int[][] m){
        int tR = 0;
        int tC = 0;
        int dR = 0;
        int dC = 0;
        int endR = m.length - 1;
        int endC = m[0].length - 1;
        boolean flag = false;
        while(tR != endR + 1){
            printLevel(m, tR, tC, dR, dC, flag);
            tR = tC == endC ? tR + 1 : tR;
            tC = tC == endC ? tC : tC + 1;
            dC = dR == endR ? dC + 1 : dC;
            dR = dR == endR ? dR : dR + 1;

            flag = true;
        }
        System.out.println(" ");
    }

    public void printLevel(int[][] m, int tR, int tC, int dR, int dC, boolean flag){
        if(flag){
            while(tR != dR + 1){
                System.out.println(m[tR++][tC--]);
            }
        }else{
            while(dR != tR - 1){
                System.out.println(m[dR--][dC++]);
            }
        }
    }
    public static void main(String[] args){

    }
}
