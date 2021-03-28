package Sort;

public class Problem_06_HeapSort {

    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    //heapsort
    //建堆 O(N)
    public static void heapInsert(int[] arr, int index) {
        //父节点较小,当前数较大
        while (arr[index] > arr[(index - 1) / 2]) {
            swap(arr, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    public static void heapify(int[] arr, int index, int heapsize) {
        int left = 2 * index + 1;
        while (left < heapsize) {
            //找出值较大的下标
            //只有左孩子是越界的情况，则最大为左孩子
            int largest = left + 1 < heapsize && arr[left + 1] > arr[left] ? left + 1 : left;

            //三者之间, left + 1, left, right
            largest = arr[largest] > arr[index] ? largest : index; //堆顶改变之后仍然作为堆顶
            if (largest == index) {//不需要调整
                break;
            }
            //往下调
            swap(arr, largest, index);//largest != index
            index = largest;
            left = index * 2 + 1;//左孩子往下走
        }

    }

    public static void heapSort(int[] arr) {
        if (arr.length < 2 || arr == null) {
            return;
        }
        for (int i = 0; i < arr.length; ++i) {
            //形成大根堆，无序
            heapInsert(arr, i);
        }
        int heapsize = arr.length;

        //堆顶和最后一个位置交换
        swap(arr, 0, --heapsize);

        //调整让堆结构合理
        while (heapsize > 0) {
            //变小之后再调整
            heapify(arr, 0, heapsize);
            swap(arr, 0, --heapsize);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 7, 3, -4, 6, 8};
        int len = arr.length;
        heapSort(arr);
        for (int i = 0; i < len; i++) {
            System.out.println(arr[i]);
        }
    }
}
