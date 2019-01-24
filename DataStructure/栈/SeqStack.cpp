#include <iostream>
#include <stdio.h>

using namespace std;

typedef int DataType;
struct SeqStack
{
	int MaxNum;
	int t;
	DataType* s;
};
typedef struct SeqStack* pSeqStack;

/**
 @common:创建空栈
 @param:m为元素的最大数目
 @return:返回指向顺序栈的指针
*/
pSeqStack  createEmptyStack_seq(int m){
	pSeqStack pastack = (pSeqStack)malloc(sizeof(struct SeqStack));
	if (pastack!=NULL)
	{
		pastack->s = (DataType*)malloc(sizeof(DataType)*m);
		if (pastack->s)
		{
			pastack->MaxNum = m;
			pastack->t = -1;
			return pastack;
		}
	}
	printf("out of space!\n");
	return NULL;
}

/**
@common:判是否是空栈
@param:指向顺序栈的指针
@return:空栈返回1
*/
int  isEmptyStack_seq(pSeqStack pastack){
	return pastack->t == -1;
}

/**
@common:入栈
@param:指向顺序栈的指针，x数值
@return:void
*/
void  push_seq(pSeqStack pastack, DataType x){ 	/*检查栈是否满*/	if (pastack->t >= pastack->MaxNum - 1) 		printf("overflow! \n");	else	{		pastack->t = pastack->t + 1;		/*若不满，先修改栈顶变量*/		pastack->s[pastack->t] = x;		/*把元素x放到栈顶变量的位置中*/	}}/**
@common:出栈(删除栈顶元素)
@param:指向顺序栈的指针
@return:void
*/void  pop_seq(pSeqStack pastack){	if (isEmptyStack_seq(pastack))	{		printf("stack is empty()!\n");	}	else	{		pastack->t -= 1;	}}/**
@common:出栈(同时取出栈顶元素)
@param:指向顺序栈的指针
@return:栈顶的值
*/DataType popSeqStack(pSeqStack pastack){	DataType temp;	if (isEmptyStack_seq(pastack))	{		printf("stack is empty()!\n");	}	else	{  		temp = pastack->s[pastack->t];		pastack->t -= 1;	}	return temp;}/**
@common:取栈顶的值
@param:指向顺序栈的指针
@return:DataType
*/DataType  top_seq(pSeqStack pastack){	if (isEmptyStack_seq(pastack))	{		printf("stack is empty()!\n");	}	else	{		return pastack->s[pastack->t];	}}int main(){	pSeqStack pastack = createEmptyStack_seq(3);	push_seq(pastack,1);	push_seq(pastack, 2);	push_seq(pastack, 3);	DataType temp = popSeqStack(pastack);	printf("%d\n",temp);	pop_seq(pastack);	printf("%d", top_seq(pastack));	system("pause");	return 0;}