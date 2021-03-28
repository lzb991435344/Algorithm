#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**

完全二叉树节点计数
	
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//计算完全二叉树的节点的数目
int count(TreeNode* root)
{
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode* temp = root;

	int l_node = 0;
	int r_node = 0;

	while (temp->left != NULL || temp->right != NULL)
	{
		l_node = 0;
		r_node = 0;
		int res = 1;
		left = temp->left;

		while (left != NULL)
		{
			l_node++;
			left = left->left;
		}
		right = temp->right;
		while (right != NULL)
		{
			r_node++;
			right = right->right;
		}
		// 比较两个头节点的深度 若一样说明左子树是一颗满二叉树 
		{
			if (l_node == r_node)
			{
				res += pow(2, l_node);
				temp = temp->right;
			}
			// 比较两个头节点的深度 若不一样说明右子树是一颗满二叉树 
			else
			{
				res += pow(2, r_node);
				temp = temp->left;
			}
		}
		return res;
	}
}

int main()
{
	
	getchar();
	return 0;
}