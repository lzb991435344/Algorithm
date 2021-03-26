/*
题目：
    存在一个升序排列的链表，给head,删除重复的元素
    也有可能是头结点重复

    (1)节点数目在[0,300]
    (2)链表已经升序
*/

#include <iostream>


struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //普通方法
    ListNode* deleteDuplicateElement(ListNode *head){
        if (!head || !head->next){
            return head;
        }
        //使用三个指针，a,b,c,当b为NULL时，结束循环
        ListNode* a = head;
        ListNode* b = head->next;
        while(b) {
            ListNode* c = b->next;
            if (a->val == b->val){
                a->next = b->next;
                delete b;
            }else{
                a->next = b;
                a = b;
            }
            b = c;
        }
        a->next = NULL; //尾部节点
        return head;
    }

    //递归
    ListNode* deleteDuplicates(ListNode* head){
        if (!head || !head->next){
            return head;
        }
        ListNode* newHead = deleteDuplicates(head->next);
        if(head->val == newHead->val){
            head->next = NULL;
            return newHead;
        }else{
            head->next = newHead;
            return head;
        }
    }

    ListNode* createLinkListHead(){

        ListNode* head = NULL;

        head = (ListNode*)malloc(sizeof(ListNode*));
        if (head == NULL){
            std::cout<< "malloc error" <<std::endl;
            return NULL;
        }
        return head;
    }
    ListNode* insertLinkListFromHead(int val){
        ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
        if (p == NULL){
            std::cout<< "malloc error" <<std::endl;
            return NULL;
        }
        
    }

    ListNode* insertLinkListFromTail(int val){
        ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
        if (p == NULL){
            std::cout<< "malloc error" <<std::endl;
            return NULL;
        }
        
    }

private:
};

int main(){
    Solution s;
    ListNode* tt = NULL;
}