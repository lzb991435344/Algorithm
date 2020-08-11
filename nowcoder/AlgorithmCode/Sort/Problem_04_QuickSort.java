package Sort;

public class Problem_04_QuickSort {
    public static void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    //quickSort
    public static int[] partion(int[] arr, int l, int r){
        int less = l - 1;
        int more = r;
        while(l < more){
            if(arr[l] < arr[r]){
                //less 往右扩大
                swap(arr,++less, l++);
            }else if(arr[l] > arr[r]){
                //more往左扩大
                swap(arr, --more, l);
            }else{
                l++;
            }
        }
        swap(arr, more, r);
        //返回两个值
        return new int[]{less + 1, more};
    }
    public static void quickSort(int[] arr, int l, int r){
        if(l < r){
            //随机快排
            swap(arr,l + (int)(Math.random() * (r - l + 1)) ,r);
            int[] p = partion(arr, l, r);
            quickSort(arr, l, p[0] - 1);//相等区域的左边界
            quickSort(arr, p[1] + 1, r);//相等区域的右边界
        }
    }


    //O(N*logN)
    public  void  myqsort(int[] a, int l, int r) {
        int i, j;
        int tmp;
        if (l > r) {
            return;
        }

        i = l;
        j = r;
        tmp = a[i];

        while (i != j) {
            while (i < j && a[j] <= tmp) {
                j--;
            }
            if(i < j){
                a[i++] = a[j];
            }


            while (i < j && a[i] >= tmp) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }

        }
        a[i] = tmp;

        myqsort(a,l, i - 1);
        myqsort(a, i + 1, r);
    }

    public static void main(String[] args){
        int[] arr = {3,2,0,7,4,5};
        quickSort(arr, 0, arr.length - 1);
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }

}
