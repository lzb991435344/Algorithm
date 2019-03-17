#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std; 

/**树节点之间的最大距离
  题目：有一棵二叉树，其中所有节点的值都不一样,找到含有节点最多
的搜索二叉子树,并返回这棵子树的头节点.给定二叉树的头结点root，请返
回所求的头结点,若出现多个节点最多的子树，返回头结点权值最大的。

*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
   TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class  MaxSubTree
{
public:
	int max(int a , int b)
	{
		return  a > b ? a : b;
	}

	int min(int a ,int b)
	{
		return a < b ? a : b;
	}
	//寻找最大的节点
	TreeNode* maxSearchNode(TreeNode* root , int& maxNode ,int& minNode ,int& totalNode )
	{
		if (root == NULL)
		{
			maxNode = -9999;
			minNode = 9999;
			totalNode = 0;
			return NULL;
		}		
		int lmax, lmin, lnumber;
		int rmax, rmin, rnumber;
		TreeNode* lnode = maxSearchNode(root,lmax,lmin,lnumber);
		TreeNode* rnode = maxSearchNode(root,rmax,rmin,rnumber);

		//更新最大值节点和最小值节点
		maxNode = max(rmax,root->val);
		minNode = min(lmin,root->val);

		if (lmax < root->val && rmin > root->val && lnode == root->left && rnode == root->right)
		{
			totalNode = lnumber + rnumber + 1;
			return root;
		}
		//比较左右两边的数量，返回数量较大的树节点的头结点
		if (lnumber > rnumber)
		{
			totalNode = lnumber;
			return lnode;
		}
		else
		{
			totalNode = rnumber;
			return rnode;
		}
	}
	//获取搜索二叉树的开始节点
	TreeNode* getMax(TreeNode* root)
	{
		int max, min, num;
		return maxSearchNode(root,max,min,num);
	}
};

int main()
{
	MaxSubTree ft;
	vector<int> arr;
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(5);
	root->right = new TreeNode(18);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(9);
	root->right->left = new  TreeNode(15);
	root->right->right = new TreeNode(19);

	TreeNode* node = ft.getMax(root);
	printf("%d\n",node->val);
	getchar();
	system("pause");
	return 0;
}


