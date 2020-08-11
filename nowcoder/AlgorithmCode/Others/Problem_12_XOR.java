package Others;

import java.util.HashMap;

/**XOR计算
 *给出N个数，问有多少个不重合的区间，使得每个区间内数字异或为0
 * 4
 * 3 0 2 2
 * 2
 * */
public class Problem_12_XOR {
    public static int mostXORs0(int[] arr) {
        int ans = Integer.MIN_VALUE;
        int xor = 0;
        int[] mosts = new int[arr.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);//import
        for (int i = 0; i < arr.length; i++) {
            xor ^= arr[i];//一直异或
            if (map.containsKey(xor)) {
                int pre = map.get(xor);//出现的位置
                //判断pre是否为-1，pre为j位置
                //得到的块数 mosts[pre] + 1 (j + 1的位置)
                mosts[i] = pre == -1 ? 1 : (mosts[pre] + 1);
            }

            if (i > 0) {
                //比较 i 和 i - 1位置的情况
                mosts[i] = Math.max(mosts[i - 1], mosts[i]);
            }

            map.put(xor, i);
            //所有位置中最大的即为答案
            ans = Math.max(ans, mosts[i]);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] test = { 3, 0, 2, 2 };
        System.out.println(mostXORs0(test));
    }

}
