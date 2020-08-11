package CodePractice;

public class Problem_02_MakeNo {

    public static int[] makeNo(int size){
        if(size == 1){
            return new int[1];
        }

        //size
        //halfsize 一半长达标，向上取整
        //[7:4] [4个奇数][3个偶数]
        int halfSize = (size + 1)/2;
        //等长的奇数达标
        int[] base = makeNo(halfSize);
        //等长的偶数达标
        int[] ans = new int[size];
        int index = 0;

        //左侧放奇数
        for(; index < halfSize; index++){
            ans[index] = base[index]*2 + 1;
        }

        //右侧放偶数
        for(int i = 0; index < size; index++, i++){
            ans[index] = base[i] *2;
        }
        return ans;
    }


    public static boolean isValid(int[] arr){
        int N = arr.length;
        for(int i = 0 ; i < N; i++){
            for(int k = i + 1; k < N; k++){
                for(int j = k + 1; j < N; j ++){
                    if(arr[i] + arr[j] == 2*arr[k]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    public static void main(String[] args){
        System.out.println("start");
        for(int N = 1; N < 1000; N++){
            int[] arr = makeNo(N);
            if(!isValid(arr)){
                System.out.println("error");
            }
        }
        System.out.println("end");
        System.out.println(isValid(makeNo(1024)));
        System.out.println(isValid(makeNo(2055)));
    }

}
