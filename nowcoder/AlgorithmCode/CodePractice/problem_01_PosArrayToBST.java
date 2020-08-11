package CodePractice;

public class problem_01_PosArrayToBST {

    public static class Node{
        public int value;
        public Node left;
        public Node right;

        public Node(int value){
            this.value = value;
        }

        public static Node posArrayToBST(int[] posArr){
            return process1(posArr, 0 , posArr.length - 1);
        }

        //棒状结构为时间最差复杂度 O(N*N)
        public static Node process1(int[] posArr, int l, int r){
            if(l > r){
                return null;
            }
            Node head = new Node(posArr[r]);
            //只含有一个头结点
            if(l == r){
                return head;
            }

            int m = l - 1;//初始化为无效范围
            //找出有效范围的数，找出下标索引
            for(int i = l; i < r; i++){
                //找出小于头结点的数的下标索引
                if(posArr[i] < posArr[r]){
                    m = i;
                }
            }
            head.left = process1(posArr, l, m);
            head.right = process1(posArr, m + 1, r - 1);
            return head;
        }

        //m范围
        public static Node process3(int[] posArr, int l, int r){
            if(l > r){
                return null;
            }
            Node head = new Node(posArr[r]);
            //只含有一个头结点
            if(l == r){
                return head;
            }

            int m = -1;//初始化为无效范围
            //找出有效范围的数，找出下标索引
            for(int i = l; i < r; i++){
                //找出小于头结点的数的下标索引
                if(posArr[i] < posArr[r]){
                    m = i;
                }
            }
            // >
            if(m == -1){
                head.right = process3(posArr, l, r - 1);
            }else if(m == r - 1){ // <
                head.left = process3(posArr, l, r - 1);
            }else{// > 和 <
                head.left = process3(posArr, l, m);
                head.right = process3(posArr, m + 1, r - 1);
            }
            return head;
        }

        //最优解
        //寻找小于头结点的数的最右节点
        public static Node posArrayToBST2(int[] posArr){
           return process2(posArr, 0, posArr.length - 1);
        }

        public static Node process2(int[] posArr, int l, int r){
            if(l > r){
                return null;
            }

            Node head = new Node(posArr[r]);
            if(l == r){
                return head;
            }

            int m = l - 1;
            int left = l;
            int right = r;
            //二分
            while(left < right){
                // int mid = left + (right - left)>>1
                int mid = left + (right - left)/2;
                if(posArr[mid] < posArr[r]){
                    m = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            head.left = process1(posArr, l, m);
            head.right = process1(posArr, m + 1, r - 1);
            return head;
        }
    }

    public static void main(String[] args){

    }
}
