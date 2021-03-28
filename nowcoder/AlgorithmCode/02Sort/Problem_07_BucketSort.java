package Sort;

public class Problem_07_BucketSort {

    //给定一个数组，排序后求相邻两数的最大值差值，不能用比较的排序
    public int  bucket(long num, long len, long min, long max){
        return (int)((num - min) * len /(max - min));
    }


    public int  maxGap(int[] num){
        if(num == null || num.length < 2){
            return 0;
        }
        int len = num.length;
        int min = Integer.MAX_VALUE;
        int max= Integer.MIN_VALUE;

        for(int i = 0; i < len; ++i){
            min = Math.min(min, num[i]);
            max = Math.max(max, num[i]);
        }
        if(min == max) return 0;
        boolean[] hasnum = new boolean[len + 1];
        int[] maxs = new int[len + 1];
        int[] mins = new int[len + 1];

        int bid = 0;
        for(int i = 0; i < len; ++i){
            bid = bucket(num[i], len, min, max);

            //桶里的最大最小值被更新
            mins[bid] = hasnum[bid] ? Math.min(mins[bid], num[i]):num[i];
            maxs[bid] = hasnum[bid] ? Math.max(maxs[bid], num[i]):num[i];
            hasnum[bid] = true;//
        }

        int res = 0;
        int lastmax = maxs[0];
        int i = 1;
        for(; i <= len; ++i){
            if(hasnum[i]) {
                //当前的最小进去前一个的最大值
                res = Math.max(res, mins[i] - lastmax);
                lastmax = maxs[i];
            }

        }
        return res;
    }
}
