package Recursion;

public class Problem_05_Hanoi {

    public static void process(int N, String from, String to, String help){
        if(N == 1){
           System.out.println("Move 1 from" + from + "to" + to);
        }else{
        process(N - 1, from, help, to);//from移动到help
        System.out.println("Move N-1 from" + from + "to" + to);
        process(N-1, help, to, from);//help上移动到to
    }

    }

    public static void main(String[] args){
        int n = 3;
        process(3, "左","右","中");
    }
}
