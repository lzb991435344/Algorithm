#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**题目:二叉树的非递归遍历
   前序，中序，后序（单栈，双栈）
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

class TreeToSequence
{
public:
	vector<int> preOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;
		s.push(root);
        TreeNode* cur;

		while (!s.empty())
		{
			cur = s.top();//取栈顶
			s.pop();//弹出元素
			res.push_back(cur->val);//作为结果
			//先压入右子树
			if (cur->right != NULL)
			{
				s.push(cur->right);
			}
			//压左子树
			if (cur->left != NULL)
			{
				s.push(cur->left);
			}
		}
		return res;
	 }

	vector<int> inOrder(TreeNode* root)
	{
		vector<int>  res;
		TreeNode* cur= root;
		stack<TreeNode*> s;
		//s.push(root);
		//while两个条件中分为两种情况
		//(1)当栈不为空的时候，先把左子树全部压栈，然后取栈顶
		//(2)当前节点为空时，第二个while循环不执行，确保找到根节点进行打印
		while (!s.empty() || cur!=NULL)
		{
			//将左子树全部压栈
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty())
			{
				TreeNode* temp=s.top();
				s.pop();
				res.push_back(temp->val);
				//当前节点包含空和不为空的情况
				//(1)不为空将右节点压栈
				//(2)为空时忽略执行while语句，直接取到当前需要打印的根节点
				cur = temp->right;
			}

		}
		return res;
	}
	//两个栈实现
	vector<int> resverOrderWithTwoStack(TreeNode* root)
	{
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		TreeNode* cur;
		s1.push(root);
		vector<int> res;

		while(!s1.empty())	
		{
			cur = s1.top();
			s1.pop();
			s2.push(cur);
			if (cur->left != NULL)
			{
				s1.push(cur->left);
			}
			if (cur->right != NULL)
			{
				s1.push(cur->right);
			}
		}
		while (!s2.empty())
		{
			cur = s2.top();
			s2.pop();
			res.push_back(cur->val);
		}

		return res;
	}
	//单栈实现
	vector<int> resverOrderWithOneStack(TreeNode* root)
	{
		vector<int> res;
		TreeNode* h = root;//最近一次打印的次数
		TreeNode* c = NULL;//设置为空
		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			c = s.top();
			//当前节点c的左右节点都不等于h,且左子树不为空，
			//说明左子树还没打印，入栈
			if (h != c->left && c->left != NULL && h != c->right)
			{
				s.push(c->left);
			}
			//当前节点c的右节点不等于h,且c的右子树不为空
			//说明右子树还没打印，入栈
			else if (h!=c->right && c->right != NULL)
			{
				s.push(c->right);
			}
			else
			{
				//已经打印了当前节点，直接将根节点入栈，
				//同时将当前节点设置为h
				res.push_back(c->val);
				s.pop();
				h = c;
			}
		}
		return res;
	}
};

int main()
{
	TreeNode*root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(5);
	root->left->left->right = new TreeNode(6);

	TreeToSequence ts;
	vector<int> res;
	//res = ts.inOrder(root);//5 4 6 2 1 3
	//res = ts.preOrder(root); //1 2 4 5 6 3
	//res = ts.resverOrderWithOneStack(root);// 5 6 4 2 3 1
	res = ts.resverOrderWithTwoStack(root);
	for (vector<int>::iterator it=res.begin();it!=res.end();++it)
	{
		cout << *it << endl;
	}
	system("pause");
	getchar();
	return 0;
}