package Others;


/**堆棋子
 *
 * 4
 *1 2  4 9
 * 1 1 1 1
 *
 * out: 0 1 3 10
 *
 * */
import java.util.PriorityQueue;
import java.util.Scanner;

public class Problem_17_MinOps {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int size = in.nextInt();
            int[] x = new int[size];
            int[] y = new int[size];
            for (int i = 0; i < size; i++) {
                x[i] = in.nextInt();
            }
            for (int i = 0; i < size; i++) {
                y[i] = in.nextInt();
            }
            int[] res = minOPs(size, x, y);
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < size; i++) {
                result.append(String.valueOf(res[i]) + " ");
            }
            System.out.println(result.toString().trim());
        }
        in.close();
    }

    public static int[] minOPs(int size, int[] x, int[] y) {
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            //存返回的结果
            res[i] = Integer.MAX_VALUE;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                //x[i],y[j] 到所有点的曼哈顿距离
                for (int k = 0; k < size; k++) {
                    //加入小根堆
                    pq.add(Math.abs(x[k] - x[i]) + Math.abs(y[k] - y[j]));
                }
                int resI = 0;
                int sum = 0;
                while (!pq.isEmpty()) {
                    sum += pq.poll();
                    //求所有棋子中的代价的大小，求最小值
                    res[resI] = Math.min(res[resI], sum);
                    resI++;
                }
            }


        }
        return res;
    }

}
