package Sort;

public class Problem_03_SelectSort {
    public static void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    public static void selectSort(int[] arr){
        for(int i = 0; i < arr.length; ++i){
            int index = i;
            for(int j = i + 1; j < arr.length; ++j){
                //选择小的索引
                index = arr[j] < arr[index] ? j : index;
            }
            swap(arr, i, index);
        }
    }

    public static void main(String[] args){
        int[] arr ={3,2,0,4,7};

        selectSort(arr);
        for(int i =0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }
}
