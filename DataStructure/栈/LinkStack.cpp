// LinkStack.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdio.h>
using namespace std;

typedef int DataType;
struct  Node;
typedef struct Node* pNode;/*指向结点的指针类型*/
struct  Node	/* 单链表结点结构 */
{
	DataType  info;
	struct Node  *link;
};
struct LinkStack	/* 链接栈类型定义 */
{
	pNode  top;	/* 指向栈顶结点 */
};
typedef struct LinkStack* pLinkStack;

/**
@common:新建空栈
@param:void
@return: 指向链栈的指针
*/

pLinkStack  createEmptyStack_link(void)
{
	//分配内存
	pLinkStack plstack = (pLinkStack)malloc(sizeof(struct LinkStack));
	//将栈顶指针指向空，表明是空栈
	if (plstack != NULL)
	{
		plstack->top = NULL;
	}
	else
	{
		printf("out of space!\n");
	}
	//返回指向该链栈的指针
	return plstack;
}

/**
@common:判断栈是否为空
@param:plstack指向链栈的指针
@return: bool值
*/
int  isEmptyStack_link(pLinkStack plstack)
{
	//返回栈顶是否为空
	return plstack->top == NULL;
}

/**
@common:压栈
@param:plstack指向链栈的指针，数据类型
@return:void
*/
void push_link(pLinkStack plstack, DataType x)
{
	//初始化节点类型
	pNode   p;
	//分配空间
	p = (pNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("Out of space!\n");
	else
	{
		p->info = x;
		//栈顶指针作为p的下一个的值
		p->link = plstack->top;
		//调整栈顶指针
		plstack->top = p;
	}
}
/**
@common:出栈，同时取到出栈元素的值
@param:plstack指向链栈的指针
@return:DataType类型
*/
DataType pop_link(pLinkStack plstack)
{
	pNode   p;//辅助节点，用于取到栈顶元素的值
	DataType  elem;//存栈顶元素值
	if (isEmptyStack_link(plstack))
		printf("Empty stack pop.\n");
	else
	{
		//出栈：pop出栈顶元素
		//栈顶指针先指向p节点
		p = plstack->top;
		//元素赋值
		elem = p->info;
		//修改栈顶指针的位置：指向原栈顶指针的下一个
		plstack->top = plstack->top->link;
		//释放内存
		free(p);
	}
	//返回元素的值
	return elem;

}
/**
@common:取出栈顶元素的值
@param:plstack指向链栈的指针
@return:DataType类型
*/
DataType  top_link(pLinkStack plstack)
{
	//返回栈顶的元素
	return  plstack->top->info;
}

int main()
{
	//建栈测试
	pLinkStack plstack= createEmptyStack_link();
	//压栈测试
	push_link(plstack,1);
	push_link(plstack, 2);
	push_link(plstack, 3);

	//判断栈是否为空测试
	printf("%d\n", isEmptyStack_link(plstack));

	//出栈测试
	DataType temp = pop_link(plstack);
	printf("%d\n",temp);

	//取栈顶元素测试
	temp = top_link(plstack);
	printf("%d\n", temp);

	getchar();
	system("pasuse");
	return 0;
}

