package Array;

//正数的数组中，求累加和等于给定值的最长子数组的长度
public class Problem_13_GetMaxLen {

    public static int GetMaxLen(int[] arr, int k){
        if(arr == null || arr.length == 0  || k < 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int res = 0;
        int sum = arr[0];
        while(right <= arr.length){
            if(sum == k){//等于当前值
                res = Math.max(res, right - left + 1);
                sum -= arr[left++];
            }else if(sum < k){//当前sum小于k
                right++;//向右扩
                if(right == arr.length){//等于总长度
                    break;
                }
                sum += arr[right];
            }else{//左边向右扩
                sum -=arr[left++];
            }
        }
        return res;
    }
    public static void main(String[] args){
        int[] arr = {1,2,1,1,1};
        int k = 3;
        int res = GetMaxLen(arr, k);

        System.out.println("Res is:" + res);
    }
}
