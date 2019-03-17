/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/**
题目
有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够
K个节点一组，则不调整最后几个节点。例如链表1->2->3->4->5->6->7->8->null，
K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。因为K==3，
所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。 
给定一个单链表的头指针head,同时给定K值，返回逆序后的链表的头指针。
*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        
        ListNode *p=head;
        int i,j;
		//检测是否长度符合条件
        for( i=0;i<k;i++)//先检测一下整个链表如果不够k就可以直接返回了
        {
            if(p==NULL)
            {
				//返回头指针
                return head;
            }
            p=p->next;
        }
         
        int count=0;
        p=head;
		
		//计算链表的长度count
        while(p!=NULL)
        {
            p=p->next;
            count++;
        }
        //这部分是重点 你必须画图去理解 才知道这个指针连接的过程
        ListNode *node=new ListNode(0);
		node->next=head;
        ListNode *pre=node;
        ListNode *cur=head;
        ListNode *temp=head->next;
         
        for(i=0;i<count/k;i++)//总共需要反转的次数
        {
			//好乱啊，乱啊，啊,,,,,,,,,,,,,
            for(j=0;j<k-1;j++)//反转过程
            {
                cur->next=temp->next;
                temp->next=pre->next;
                pre->next=temp;
                temp=cur->next;
            }
			//下一个需要调整的指针位置
            pre=cur;
            cur=cur->next;
            temp=cur->next;
        }
        //返回头指针
        return node->next;
    }
 
};