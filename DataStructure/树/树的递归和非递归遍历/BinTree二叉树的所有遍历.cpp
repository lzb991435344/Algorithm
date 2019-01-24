#include <iostream>
#include <stdio.h>
#include<queue>
#include <stack>
using  namespace std;

typedef char DataType;
struct BinTreeNode
{
	DataType info;
	BinTreeNode* left;
	BinTreeNode* right;
};
typedef struct BinTreeNode* pBinTreeNode;
typedef struct BinTreeNode* BinTree;

//该结构体用于后续遍历的第二种方法记录是否
//已经访问过该节点，做一个标记
struct Node
{
	pBinTreeNode btNode;//树节点类型
	bool isFirst;//标记值
};
typedef struct Node* pBtNode;
/**
@common:建树
@param:void
@return:指向树节点类型的结构体的指针
*/
pBinTreeNode createBinTree()
{
	int ch;
	pBinTreeNode pNode;
	ch = getchar();
	//递归的出口，当遇到‘#’符号时退出，表明创建树结束
	if (ch == '#')
	{
		pNode = NULL;
	}
	else
	{
		pNode = (pBinTreeNode)malloc(sizeof(struct BinTreeNode));
		if (pNode == NULL)
		{
			printf("out of space!\n");
			return pNode;
		}
		pNode->info = ch;
		//递归调用创建左右子树
		pNode->left = createBinTree();
		pNode->right = createBinTree();
	}
	return pNode;
}

///////递归遍历二叉树--前中后序遍历/////////
/**
@common:递归遍历二叉树（前序）
@param:树根root
@return:void
*/
void preOrderRecursion(BinTree root)
{
	//递归的出口
	if (root == NULL)
	{
		return;
	}
	//前序遍历的顺序
	printf("%c\t", root->info);
	//分别递归左右子树打印值
	preOrderRecursion(root->left);
	preOrderRecursion(root->right);
}
/**
@common:递归遍历二叉树（中序）
@param:树根root
@return:void
*/
void inOrderRecursion(BinTree root)
{
	//递归的出口
	if (root == NULL)
	{
		return;
	}
	//中序遍历的顺序
	//分别递归左右子树打印值
	inOrderRecursion(root->left);
	printf("%c\t", root->info);
	inOrderRecursion(root->right);
}
/**
@common:递归遍历二叉树（中序）
@param:树根root
@return:void
*/

void postOrderRecursion(BinTree root)
{
	//递归的出口
	if (root == NULL)
	{
		return;
	}
	postOrderRecursion(root->left);
	postOrderRecursion(root->right);
	printf("%c\t", root->info);
}
////////////////////////////////////////////

/////////////////////非递归算法遍历///////////////////////
/**
@common:非递归遍历二叉树（前序）--借助栈实现
@param:树根root
@return:void
*/
void preOrderUnRecursion(BinTree root)
{
	BinTree p;//辅助变量
			  //栈中类型为指向结构体的指针
	stack<BinTree> s;
	if (root == NULL)
	{
		return;
	}
	p = root;
	//把根节点压栈
	s.push(root);
	while (!s.empty())
	{
		//先取栈顶，再弹出元素
		p = s.top();
		s.pop();
		if (p != NULL)
		{
			printf("%c\t", p->info);
			//这里先把右子树压栈，因为出栈
			//时对应先根遍历的顺序
			s.push(p->right);
			s.push(p->left);
		}
	}
}

/**
@common:非递归遍历二叉树（中序）--借助栈实现
@param:树根root
@return:void
*/

/**
这里的算法稍微复杂一点点，你用一个例子来把算法流程走一遍
就会发现其实很简单

*/
void inOrderUnRecursion(BinTree root)
{
	//BinTree  p;
	if (root != NULL)
	{
		//栈中的类型存的是指向树节点的结构体的指针
		stack<BinTree> s;
		while (!s.empty() || root != NULL)
		{
			if (root != NULL)
			{
				//先将根节点压栈
				s.push(root);
				//左子树的节点
				root = root->left;
			}
			else
			{
				//取到栈顶元素
				root = s.top();
				//将改元素出栈
				s.pop();
				//打印取到的栈顶元素
				printf("%c\t", root->info);
				//指向右子树
				root = root->right;
			}
		}
	}
}

