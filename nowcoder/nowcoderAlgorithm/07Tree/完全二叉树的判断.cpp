#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

/**题目：判断是否是完全二叉树
  就是在一个二叉树中找到最后一个非叶子节点，当这个结点左孩子存在、
右孩子不存在或者左右孩子都不存在的时候，这个二叉树就是一个完全
二叉树，否则就不是一个完全二叉树。
判断的过程：
1.树空，不是完全二叉树。
2.树只有根节点，就是一个完全二叉树。
3.先将根节点入队列
  当一个节点的左右孩子都存在的时候，就让这个节点的左右孩子入队列
，并且让这个节点出队列，左孩子不存在、右孩子存在直接返回，
左孩子存在、右孩子不存在或者左右孩子都不存在，就让这个节点出
队列，这时，如果队列中的所有节点都没有左右孩子，那么这就是一个
完全二叉树。			
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};
class checkComplete
{
public:
	bool chk(TreeNode* root)
	{
		queue<TreeNode*> s;
		s.push(root);
		bool res = true;
		bool isleaf = false;
		while (!s.empty())
		{
			TreeNode*temp = s.front();
			s.pop();
			//标志位true的时候，开始判断当前节点是不是叶子节点
			if (isleaf)
			{
				//当前节点的左右子树都不是叶子节点
				if (!(temp->left == NULL &&temp->right == NULL))
				{
					res = false;
					break;
				}

				//有右孩子，没有左孩子，不符合完全二叉树的定义
				if (temp->left==NULL && temp->right!=NULL)
				{
					res = false;
					break;
				}	
				//左右子树都不为空
				else if (temp->left!=NULL&&temp->right!=NULL)
				{
					s.push(temp->left);
					s.push(temp->right);
				}
				//不同时存在左右孩子节点，要求之后的节点都要是叶子节点
				else
				{
					isleaf = true;
					if (temp->left != NULL)
					{
						s.push(temp->left);
					}
					if (temp->right!=NULL)
					{
						s.push(temp->right);
					}
				}
			}
		}
		return res;
	}		
};


int main()
{
	checkComplete cc;
	TreeNode*root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(5);
	printf("%d\n",cc.chk(root));	
	system("pause");
	getchar();
	return 0;
}