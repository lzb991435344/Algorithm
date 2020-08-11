package Array;

import java.util.HashMap;

//正数
public class Problem_14_LongestSumSubArrayLength {

    public static int maxLength0(int[] arr, int aim){
        if(arr == null || arr.length == 0 || aim <= 0 ){
            return 0;
        }

        int l = 0;
        int r = 0;
        int sum = arr[0];
        int len = 0;
        while(r < arr.length){
            if(sum == aim){
                len = Math.max(len, r - l + 1);
                sum -= arr[l++];
            }else if(sum < aim){
                r++;
                if(r == arr.length){
                    break;
                }
                sum += arr[r];
            }else{
                sum -= arr[l++];
            }
        }
        return len;
    }

    public static int maxLength(int[] arr, int k) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, -1); // important
        int len = 0;
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];//一直累加
            if (map.containsKey(sum - k)) {//
                len = Math.max(i - map.get(sum - k), len);
            }
            if (!map.containsKey(sum)) {
                map.put(sum, i);//添加到map中
            }
        }
        return len;
    }
    public static int[] generateArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i != size; i++) {
            result[i] = (int) (Math.random() * 11) - 5;
        }
        return result;
    }
    public static void printArray(int[] arr) {
        for (int i = 0; i != arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = generateArray(20);
        printArray(arr);
        System.out.println(maxLength(arr, 10));
        System.out.println(maxLength0(arr, 10));
    }
}
