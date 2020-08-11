package Sort;

public class Problem_05_MergeSort {
    public static void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    //mergeSort
    public static void mergeSort(int[] arr, int l, int r){
        if(l == r){
            return;
        }
        int mid = (l + r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    public static void merge(int[] arr, int l, int mid, int r){
        //不返回help
        int[] help = new int[r - l + 1];
        int i = 0;
        int p1 = l;
        int p2 = mid + 1;
        while(p1 <= mid && p2 <= r){
            //填小的部分
            help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }

        //其中一个越界处理
        while(p1 <= mid){
            help[i++] = arr[p1++];
        }

        while(p2 <= r){
            help[i++] = arr[p2++];
        }
        //merge之后数组有序，复制回数组，全部有序
        for(i = 0; i < help.length; ++i){
            arr[l + i] = help[i];
        }
    }

    public static void main(String[] args){
        int[] arr ={2,6,1,-3,8};
        mergeSort(arr, 0 ,arr.length - 1);
        for(int i = 0; i < arr.length; i++ ){
            System.out.println(arr[i]);
        }
    }

}
