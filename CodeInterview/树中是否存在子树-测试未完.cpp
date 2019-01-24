#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

/**
CodeInterview:
>输入两颗二叉树A，B，判断B是不是A的子结构。

要查找树A中是否存在和树B结构一样的子树，可以分成两步：
1.第一步在树A中找到和B的根节点的值一样的结点R；
这实际上就是树的遍历。可以用递归实现

递归调用HasSubTree遍历二叉树A。如果发现某一结点的值和树B的头结点的值相同，则转向第2步判断
两个结点为根的数是否存在父子关系

2.第二步再判断树A中以R为根结点的子树是不是包含和树B一样的结构。
这个过程其实就是要要判断两棵树对应的节点数据是否相同。这个是一个递归的过程。

*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};

};

class TreeHasSub
{
public:

	//树是否有孩子节点
	bool doesTreeHasChild(TreeNode* parent , TreeNode* child)
	{
		if (child == NULL )
		{
			return true;
		}
		if (parent == NULL)
		{
			return false;
		}
		if (parent->val != child->val)
		{
			return false;
		}
		else
		{
			//递归左子树和右子树，存在返回1
			return doesTreeHasChild(parent->left, child->left) || doesTreeHasChild(parent->right, child->right);
		}
	}
	//是否存在分支
	bool isHaveChild(TreeNode* parent ,TreeNode* child)
	{
		if (parent == NULL || child == NULL)
		{
			return NULL;
		}
		bool res = true;
		//头节点相同，递归查找
		if (parent->val == child->val)
		{
			res = doesTreeHasChild(parent, child);
		}
		if (res != true)
		{
			//左子树或者右子树中找
			return isHaveChild(parent->left, child) && isHaveChild(parent->right, child);
		}
		else
		{
			return true;
		}
	}

};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);


	TreeNode* root1 = new TreeNode(9);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	
	TreeHasSub ts;
	printf("%d\n", ts.isHaveChild(root, root1));
	system("pause");
	getchar();
	return 0;
}