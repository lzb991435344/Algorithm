#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  顺序表实现
*/
typedef int DataType;
struct SeqList
{
	int MaxNum;//最大的元素个数
	int n; //元素的个数
	DataType* element;//一维数组，存放元素
};

typedef struct SeqList* pSeqList;

/**
@common:创建空的顺序表
@param：顺序表中的最大元素个数
@return: 指向顺序表的指针
*/
pSeqList createNULLSeqList(int m)
{
	pSeqList palist = (pSeqList)malloc(sizeof(struct SeqList)*m);
	if (palist != NULL)
	{
		palist->element = (DataType*)malloc(sizeof(DataType)*m);
		if (palist->element)
		{
			palist->MaxNum = m;
			palist->n = 0;
			return palist;
		}
	}
	printf("Out of space!\n");
	return NULL;
}

/**
@common:创建顺序表
@param：arr存放顺序表元素的一维数组，arr的大小
@return: 指向顺序表的指针
*/
//pSeqList createSeqList(int arr[],int n)
pSeqList createSeqList(pSeqList palist)
{	int n, i, x;
	//pSeqList palist = (pSeqList)malloc(sizeof(struct SeqList));
	if (palist ==  NULL)
	{
		printf("out of space!\n");
	}
	else
	{
	
		/**for (int i = 0 ; i < n ; i++)
		{
			palist->element[i] = arr[i];
		}*/
		scanf_s("%d", &n);
		for (i = 0 ; i <= n-1 ; i++)
		{
			scanf_s("%d",&x);
			palist->element[i] = x;
		}
		palist->n = n;
	}
	return palist;
}

/**
@common:在palist所指顺序表中下标为p的元素之前插入元素x
@param：palist指向顺序表的指针，插入位置，插入元素的值
@return: true（1）则成功，false（0）失败
@时间复杂度：O(N)
*/
int insertPreSeqList(pSeqList palist , int p , DataType x)
{
	int q;//该变量为辅助变量，用于寻找正确的插入位置
	//数据溢出
	if (palist->n ==palist->MaxNum -1)
	{
		printf("overflow\n");
		return false;
	}
	//位置不合理
	if (p<0 || p>palist->MaxNum-1)
	{
		printf("Not Exist!\n");
		return false;
	}
	//循环用于把当前p位置及p之后的元素向后移动一个位置
	for (q = palist->n -1 ; q >= p ; q--)
	{
		palist->element[q + 1] = palist->element[q];
	}
	//赋值
	palist->element[p] = x;
	//元素的值+1
	palist->n += 1;
	return true;
}

/**
@common:在palist所指顺序表中删除下标为p的元素
@param：palist指向顺序表的指针，插入位置，插入元素的值
@return: true（1）则成功，false（0）失败
*/

int deleteValueFromSeqList(pSeqList palist , int p)
{
	int q;//辅助变量，便于帮助移动元素
	//位置不合理
	if (p < 0 || p > palist->n -1)
	{
		printf("Not exist!\n");
		return 0;
	}
	//删除元素后q之后的元素都向前移动一个位置
	for (q = p ; q < palist->n - 1 ; q++)
	{
		palist->element[q] = palist->element[q+1];
	}
	//元素个数-1
	palist->n -= 1;
	return 1;
}

/**
@common:求ｘ在palist所指顺序表中的下标位置
@param：palist指向顺序表的指针，插入元素的值
@return: 成功返回元素值的下标，否则返回0
*/
int locateValueSeqList(pSeqList palist , DataType x)
{
	int q;
	for (q = 0 ; q < palist-> n ;q++)
	{
		if (palist->element[q] == x)
		{
			return q;
		}
	}
	return -1;
}

/**
@common:在palist所指顺序表中的第p个位置的元素值
@param：palist指向顺序表的指针，插入元素的值
@return: 成功返回元素值，否则返回一个特别的字符串
*/
DataType locatePValue(pSeqList palist , int p)
{
	//检查位置合理性
	if (p > 0 && p < palist->n -1)
	{
		//元素的下标值为p-1,元素值排列为0...N-1
		return palist->element[p-1];
	}
	return '#';
}
/**
@common:打印顺序表的值
@param：
@return: 
*/

void printSeqList(pSeqList palist)
{
	if (palist != NULL)
	{
		for (int i=0 ; i <= palist->n -1 ; i++)
		{
			printf("%d\t",palist->element[i]);
		}
    }
}
//for test
int main()
{
	int arr[5] = {1,2,3,4,5};
	//创建顺序表测试
	pSeqList palist =  createNULLSeqList(5);
	createSeqList(palist);
	printSeqList(palist);

	//插入测试
	printf("%d\n", insertPreSeqList(palist, 2, 6));
	printSeqList(palist);

	//删除测试
	printf("%d\n", deleteValueFromSeqList(palist, 2));
	printSeqList(palist);

	//查找测试
	printf("%d\n",locateValueSeqList( palist,5)); 

	system("pause");
	getchar();
	return 0;
}