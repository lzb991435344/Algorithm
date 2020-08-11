package Sort;

public class Problem_01_InsertSort {
    public void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    //异或的方式，省一个tmp变量
    public void swap2(int[] arr, int i, int j){

    }

    public int[] generateRandomArray(int size, int value){
        int[] arr = new int[(int) ((size + 1) * Math.random())];
        for(int i = 0; i < arr.length; ++i){
            arr[i] = (int)((value + 1)* Math.random() - (int)(value * Math.random()));
        }
        return arr;
    }

    public void insertSort(int[] arr){
        for(int i = 1; i < arr.length; ++i){
            for(int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--){
                swap(arr, j, j + 1);
            }
        }
    }
}
