#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
>输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
>假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

输入
>前序遍历序列{1,2,4,7,3,5,6,8}
>
>中序遍历序列{4,7,2,1,5,3,8,6}

>输出
则重建二叉树并返回。
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}

};
class reBuildBinTree
{
public:
	//按层打印二叉树--借助队列
	vector<vector<int> > printTree(TreeNode* root) {
		vector< vector<int> > v;
		vector<int> v1;

		queue<TreeNode *> q;
		//压入根节点
		q.push(root);

		TreeNode *last = NULL;
		TreeNode *nlast = NULL;
		last = root;
		while (!q.empty())
		{
			//使用temp指向队列中的头结点
			TreeNode *temp = q.front();
			//弹出节点
			q.pop();
			//v1用于保存当前值
			v1.push_back(temp->val);
			// 把当前节点左节点加入队列中 注意队列是先进先出
			//的数据结构 这里打印的要求是从左到右 所以要注意
			//左右节点加入队列的顺
			//nlast指向当前的temp的左子树
			if (temp->left != NULL)
			{
				q.push(temp->left);
				nlast = temp->left;
			}
			//nlast指向当前的右子树
			// 把当前节点右节点加入队列中
			if (temp->right != NULL)
			{
				q.push(temp->right);
				nlast = temp->right;
			}
			//队头元素等于根元素
			// 到了一行的末尾
			if (temp == last)
			{
				v.push_back(v1);
				v1.clear();
				last = nlast;
			}
		}
		return v;
	}
     //重建二叉树
	struct TreeNode* reConstructTree(vector<int> pre , vector<int> in)
	{
		int len = pre.size();
		if (len == 0)
		{
			return NULL;
		}
		if (pre.size() != in.size())
		{
			return NULL;
		}
		int value = pre[0];//前序遍历的第一个节点是root
        int size = pre.size();
		TreeNode* root = new TreeNode(value);
		//cout <<"The root is:"<< value << endl;
		int rootindex;
		//在中序遍历中找到root的值，以此为分界线，分别是左子树和右子树
		//找到当前索引的下标值(计算左右子树的长度)
		for ( rootindex = 0 ; rootindex < size ; rootindex++)
		{
			if (in[rootindex] == value)
			{
				break;
			}
		}
		//对当前的索引值做判断
		if (rootindex >=size)
		{
			return NULL;
		}
		
		//左子树的长度
		int leftLength = rootindex;
		//右子树的长度
		int rightLength = size - 1 - rootindex;
		//静态分配vector,节省空间
		vector<int> preLeft(leftLength), inLeft(leftLength);
		vector<int>  preRight(rightLength), inRight(rightLength);

		for (int i = 0 ; i < size ; i++)
		{
			if(i < rootindex )
			{
				preLeft[i] = pre[i+1]; //前序遍历的第i+1 =< x < rootindex是左子树 
				inLeft[i] = in[i];    //rootindex之前都是左子树
			}
			else if (i > rootindex )
			{
				preRight[i - 1 - rootindex] = pre[i];//大于rootindex的数组值都是右子树
				inRight[i - 1 - rootindex] = in[i];//in中大于rootindex右子树
			}
		}	
		//递归重建树
		root->left = reConstructTree(preLeft , inLeft);
		root->right = reConstructTree(preRight , inRight);
		return root;
	}
};

int main()
{
	vector<vector<int>> res;
	reBuildBinTree rb;
	vector<int> pre = {1,2,4,5,3,6};
	vector<int> in = {4,2,5,1,3,6};
	struct TreeNode* root= rb.reConstructTree(pre , in);
	res=rb.printTree(root);
	for (int i=0 ; i < res.size() ; i++ )
	{
		for (int j = 0 ; j < res[i].size() ; j++ )
		{
			printf("%d\t", res[i][j]);
		}
	}
	system("pause");
	getchar();
	return 0;
}