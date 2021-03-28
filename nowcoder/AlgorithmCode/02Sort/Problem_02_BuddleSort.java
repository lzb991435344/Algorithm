package Sort;

public class Problem_02_BuddleSort {
    public void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public  void buddleSort(int[] arr){
        for(int end = arr.length - 1; end > 0; --end){
            for(int i = 0; i  < end; ++i){
                if(arr[i] > arr[ i + 1]){
                    swap(arr, i, i  + 1);
                }
            }
        }
    }
}
