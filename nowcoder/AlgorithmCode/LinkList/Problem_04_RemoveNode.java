package LinkList;

public class Problem_04_RemoveNode {
    public class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }
    public static ListNode  removeNode(ListNode pNode, int delVal) {

        //新建临时节点
        ListNode temp = pNode;

        // 首先判断头节点是否为要被删除节点
        if (pNode.val == delVal) {
            pNode = pNode.next;
            return pNode;
        }

        // 当被删除节点存在中间部分时
        while (temp.next != null) {
            if (temp.next.val == delVal) {
                temp.next = temp.next.next;
                return pNode;
            }
            temp = temp.next;
        }

        // 被删除节点为尾节点时
        if (temp.next == null) {
            temp = null;
        }
        return pNode;
    }

    public static void main(String[] args){
        Problem_04_RemoveNode t = new Problem_04_RemoveNode();

       /** ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);

        node1.next = node2;
        node1.next.next= node3;
        node1.next.next.next = node4;
        node1.next.next.next.next= node5;
        node1.next.next.next.next.next = null;

        ListNode res = null;
        res = t.removeNode(node4,4);

        while(res!=null) {
            System.out.println("res is:" + res.val);
            res = res.next;
        }*/
    }
}
