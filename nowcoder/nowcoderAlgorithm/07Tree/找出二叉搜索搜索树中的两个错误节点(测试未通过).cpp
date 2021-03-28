#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std; 

/**树节点之间的最大距离
 题目：一棵二叉树原本是搜索二叉树，但是其中有两个节点
调换了位置，使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点
并返回他们的值。保证二叉树中结点的值各不相同。给定一棵树的根结点，
请返回两个调换了位置的值，其中小的值在前。

 思路：对于搜索二叉树，总是与中序遍历关联起来的，根据搜索二叉树的特点，
如果一棵树是搜索二叉树，那么当对其进行中序遍历时一定是顺序排列的，本题
中说一棵搜索二叉树中的2个结点交换了位置，而由于已知各个结点各不相同因此
显然对此时的二叉树进行中序遍历时会出现逆序的结点，即某个结点可能比前一个
结点小，这种情况可能出现1次或者2次，例如12345，如果不相邻的元素24交换位置
得到14325，那么显然会出现2次减小的情况，4à3和3à2；如果是相邻的2个元素23交换
位置得到13245，那么只有1次减小的情况，3à2，因此按照中序遍历的顺序遍历当前的二
叉树，每次记录上一个数和当前的数进行比较，如果减小了就是出错的数，记第一次出错
时的较大值（当前值的前面一个值）为number1，较小值（当前值）为number2，然后继续向
下遍历，如果遇到第2次出错的情况，就用较小的值（当前值）替换number2，表示这才是与number1
交换的值，最后显然number1，number2就是交换的2个值，并且number1>number 2，由于要求返回时较
小的值在前面，因此返回number2，number1。可以使用递归也可以不使用递归来解决问题。

总的来说第一个出错的数（大）是第一次减小时前面的数；第二个出错的数（小）是最后一次减小时后面的数。

*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
   TreeNode(int x):val(x), left(NULL), right(NULL){}
};
class findErrorNumberInBinSearchTree
{
public:
	//中序遍历
	void inOrder(TreeNode* root ,vector<int> res)
	{
		if (root == NULL) return;

		inOrder(root->left , res);
		res.push_back(root->val);
		inOrder(root->right , res);
	}

	vector<int>  findErrorNode(TreeNode* root)
	{
		
		vector<int> res;
		inOrder(root , res);
		int pos1 = 0;
		int pos2 = 0;
		int temp = 0;
		for (int i = 1 ; i < res.size() ; i++)
		{
			if (res[i] < res[i - 1] && temp == 0)
			{
				pos1 = i - 1;//返回较大的那个的下标值
				temp++;
			}
			else if (res[i] < res[i-1] && temp == 1)
			{
				pos2 = i;//返回较小那个值的索引
				temp++;
			}
        }
		vector<int> arr;
		if (temp == 1)
		{
		   printf("%d\n",pos1);
		   arr.push_back(res[pos1+1]);//小值
		   arr.push_back(res[pos1]);//大值
		}
		else if (temp==2)
		{
			printf("%d\n", pos1);
			printf("%d\n", pos2);
		   arr.push_back(res[pos2]);//两次出现的小值
		   arr.push_back(res[pos1]);//较大值
		}
		
		return arr;
   }
};
int main()
{

	/**TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->left->left->left = new TreeNode(5);
	root->left->left->left->left = new TreeNode(6);*/

	findErrorNumberInBinSearchTree ft;
	vector<int> arr;
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(9);
	root->right->left = new  TreeNode(18);
	root->right->right = new TreeNode(19);

	printf("6666666666");
	arr = ft.findErrorNode(root);
	printf("7777777");

	for (vector<int>::iterator it=arr.begin();it!=arr.end();it++)
	{
		cout <<*it<< endl;
	}

	getchar();
	system("pause");
	return 0;
}


