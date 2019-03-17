#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std; 

/**树节点之间的最大距离
  从二叉树的节点A出发，可以向上或者向下走，但沿途的节点只能
经过一次，当到达节点B时，路径上的节点数叫作A到B的距离。对于给
定的一棵二叉树，求整棵树上节点间的最大距离。给定一个二叉树的头
结点root，请返回最大距离。保证点数大于等于2小于等于500.

分析：情况1：完全来自root的左子树，如图所示，即最大路径不经过root结点，只在结点1的左子树2上面，
  此时的最大距离为8。
情况2：完全来自root结点的右子树，如图所示，最大路径不经过root结点，只在结点1的右侧左子树3上面，
 此时最大距离是9。
情况3：来自结点root的两侧，如图所示，经过root结点，此时的最大距离=root的左子树的高度（即结点3的
 最长路径）+root右子树的高度（即结点3的最长路径）+root结点本身。


 查看递归的结果
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
   TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class lonestDistance
{
public:
	int max(int a , int b)
	{
		return a > b ? a : b;
    }

	int getmaxHeight(TreeNode* root , int &maxDistance)
	{
		if (root == NULL)//根节点为空时，直接返回0
		{
			return 0;
		}
		//这里分别获得左子树和右子树的最大高度
		int lh = getmaxHeight(root->left ,maxDistance);
		printf("*%d\t", lh);
		printf("\n");
		int rh = getmaxHeight(root->right ,maxDistance);
		printf("#%d\t",rh);
		maxDistance = lh + rh + 1;
		return max(lh , rh)+1;
	}

	int longestDistance(TreeNode* root)
	{
		int lmax = 0;
		int rmax = 0;
		int lres = getmaxHeight(root->left,lmax);
		int rres = getmaxHeight(root->right,rmax);
		 
		return max(lres + rmax + 1 , max(lmax , rmax));
	}
};

int main()
{

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->left->left->left = new TreeNode(5);
	root->left->left->left->left = new TreeNode(6);

	lonestDistance ld;
	printf("%d\n",ld.longestDistance(root));
	getchar();
	system("pause");
	return 0;
}


