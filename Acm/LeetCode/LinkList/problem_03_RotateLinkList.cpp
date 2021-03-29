#include <iostream>

/*leetCode  61
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
*/
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    //方法1  key：找到最后一个有效的节点
    ListNode* Rotate_Right(ListNode *head, int k){
        if (!head || !head->next){
            return  head;
        }

        ListNode* p = head;

        int node_sum = 0;
        while(p->next){
            node_sum++;
            p = p->next;
        }

        int x = k % node_sum; //取模找到节点位置
        if(!x) return head;
        ListNode* tail = p;

        int i = 1;
        p = head;

        //找到n新链表ullptr节点的前一个位置
        while(i < node_sum){
            p = p->next;
            i++;
        }

        //重新连接链表
        ListNode* newHead = p->next; //确定新头的位置
        tail->next = head;
        p->next = nullptr; //p的写一个节点是nullptr
        return newHead;
    }

    //方法2
    //key：快慢指针找到k+1的位置
    ListNode* Rotate_Right2(ListNode *head, int k){

        ListNode* p = head;

        int node_sum = 0;
        while(p->next){
            node_sum++;
            p = p->next;
        }

        int x = k % node_sum;
        if(!x){
            return head;
        }

        ListNode* fast = head,*slow = head;

        while(x--){
            fast = fast->next;
        }

        //找到相应的问题
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        //连接新的链表
        ListNode* newHead = slow->next;
        fast->next = head;
        slow->next = nullptr;

        return newHead;
    }

private:

};

