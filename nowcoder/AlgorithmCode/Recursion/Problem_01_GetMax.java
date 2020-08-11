package Recursion;

public class Problem_01_GetMax {
    //从数组中获取最大值
    public static int getMax(int[] arr, int l, int r){
        if(l == r){
            return arr[l];
        }
        int mid = l + (r - l)/2;
        int leftMax = getMax(arr, l, mid);
        int rightMax = getMax(arr, mid + 1, r);

        return Math.max(leftMax, rightMax);
    }

    public static int[] getRandomArray(int len) {
        if (len < 0) {
            return null;
        }
        int[] arr = new int[len];
        for (int i = 0; i < len; i++) {
            //[0,1)* 10 = [0,10)
            arr[i] = (int) (Math.random() * 100);
        }
        return arr;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i != arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        //int[] arr = {-1, -2, 4 ,9 ,2};
        int[] arr = getRandomArray(10);
        printArray(arr);
        System.out.println(getMax(arr, 0, arr.length - 1));
    }
}
