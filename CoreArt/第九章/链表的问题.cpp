/**
第一节、求链表倒数第k个结点
第13题、题目描述：
输入一个单向链表，输出该链表中倒数第k个结点,
链表的倒数第0个结点为链表的尾指针。
*/
//设置两个指针p1,p2，首先p1和p2都指向head，然后p2向前走k步，这样p1和p2之间就间隔k个节点，
//最后p1和p2同时向前移动，直至p2走到链表末尾。

#include <iostream>
#include  <stdio.h>
using namespace std;
struct ListNode
{
 char data;
 ListNode* next;
};

ListNode* head;
ListNode* pone;
ListNode* ptwo;

//倒数第K个节点
ListNode* function(ListNode* head,int k)
{
	assert(k>=0);
	pone=ptwo=head;
	for(;k>0 && ptwo!=NULL;k--)
	{
		ptwo=ptwo->next;
		if(k>0)
		{
			return NULL;
		}
	}
	while(ptwo!=NULL)
	{
		pone=pone->next;
		ptwo=ptwo->next;
	}
	return pone;
}

/**
判断两个链表是否相交
1.直接循环判断第一个链表的每个节点是否在第二个链表中。但，这种方法的时间复杂度为O(Length(h1) * Length(h2))。
 显然，我们得找到一种更为有效的方法，至少不能是O（N^2）的复杂度。
2.针对第一个链表直接构造hash表，然后查询hash表，判断第二个链表的每个结点是否在hash表出现，如果所有的
第二个链表的结点都能在hash表中找到，即说明第二个链表与第一个链表有相同的结点。时间复杂度为为线性：
O(Length(h1) + Length(h2))，同时为了存储第一个链表的所有节点，空间复杂度为O(Length(h1))。
3.进一步考虑“如果两个没有环的链表相交于某一节点，那么在这个节点之后的所有节点都是两个链表共有的”这个特点，
我们可以知道，如果它们相交，则最后一个节点一定是共有的。而我们很容易能得到链表的最后一个节点，所以这成了
我们简化解法的主要突破口。那么，我们只要判断俩个链表的尾指针是否相等。相等，则链表相交；否则，链表不相交。
所以，先遍历第一个链表，记住最后一个节点。然后遍历第二个链表，到最后一个节点时和第一个链表的最后一个节点
做比较，如果相同，则相交，否则，不相交。这样我们就得到了一个时间复杂度，它为O((Length(h1) + Length(h2))，
而且只用了一个额外的指针来存储最后一个节点。这个方法时间复杂度为线性O（N），空间复杂度为O（1），显然比解法
三更胜一筹。
4.上面的问题都是针对链表无环的，那么如果现在，链表是有环的呢?还能找到最后一个结点进行判断么?上面的方法还同样有效么?显然，这个问题的本质已经转化为判断链表是否有环。那么，如何来判断链表是否有环呢?
总结：
所以，事实上，这个判断两个链表是否相交的问题就转化成了：
1.先判断带不带环
2.如果都不带环，就判断尾节点是否相等
3.如果都带环，判断一链表上俩指针相遇的那个节点，在不在另一条链表上。
如果在，则相交，如果不在，则不相交。
*/

//1.先判断带不带环
//判断是否有环，返回bool，如果有环，返回环里的节点
//思路：用两个指针，一个指针步长为1，一个指针步长为2，判断链表是否有环
bool isCircle(ListNode* head,ListNode*& circleNode,ListNode*& lastNode)
{
	ListNode *fast=head->next;
	ListNode * slow=head;
	//快慢指针一直走到链表尾部
	while(fast && slow && fast!=slow)
	{
		if(fast->next!=NULL)
			fast=fast->next;
		//快指针先走到链表尾部则先赋值
		if(fast->next==NULL) lastNode=fast;
		if(slow->next==NULL) lastNode=slow;
		fast=fast->next;
		slow=slow->next;
	}
	//快慢两个指针相等，且存在，相交的节点就是fast指针指向的节点
	if(fast==slow && fast&& slow)
	{
		circleNode=fast;
		return true;
	}else 
	{
		return false;
	
	}
}
//如果都不带环，就判断尾节点是否相等，如果都带环，判断一链表上俩指针相遇的那个节点，在不在另一条链表上。

//判断带环不带环时链表是否相交
//2.如果都不带环，就判断尾节点是否相等
//3.如果都带环，判断一链表上俩指针相遇的那个节点，在不在另一条链表上。
bool detect(ListNode*head1,ListNode*head2)
{
	ListNode* circliNode1;
	ListNode* circliNode2;
	ListNode* lastNode1;
	ListNode* lastNode2;

	bool circle1=isCircle(head1,circliNode1,lastNode1);
	bool circle2=isCircle(head2,circliNode2,lastNode2);

	//一个有环，一个无环
	if(circle1!=circle2)
	{
		return false;
	}//两个都无环,判断尾节点是否相等
	else if(！circle1 && !circle2)
	{
		return lastNode1=lastNode2;
	}
	//两个都有环，判断环里的节点是否能到达另一个链表环里的节点
	else
	{
		ListNode* temp=circliNode1->next;
		while(temp!=circliNode1)
		{
			if(temp=circliNode2)
			{
				return true;
			}
			temp=temp->next;
		}
		return false;
	}
	return false;
}

//求两个链表相交的第一个节点
//思路：在判断是否相交的过程中要分别遍历两个链表，同时记录下各自长度。
/**
这个算法需要处理一种特殊情况，即：其中一个链表的头结点在另一个链表的环中，且不是环入口结点。
这种情况有两种意思：
1)如果其中一个链表是循环链表，则另一个链表必为循环链表，即两个链表重合但头结点不同；
2)如果其中一个链表存在环(除去循环链表这种情况)，则另一个链表必在此环中与此环重合，
其头结点为环中的一个结点，但不是入口结点。在这种情况下我们约定，如果链表B的头结点在链表A的环中，
且不是环入口结点，那么链表B的头结点即作为A和B的第一个相交结点；如果A和B重合(定义方法时形参A在B之前)，
则取B的头结点作为A和B的第一个相交结点。

*/
ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2)
{
	// Get the length of two lists
	unsigned int nLength1 = ListLength(pHead1);
	unsigned int nLength2 = ListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;

	// Get the longer list
	ListNode *pListHeadLong = pHead1;
	ListNode *pListHeadShort = pHead2;
	if(nLength2 > nLength1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	// Move on the longer list
	for(int i = 0; i < nLengthDif; ++ i)
		pListHeadLong = pListHeadLong->m_pNext;

	// Move on both lists
	while((pListHeadLong != NULL) && (pListHeadShort != NULL) && (pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	// Get the first common node in two lists
	ListNode *pFisrtCommonNode = NULL;
	if(pListHeadLong == pListHeadShort)
		pFisrtCommonNode = pListHeadLong;

	return pFisrtCommonNode;
}

unsigned int ListLength(ListNode* pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while(pNode != NULL)
	{
		++ nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}