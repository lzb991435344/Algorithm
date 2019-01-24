#include <stdio.h>
#include <iostream>

using namespace std;

#define MaxNum 100 //最大元素使用宏定义
typedef int DataType;
struct SeqQueue
{
	DataType arr[MaxNum];//一维数组保存元素
	int f, r;//指向头尾元素的整型值
};
typedef struct SeqQueue* pSeqQueue;

/**
  @common:判队列是否为空
  @param:指向顺序队的指针
  @return:返回1则为空
*/
int isEmptySeqQueue(pSeqQueue psQueue)
{

	return psQueue->f == psQueue->r;
}
/**
@common:创建空顺序队列
@param:void
@return:指向顺序队的指针
*/
pSeqQueue createSeqQueue()
{
	pSeqQueue psQueue = (pSeqQueue)malloc(sizeof(struct SeqQueue));
	if (psQueue == NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	else
	{
		//头和尾置为0
		psQueue->f = 0;
		psQueue->r = 0;
	}
}

/**
@common:入顺序队列
@param:psQueue指向顺序队的指针,x是对应的类型的值
@return:void
*/
/**
使用约定：少用一个元素空间，队头指针在队尾指针的下一个位置为满//求模运算在于使得求模的结果与队头指向的元素的位置相同，这时队列满判别队列满的条件：(psQueue->r +1) % MAXNUM= psQueue->f

//头和尾指向同一个元素即为空
判断队列空的条件:  psQueue->r == psQueue->f
*/

void enSeqQueue(pSeqQueue psQueue , DataType x)
{
	if ((psQueue->r + 1)% MaxNum == psQueue->f)
	{
		printf("full Queue!\n");
    }
	else
	{
		psQueue->arr[psQueue->r] = x;
		psQueue->r = (psQueue->r + 1) % MaxNum;
	}
}


/**
@common:出顺序队列
@param:psQueue指向顺序队的指针
@return:void
*/
void deSeqQueue(pSeqQueue psQueue)
{
	if (psQueue->r == psQueue->f)
	{
		printf("empty queue!\n");
	}
	else
	{
		//队头指针向后移动一个位置
		/** 例子：
		psQueue->f = 1;
		MaxNum = 5;
		psQueue->f=(psQueue->f + 1) % MaxNum = 2;
		执行出队后psQueue->f = 2，指向了下一个元素的位置,
		也就是把队头去掉了
		*/
		psQueue->f = (psQueue->f+1) % MaxNum;
	}
}

/**
@common:取顺序队列元素
@param:psQueue指向顺序队的指针
@return:DataType 元素值
*/
DataType seqQueueFValue(pSeqQueue psQueue)
{
	return  psQueue->arr[psQueue->f];
}

int main()
{
	//创建顺序队列测试
	pSeqQueue psQueue = createSeqQueue();
	enSeqQueue(psQueue, 1);
	enSeqQueue(psQueue, 2);
	enSeqQueue(psQueue, 3);

	//队列判空测试
	printf("%d\n",isEmptySeqQueue(psQueue));

	//出队测试
	deSeqQueue(psQueue);

	//取队头测试
	DataType temp;
	temp = seqQueueFValue(psQueue);
	printf("%d\n", temp);
	getchar();
	system("pause");
	return 0;
}