#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：判断是否是平衡二叉树
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};
class checkBalance
{
public:
	bool check(TreeNode* root)
	{
		return chk(root) >= 0;
	}

	int chk(TreeNode* root)
	{
		if (root==NULL)
		{
			return 0;
     	}
		//左右子树的高度
		int lh = chk(root->left);
		int rh = chk(root->right);

		if (lh<0 || rh<0)
		{
			return -1;
		}
		//左右子树的高度差<=1
		if (abs(lh-rh)>1)
		{
			return -1;
		}
		return lh > rh ? lh + 1 : rh + 1;
	}
};


int main()
{
	checkBalance cb;
	TreeNode*root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	printf("%d\n",cb.chk(root));
	printf("%d\n",cb.check(root));
	system("pause");
	getchar();
	return 0;
}