/**
@common:非递归遍历二叉树（后序）----方法1
@param:树根root
@return:void

  分析：要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，
先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子
或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了 每次取栈顶
元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
*/
void postOrderUnRecursion(BinTree root)
{
	//前一次访问的节点
	BinTree pre = NULL;
	//当前的节点
	BinTree cur;
	stack<BinTree> s;
	//压入根节点
	s.push(root);
	while (!s.empty())
	{
		//取栈顶的元素
		cur = s.top();
		if ((cur->left == NULL&&cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{
            //如果当前结点没有孩子结点或者孩子节点都已被访问过 
			printf("%c\t", cur->info);
			//弹出该节点
			s.pop();
			//当前节点设置为上一次访问的节点
			pre = cur;
		}
		else
		{   //左右子树都不为空的时候，都把它们压栈
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
	}
}

/**
@common:非递归遍历二叉树（后序）----方法2
@param:树根root
@return:void

  分析：对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索
到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将其出栈并访问， 
因此其右孩子还为被访问。所以接下来按照相同的规则对其右子树进行相同的处理，
当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。这样就 
保证了正确的访问顺序。可以看出，在这个过程中，每个结点都两次出现在栈顶，
只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是 
否是第一次出现在栈顶。
*/

void postOrderWithUnRecursion(BinTree root)
{
	stack<pBtNode> s;
	BinTree p = root;
	pBtNode temp;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			//申请标记节点的内存
			pBtNode btn = (pBtNode)malloc(sizeof(struct Node));
			
			btn->btNode = p;
			//标记第一次出现在栈顶
			btn->isFirst = true;
			//该节点入栈
			s.push(btn);
			//进入左子树
			p = p->left;
		}
		if (!s.empty())
		{
			temp = s.top();
			s.pop();
			//表示是第一次出现在栈顶 
			if (temp->isFirst == true)
			{
				temp->isFirst = false;
				s.push(temp);
				p = temp->btNode->right;
			}
			//第二次出现在栈顶 
			else
			{
				printf("%c\t", temp->btNode->info);
				p = NULL;
			}
		}
	}
}
/////////////////////////////////////////////////////////

/**
@common:按层遍历二叉树--辅助数据结构--队列（先进先出）
@param:树根root
@return:void
*/
void levelTravelTree(BinTree root)
{
	queue<BinTree> q;
	BinTree temp;
	if (root != NULL)
	{
		q.push(root);
		while (!q.empty())
		{
			//先取队头的元素
			temp = q.front();
			//弹出队头
			q.pop();
			//打印当前队头的值
			printf("%c\t", temp->info);
			//如果temp是左子树不为空，直接将指向左子树的指针压入队列
			if (temp->left)
			{
				q.push(temp->left);
			}
			//如果temp是右子树，直接将指向右子树的指针压入队列
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}
/**
@common:计算叶子节点数
@param:root 树根节点，x要查找的值
@return:int,叶子节点的数目
*/
int countLeafs(BinTree root)
{
	//递归出口
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	//左子树的叶子节点数+右子树的叶子节点数
	return countLeafs(root->left) + countLeafs(root->right);
}

/**
@common:查找树节点
@param:root 树根节点，x要查找的值
@return:
*/
BinTree searchNode(BinTree root, DataType x)
{
	//递归的出口，找到值即返回
	if (root->info == x)
	{
		return root;
	}
	//递归左子树，寻找值
	if (root->left != NULL)
	{
		return searchNode(root->left, x);
	}
	//递归右子树寻找值
	if (root->right != NULL)
	{
		return searchNode(root->right, x);
	}
	return NULL;
}

//fortest
//测试用例输入 abd##e##cf##g##
//递归建树的时候是先从根开始，用‘#’表示为空(进行二叉树的序列化),
//然后先递归左子树，再递归右子树
int main()
{
	BinTree bTree;
	int count = 0;
	bTree = (BinTree)malloc(sizeof(struct BinTreeNode));
	bTree = createBinTree();

	printf("递归先序遍历结果为：\n");
	preOrderRecursion(bTree);
	printf("\n");

	printf("非递归先序遍历结果为：\n");
	preOrderUnRecursion(bTree);
	printf("\n");

	printf("递归中序遍历结果为：\n");
	inOrderRecursion(bTree);
	printf("\n");

	printf("非递归中序遍历结果为：\n");
	inOrderUnRecursion(bTree);
	printf("\n");

	printf("递归后序序遍历结果为：\n");
	postOrderRecursion(bTree);
	printf("\n");

	printf("非递归后序遍历结果1为：\n");
	postOrderUnRecursion(bTree);
	printf("\n");

	printf("非递归后序遍历结果2为：\n");
	postOrderWithUnRecursion(bTree);
	printf("\n");

	count = countLeafs(bTree);
	printf("叶子节点数为：%d ", count);
	printf("\n");

	printf("按层遍历结果为：\n");
	levelTravelTree(bTree);
	printf("\n");



	getchar();
	system("pause");
	return 0;
}