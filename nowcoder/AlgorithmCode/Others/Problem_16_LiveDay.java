package Others;

import java.util.Scanner;


//独立的小易
/**
 *
 * 3 5 100 10
 * 11
 * */
public class Problem_16_LiveDay {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int x = in.nextInt();
            int f = in.nextInt();
            int d = in.nextInt();
            int p = in.nextInt();
            System.out.println(liveDay(x,f,d,p));

        }
        in.close();
    }
    public static int liveDay(int x, int f, int d, int p) {
        int p1 = d / x;
        if (p1 <= f) {
            return p1;
        }
        int rest = d - f * x;
        return f + rest / (p + x);
    }

}
