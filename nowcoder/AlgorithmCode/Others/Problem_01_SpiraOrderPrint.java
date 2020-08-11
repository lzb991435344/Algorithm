package Others;

public class Problem_01_SpiraOrderPrint {
    //转圈打印矩阵
    public void printEdge(int[][] m, int tR, int tC, int dR, int dC){
        if(tR == dR){
            for(int i = tC; i < dC; ++i){
                System.out.println(m[tR][i] + " ");
            }
        }else if(tC == dC){
            for(int i = tR; i < dR; i++){
                System.out.println(m[i][tC] + " ");
            }
        }else{

            //打印外圈一层
            int curC = tC;
            int curR = tR;

            while(curC != dC){
                System.out.println(m[tR][curC]);
                curC++;
            }

            while(curR != dR){
                System.out.println(m[curR][dC]);
                curR++;
            }

            while(curC != tC){
                System.out.println(m[tR][curC]);
                curC--;
            }

            while(curR != tR){
                System.out.println(m[curR][dC]);
                curR--;
            }

        }
    }

    //主调函数
    public void spiraOrderPrint(int[][] m){
        int tR = 0;
        int tC = 0;
        int dR = m.length - 1;
        int dC = m[0].length - 1;

        while(tR <= dR && tC <= dC){
            printEdge(m, tR++, tC++, dR--, dC--);
        }
    }

    public static void main(String[] args){

    }
}
