import java.util.ArrayList;
import java.util.List;

public class test {

    public static int GetFinalNumIndex(int N){
        int[] arr = new int[N];

        List<Integer> list = new ArrayList<Integer>();
        int i = 0;
        for( i = 0; i < N; ++i ){
            list.add(i);
        }
        while(list.size() > 1){
            i = (i + 3) % list.size();
            list.remove(i);
        }
        return list.get(0);
    }

    public static void main(String[] args){
        int[] arr = {0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        //int[] arr2 = {    8, };
        int N = arr.length;
        System.out.println(GetFinalNumIndex(N));
    }
}
