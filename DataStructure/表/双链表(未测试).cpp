// TrainingCode.cpp: 定义控制台应用程序的入口点。
//
/**
		双链表的实现																
*/
#include <iostream>
using namespace std;

typedef int DataType;
struct DoubleLinkList
{
	DataType info;
	struct DoubleLinkList* prior;
	struct DoubleLinkList* next;
};
typedef struct DoubleLinkList* pDoubleLinkList;

/**
@common:创建双向链表
@param:arr一维数组，数组的大小
@return：指向双向链表的指针
*/
pDoubleLinkList createDoubleLinkList(int* arr , int n)
{
	pDoubleLinkList s, r;
	pDoubleLinkList pdllist = (pDoubleLinkList)malloc(sizeof(struct DoubleLinkList));
	if (pdllist)
	{
	   r = pdllist;
	   pdllist->next = NULL;
	   for (int i= 1 ; i <= n; i++)
	   {
		   s = (pDoubleLinkList)malloc(sizeof(struct DoubleLinkList));
		   s->info = arr[i];
		   r->next = s;
		   s->prior = r;
		   r = s;
	   }
	   r->next = NULL;
	}
	else
	{
		printf("out of space!\n");
		return NULL;
	}
}

/**
@common:寻找指定的节点
@param:指向双向链表的指针,要寻找的指定的值
@return：指向双向链表的指针
*/
pDoubleLinkList findNode(pDoubleLinkList pdllist , int x)
{
	pDoubleLinkList p = pdllist->next;
	while (p)
	{
		if (p->info == x)
		{
			return p;
			break;
		}
		p = p->next;
	}
	return p;
}
/**
@common:寻找指定位置的元素
@param:指向双向链表的指针,要寻找的指定的值的位置
@return：指向双向链表的指针
*/
DataType getElement(pDoubleLinkList pdllist,int i)
{
	int j = 1;
	pDoubleLinkList p = pdllist->next;
	while (p && j<i)
	{
		p = p->next;
		j++;
	}
	if (j > i)
	{
		printf("out of range!\n");
	}
	return p->info;
}

/**
@common:寻找指定元素的前驱--（假如元素有重复呢？）
    ---考虑实现以下寻找特定位置的前驱
@param:指向双向链表的指针,要寻找指定前驱的指定的值x
@return：指向双向链表的指针
*/
pDoubleLinkList getPrevious(pDoubleLinkList pdllist, DataType x)
{
	pDoubleLinkList p = pdllist->next;
	//DataType temp;

	while (p)
	{
		if (p->info == x)
		{
			//返回指向前驱的指针
			return  p->prior; 
			break;
		}
		p = p->next;
	}
	return NULL;
}

/**
@common:寻找指定元素的后继
@param:指向双向链表的指针,要寻找的指定的值的位置
@return：指向双向链表的指针
*/
pDoubleLinkList getPostValue(pDoubleLinkList pdllist , DataType x)
{
	pDoubleLinkList p = pdllist->next;
	while (p)
	{
		if (p->info == x)
		{
			return p->next;
			break;
		}
		p = p->next;
	}
	return NULL;
}

/**
@common:在指定节点之后插入一个节点（也可修改为在指定位置插入，用到上面的接口来寻找前驱和后继）
@param:指向双向链表的指针，待插入节点的前驱，待插入的值
@return：指向双向链表的指针
*/

int insertValue(pDoubleLinkList pdllist , pDoubleLinkList p ,int x)
{
	pDoubleLinkList s; //待插入节点
	s = (pDoubleLinkList)malloc(sizeof(struct DoubleLinkList));
	if (s==NULL)
	{
		printf("out of space!\n");
		return false;
	}
	else
	{
		//插入节点算法
		//1.新节点的后继
		//2.新节点的前驱
		//3.上一个节点的后继
		//4.新节点的下一个节点的前驱
		s->next = p->next;
		s->prior = p;
		p->next = s;
		s->next->prior = s;
	}
	return true;
}

/**
@common:在指定元素值之后删除一个节点(也可在指定位置删除，调用以上实现的接口)
@param:指向双向链表的指针，待插入节点的前驱，待插入的值
@return：指向双向链表的指针
*/
int deleteValue(pDoubleLinkList pdllist, pDoubleLinkList p)
{
	//新建节点用于辅助，指向被删除节点，释放内存
	pDoubleLinkList q = p->next;

	//被删节点上一个节点的后继
	p->next = q->next;

	//被删除节点的下一个节点的前驱
	q->next->prior = p;

	//释放内存
	free(q);
	return true;
}


int main()
{
	
	getchar();
	system("pause");
	return 0;
}

