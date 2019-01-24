// LinkQueue.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdio.h>
using namespace std;

//定义数据类型为int型
typedef int DataType;
struct Node;
//重命名结构体Node的名字，pNode是指向该结构的指针
typedef struct Node* pNode;
//链队节点类型
struct Node
{
	DataType info;
	struct Node* link;
};
struct LinkQueue
{
	pNode f;//头指针
	pNode r;//尾指针
};
typedef struct LinkQueue* pLinkQueue;

/**
@common:新建空链队
@param:void
@return: 指向链队的指针
*/

pLinkQueue createEmptyLinkQueue()
{
	pLinkQueue plQueue = (pLinkQueue)malloc(sizeof(struct LinkQueue));
	if (plQueue != NULL)
	{
		//空队列两个指针都指向空
		plQueue->f = NULL;
		plQueue->r = NULL;
	}
	else
	{
		printf("out of space!\n");
	}
	return plQueue;
}

/**
@common:判链队是否为空
@param:指向链队的指针
@return: 空返回1，否则返回0
*/
int  isEmptyQueue_link(pLinkQueue plQueue)
{
	return (plQueue->f == NULL);
}

/**
@common:入队(分两种情况，空队和非空队)
@param:plQueue指向链队的指针，DataType数据类型
@return: void
*/
void enLinkQueue(pLinkQueue plQueue, DataType x)
{
	pNode p;
	//分配节点内存
	p = (pNode)malloc(sizeof(struct Node));
	if (p == NULL)
	{
		printf("out of space!\n");
	}
	else
	{
		//赋值
		p->info = x;
		p->link = NULL;
		//空队：队中无节点
		if (plQueue->f == NULL)
		{
			//当前队列的头指针和尾指针都指向新加入的节点
			plQueue->f = p;
			plQueue->r = p;
		}
		//非空队：队中存在节点
		else
		{
			//将p节点连接到尾指针的下一个节点
			plQueue->r->link = p;
			//修改尾指针指向
			plQueue->r = p;
		}

	}
}
/**
@common:出队(队头出队，修改的是头指针)
@param:plQueue指向链队的指针
@return: void
*/

void  deQueue_link(pLinkQueue plQueue)
{
	//辅助节点，不用分配内存空间，最后用于free掉队头的指针
	struct Node  * p;
	if (plQueue->f == NULL)
	{
		printf("empty queue.\n ");
	}
	else
	{
		//p先指向队头的指针
		p = plQueue->f;
		//队头指针指向下一个
		plQueue->f = plQueue->f->link;
		free(p);
	}
}

/**
@common:读取队头的元素
@param:plQueue指向链队的指针
@return: DataType
*/
DataType queueFValue(pLinkQueue plQueue)
{
	return plQueue->f->info;
}

int main()
{
	pLinkQueue plQueue = createEmptyLinkQueue();
	enLinkQueue(plQueue, 1);
	enLinkQueue(plQueue, 3);
	enLinkQueue(plQueue, 5);

	printf("%d\n", isEmptyQueue_link(plQueue));

	deQueue_link(plQueue);
	DataType temp;
	temp = queueFValue(plQueue);

	printf("%d\n", temp);
	getchar();
	system("pasuse");
	return 0;
}

