package Others;

import java.util.Arrays;
import java.util.Scanner;

/***疯狂队列
 *
 * 5
 * 5 10 25 40 25
 * 100
 *
 * */
public class Problem_18_MaxMad {


    public static int maxMad(int[] arr) {
        Arrays.sort(arr);//怎样排序的?
        //下标
        int res = arr[arr.length - 1] - arr[0];
        int maxI = arr.length - 2;
        int minI = 1;

        //
        while (minI < maxI) {
            res += arr[maxI + 1] - arr[minI];
            res += arr[maxI] - arr[minI - 1];
            maxI--;
            minI++;
        }

        if (minI == maxI) {
            res += Math.max(arr[minI] - arr[minI - 1], arr[minI + 1] - arr[minI]);
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
            }
            System.out.println(maxMad(arr));
        }
        in.close();
    }

}
