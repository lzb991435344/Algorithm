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
 操作给定的二叉树，将其变换为源二叉树的镜像。

**输入描述**

二叉树的镜像定义：源二叉树
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		镜像二叉树
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7  5
*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};

};

class MirrorTree
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

	//通过层遍历实现镜树的实现
	void mirrorLevel(TreeNode * root)
	{
		if (root == NULL)
		{
			return;
		}
		swap(root->left , root->right);
		mirrorLevel(root->left);
		mirrorLevel(root->right);
	}

	//前序遍历
	void mirrorPre(TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		//不压入根节点
		TreeNode* node = root;
		stack<TreeNode*> s;
		while (node != NULL || !s.empty())
		{
			while (node !=  NULL)
			{
				if (node->left != NULL)
				{
					swap(node->left, node->right);
				}
				s.push(node);
				node = node->left;
			}
			if (!s.empty())
			{
				node = s.top();
				s.pop();
				node = node->right;
			}

		}
	}
	//按照广度优先遍历
	void mirrorPreBfs(TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* temp = root;
		while (!s.empty())
		{
		    temp = s.top();
			s.pop();
			//左右子树不为空的时候交换左右子树
			if (temp->left != NULL || temp->right != NULL )
			{
				swap(temp->left , temp->right);
			}
			//左子树入栈
			if (temp->left != NULL)
			{
				s.push(temp->left);
			}
			//右子树入栈
			if (temp->right != NULL)
			{
				s.push(temp->right);
			}
		}		 
	}
	//中序遍历
	void mirrorIn(TreeNode* root)
	{
		if(root == NULL)
		{
			return ;
		}
		stack<TreeNode*> s;
		TreeNode* temp = root;
		while (temp != NULL || !s.empty() )
		{
			//先找到最左的元素
			while (temp != NULL)
			{
				//左子树全部压栈
				s.push(temp);
				temp = temp->left;
			}
			//这里全部转换到左子树来进行交换节点，交换节点之后
			//继续将左子树的节点全部压栈，交换值，即可完成
			if (!s.empty())
			{
				//从底部进行递归，一直到根节点
				temp = s.top();
				//左右子树不为空，交换值
				if (temp ->left != NULL || temp->right != NULL)
				{
					swap(temp->left ,temp->right);
				}
				s.pop();
				//指向当前节点的左子树
				temp = temp->left;
			}
		}
	}
	//后序遍历实现
	void mirrorPost(TreeNode* root)
	{
		if (root == NULL)
		{
			return ;
		}
		TreeNode* curr = NULL;//当前访问的节点
		TreeNode* pre = NULL;//前一个访问的节点
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			curr = s.top();//取栈顶

			if ((curr->left == NULL && curr->right == NULL) || 
				((pre != NULL) &&((pre == curr->left) || (pre == curr->right))))
			{
				//左右子树不为空，交换左右子树
				if (curr->left != NULL || curr->right != NULL)
				{
					swap(curr->left ,curr->right);
				}
				s.pop();
				//设置当前访问的节点
				pre = curr;
			}
			else
			{
				//左右子树不为空压栈
				if (curr->left != NULL)
				{
					s.push(curr->left);
				}
				if (curr->right != NULL)
				{
					s.push(curr->right);
				}
			}
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

	vector<vector<int>> res;
	MirrorTree mt;
	//mt.printTree(root);
	//mt.mirrorLevel(root);
	//mt.mirrorPre(root);
	//mt.mirrorPreBfs(root);
	//mt.mirrorIn(root);
	mt.mirrorPost(root);
	res = mt.printTree(root);
	for (int i = 0 ; i < res.size() ;i++)
	{
		for (int j = 0 ;j < res[i].size() ; j++)
		{
			printf("%d\t",res[i][j]);
		}
	}
	system("pause");
	getchar();
	return 0;
}