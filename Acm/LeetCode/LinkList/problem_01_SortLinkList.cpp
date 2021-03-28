#include <iostream>

/*
在O(n log n)的时间内使用常数级空间复杂度对链表进行排序。
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *binarySort(ListNode *head, ListNode *left, ListNode *right)
    {
        //zero or one elment
        //递归出口，把right想象成尾节点
        if (head == right || head->next == right)
            return head;

        ListNode *left_head = head;
        ListNode *current = head->next;
        ListNode *left_tail = left;
        ListNode *right_tail = head;
        while (current != right)
        {
            //当前节点小于等于头结点
            if (current->val <= head->val)
            {
                ListNode *next = current->next;
                current->next = left_head;
                left_tail->next = current;
                //handle duplicate value which equals to head->val
                //if equals then let left_head be the current, otherwise move left tail to next one.

                if (current->val == head->val)
                    left_head = current;
                else
                    left_tail = left_tail->next;
                current = next;
                right_tail->next = next;
            }
            else
            {
                current = current->next;
                right_tail = right_tail->next;
            }
        }
        //recursive sort the left part
        if (left->next != head)
            binarySort(left->next, left, left_tail->next);
        //recursive sort the right part
        if (head->next != right)
            binarySort(head->next, head, right);
        return left->next;
    }
    ListNode *sortList(ListNode *head)
    {
        //add a head
        ListNode *left = new ListNode(0);
        left->next = head;
        //递归函数，
        return binarySort(head, left, NULL);
    }
};