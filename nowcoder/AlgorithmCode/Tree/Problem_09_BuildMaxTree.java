package Tree;

//数组变树
//单调栈
//值最大的节点是树的头,数组无重复元素，每个元素对应树的一个节点
//O(N) O(N)
public class Problem_09_BuildMaxTree {
    public int[] buildMaxTree(int[] A, int n) {
        int res[] = new int[n];
        // 遍历每个值去获取结果
        for (int i = 0; i < n; i++) {
            res[i] = getIndex(i, A, n);
        }
        return res;
    }

    public int getIndex(int target, int[] A, int n) {
        int left = -1;// 左边第一个比它大的数索引
        int right = n;// 右边第一个比它大的数索引

        // 更新右索引
        for (int i = target + 1; i < n; i++) {
            if (A[i] > A[target]) {
                right = i;
                break;
            }
        }
        // 更新左索引
        for (int i = target - 1; i >= 0; i--) {
            if (A[i] > A[target]) {
                left = i;
                break;
            }
        }
        // 当两个索引都没变化，说明左右两边都没有比它大的数，根节点返回-1
        if (left == -1 && right == n) {
            return -1;
            // 两个索引都发生变化了，此时返回元素更小的那个索引
        } else if (left != -1 && right != n) {
            return A[left] > A[right] ? right : left;
            // 同理 返回左边
        } else if (left != -1 && right == n) {
            return left;
            // 右索引有变化，左索引没有。说明右边更小并返回
        } else if (left == -1 && right != n) {
            return right;
        }
        return 0;
    }
    public static void main(String[] args) {
       // test t = new test();
        int[] arr = {3,1,4,2};
        int len = arr.length;
        int[] res={0};

       // res = t.buildMaxTree(arr, len);
        for(int i = 0; i <res.length; ++i){
            System.out.println(res[i]);
        }
    }
}
