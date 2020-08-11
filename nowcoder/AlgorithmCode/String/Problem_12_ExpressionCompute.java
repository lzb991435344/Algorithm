package String;

import java.util.LinkedList;

//字符串表达式求值
//记录特殊情况，边界值，测试的时候需要
public class Problem_12_ExpressionCompute {
    public static int getValue(String str) {
        return value(str.toCharArray(), 0)[0];
    }

    //f()
    //i位置为开始位置
    public static int[] value(char[] str, int i) {
        LinkedList<String> que = new LinkedList<String>();
        int pre = 0;
        int[] bra = null;

        while (i < str.length && str[i] != ')') {
            if (str[i] >= '0' && str[i] <= '9') {//数字
                pre = pre * 10 + str[i++] - '0';
            } else if (str[i] != '(') {//非左括号， + - * /
                addNum(que, pre);
                que.addLast(String.valueOf(str[i++]));
                pre = 0;//遇到运算符，重新收集数字
            } else {//左括号
                //配对的右括号的值
                bra = value(str, i + 1);
                pre = bra[0];
                i = bra[1] + 1;
            }
        }
        addNum(que, pre);
        //arr.length == 2
        //arr[0]---计算结果
        //arr[1]---计算到的位置
        return new int[] { getNum(que), i };
    }
    public static void addNum(LinkedList<String> que, int num) {
        if (!que.isEmpty()) {
            int cur = 0;
            String top = que.pollLast();
            if (top.equals("+") || top.equals("-")) {
                que.addLast(top);
            } else {
                cur = Integer.valueOf(que.pollLast());
                num = top.equals("*") ? (cur * num) : (cur / num);
            }
        }
        que.addLast(String.valueOf(num));
    }

    //返回计算结果
    public static int getNum(LinkedList<String> que) {
        int res = 0;
        boolean add = true;
        String cur = null;
        int num = 0;
        while (!que.isEmpty()) {
            /**
             public E pollFirst()  返回列表中的第一个元素，否则返回空
             */
            cur = que.pollFirst();
            if (cur.equals("+")) {
                add = true;
            } else if (cur.equals("-")) {
                add = false;
            } else {
                /**
                 //Integer.parseInt("")
                 public static int parseInt(String s) throws NumberFormatException {
                 return parseInt(s,10); }
                 //Integer.valueOf("")
                 public static Integer valueOf(String s) throws NumberFormatException { return Integer.valueOf(parseInt(s, 10)); }
                 //new Integer("")
                 public Integer(String s) throws NumberFormatException { this.value = parseInt(s, 10); }
                 */
                num = Integer.valueOf(cur);
                res += add ? num : (-num);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String exp = "48*((70-65)-43)+8*1";
        System.out.println(getValue(exp));

        exp = "4*(6+78)+53-9/2+45*8";
        System.out.println(getValue(exp));

        exp = "10-5*3";
        System.out.println(getValue(exp));

        exp = "-3*4";
        System.out.println(getValue(exp));

        exp = "3+1*4";
        System.out.println(getValue(exp));
    }

}
