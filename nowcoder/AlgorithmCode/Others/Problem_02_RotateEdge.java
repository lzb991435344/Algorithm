package Others;

public class Problem_02_RotateEdge {
    //正方形顺时针旋转90度
    public void rotate(int[][] m){
        int tR = 0;
        int tC = 0;
        int dR = m.length - 1;
        int dC = m[0].length - 1;

        while(tR <= dR && tC <= dC){
            rotateEdge(m, tR++, tC++, dR--, dC--);
        }
    }

    public void rotateEdge(int[][] m, int tR, int tC, int dR, int dC){
        int times = dC - tC;
        int tmp = 0;

        for(int i = 0; i != times; ++i){
            tmp = m[tR][tC + i];
            m[tR][tC + i] = m[dR - i][tC];
            m[dR - i][tC] = m[dR][dC - i];
            m[dR][dC - i] = m[tR + i][dC];
            m[tR + i][dC] = tmp;
        }
    }

    public static void main(String[] args){

    }
}
