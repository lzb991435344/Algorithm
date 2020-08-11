package CodePractice;

import java.util.Arrays;
import java.util.Comparator;

public class Problem_04_KthMinPair {

    public static class Pair{
        int x;
        int y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static class PairComparator implements Comparator<Pair>{
        @Override
        public int compare(Pair o1, Pair o2) {
            return o1.x != o2.x ? o1.x - o2.x : o1.y - o2.y;
        }
    }

    public static int[] kthMinPair1(int[] arr, int k){
        int N = arr.length;
        if(k > N*N){
            return null;
        }

        Pair[] pairs = new Pair[N * N];
        int index = 0;
        for(int i = 0; i < N; ++i ){
            for(int j = 0; j < N ; j++){
                pairs[index++] = new Pair(arr[i], arr[j]);
            }
        }
        Arrays.sort(pairs, new PairComparator());

        //第k, 1 0
        //     2 1
        return new int[] {pairs[k - 1].x, pairs[k - 1].y};
    }

    //优化解 O(N*logN)
    public static int[] kthMinPair2(int[] arr, int k){
        int N = arr.length;
        if(k > N * N){
            return null;
        }
        Arrays.sort(arr);

        //第一维的数组
        int firstNum = arr[(k - 1)/N];
        int firstNumSize = 0;
        int lessFirstNumSize = 0;
        //遍历 <= firstNum的部分
        for(int i = 0; i < N && arr[i] <= firstNum; i++){
            if(arr[i] < firstNum){
                //小于firstNum的数
                lessFirstNumSize++;
            }else{
                //等于firstNum的数
                firstNumSize++;
            }
        }
        //淘汰不需要的数
        int res = k - (lessFirstNumSize * N);

        return new int[] {firstNum, arr[(res - 1)/ firstNumSize]};
    }


    //O(N) 不排序得到排序后的
    //bfbrt
    public static int[] kthMinPair3(int[] arr, int k){
        int N = arr.length;
        if(k > N * N){
            return null;
        }
        //在无序数组中，找到第k小的数，返回值
        //第k小，以1作为开始位置
        int firstNum = getMinKthByBFPRT(arr, ((k - 1)/N) + 1);
        int lessFirstNumSize = 0;
        int firstNumSize = 0;

        for(int i = 0; i < N; i++ ){
            if(arr[i] < firstNum){
                lessFirstNumSize++;
            }
            if(arr[i] == firstNum){
                firstNumSize++;
            }
        }
        int res = k - (lessFirstNumSize * N);
        return new int[] {firstNum, getMinKthByBFPRT(arr, ((res - 1)/firstNumSize))};
    }

    public static int getMinKthByBFPRT(int[] arr, int k){

        return select(arr, 0, arr.length - 1, k - 1);
    }

    public static int select(int[] arr, int begin, int end, int i) {
        if (begin == end) {
            return arr[begin];
        }
        int pivot = medianOfMedians(arr, begin, end);
        int[] pivotRange = partition(arr, begin, end, pivot);
        if (i >= pivotRange[0] && i <= pivotRange[1]) {
            return arr[i];
        } else if (i < pivotRange[0]) {
            return select(arr, begin, pivotRange[0] - 1, i);
        } else {
            return select(arr, pivotRange[1] + 1, end, i);
        }
    }
    public static int medianOfMedians(int[] arr, int begin, int end) {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        int[] mArr = new int[num / 5 + offset];
        for (int i = 0; i < mArr.length; i++) {
            int beginI = begin + i * 5;
            int endI = beginI + 4;
            mArr[i] = getMedian(arr, beginI, Math.min(end, endI));
        }
        return select(mArr, 0, mArr.length - 1, mArr.length / 2);
    }
    public static int[] partition(int[] arr, int begin, int end, int pivotValue) {
        int small = begin - 1;
        int cur = begin;
        int big = end + 1;
        while (cur != big) {
            if (arr[cur] < pivotValue) {
                swap(arr, ++small, cur++);
            } else if (arr[cur] > pivotValue) {
                swap(arr, cur, --big);
            } else {
                cur++;
            }
        }
        int[] range = new int[2];
        range[0] = small + 1;
        range[1] = big - 1;
        return range;
    }

    public static int getMedian(int[] arr, int begin, int end) {
        insertionSort(arr, begin, end);
        int sum = end + begin;
        int mid = (sum / 2) + (sum % 2);
        return arr[mid];
    }

    public static void insertionSort(int[] arr, int begin, int end) {
        for (int i = begin + 1; i != end + 1; i++) {
            for (int j = i; j != begin; j--) {
                if (arr[j - 1] > arr[j]) {
                    swap(arr, j - 1, j);
                } else {
                    break;
                }
            }
        }
    }

    public static void swap(int[] arr, int index1, int index2) {
        int tmp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = tmp;
    }

    public static void main(String[] args){
        int[] arr={3, 1, 2};
        int[] arr2= {0};
        int k = 3;

        arr2 = kthMinPair3(arr, k);
        for(int i = 0; i < arr2.length; ++ i){
            System.out.println(arr2[i]);
        }
    }

}




