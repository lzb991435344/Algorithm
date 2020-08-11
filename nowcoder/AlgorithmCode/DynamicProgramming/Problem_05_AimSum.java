package DynamicProgramming;


//给定一数组，和aim，任意选择数，能否加出aim
public class Problem_05_AimSum {

    public static boolean isAimSum(int[] arr, int i, int sum, int aim){
        if(i == arr.length - 1){
            return sum == aim;
        }
        return isAimSum(arr, i + 1, sum, aim) || isAimSum(arr, i, sum + arr[i], aim);
    }
    public static void main(String[] args){
        int[] arr={1, 4, 8};
        int aim = 12;
        System.out.println(isAimSum(arr, 0, 0, aim));
    }
}
