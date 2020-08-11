package Array;

public class Problem_20_Shuff {
    public static void shuffle(int[] arr) {
        //偶数
        if(arr != null && arr.length != 0 && (arr.length & 1) == 0){
            shuffle(arr, 0 , arr.length - 1);
        }
    }

    public static void shuffle(int[] arr, int l, int r){
        while(r - l + 1 > 0){
            int lenAndOne = r - l + 2;
            int bloom = 3;
            int k = 1;

            while(bloom <= lenAndOne/3){
                bloom *= 3;
                k++;
            }
            int m = (bloom - 1) / 2;
            int mid = (l + r) / 2;
            rotate(arr, l + m, mid, mid + m);
            cycle(arr, l - 1, bloom, k);
            l = l + bloom - 1;
        }
    }

    public static void cycle(int[] arr, int base, int bloom, int k){
        for(int i = 0, trigger = 1; i  < k; i++, trigger *= 3 ){
            int next = (2 * trigger) % 3;
            int cur = next;
            int record = arr[next + base];
            int tmp = 0;

            arr[next + base] = arr[trigger + base];
            while(cur != trigger){
                next = (2 * cur) % bloom;
                tmp = arr[next + base];
                arr[next + base] = record;
                cur = next;
                record = tmp;
            }
        }
    }
    public static void rotate(int[] arr, int l, int m, int r){
        reverse(arr, l, m);
        reverse(arr, m + 1, r);
        reverse(arr, l, r);
    }

    public static void reverse(int[] arr, int l, int r){
        while(l < r){
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i != arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5};
        reverse(arr, 0 , 2);
        printArray(arr);
    }
}
