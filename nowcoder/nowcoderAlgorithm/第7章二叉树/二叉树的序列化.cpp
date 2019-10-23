#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

/**题目:二叉树的序列化，反序列化，先序，按层次（queue）
    方便将树存到文件中，，
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};
class  TreetoStr
{
public:
	string inttostring(int n)
	{
		
		char a = '0';
		string s;
		while (n>0)
		{
			char ch = a + n % 10;
			//字符串连接
			s = ch + s;
			//
			n /= 10;
		}
		return s;
	}
	//先序实现序列化二叉树
	string preorderSerize(TreeNode* root, string &s)
	{
		if (root==NULL)
		{
			s += "#!";
            return s;
		}
		//先将取到int转换成字符
		string val = inttostring(root->val);
		s += val;
		s += "!";
		preorderSerize(root->left,s);
		preorderSerize(root->right,s);
		return s;
	}

	//按层遍历--测试未通过
	string levelOrderSerize(TreeNode* root, string &s)
	{
		if (root == NULL)
		{
			s += "#！";
			return s;
		}

		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			TreeNode* temp = que.front();
			que.pop();

			if (temp->left!=NULL)
			{
				string val = inttostring(temp->left->val);
				s += val;
				s += "!";
			}
			else
			{
				s += "#！";
			}

			if (temp->right!=NULL)
			{
				string val = inttostring(temp->left->val);
				s += val;
				s += "!";
			}
			else
			{
				s += "#！";
			}
		}
		return s;
	}


	string toString(TreeNode*  root)
	{
		string s;
		return preorderSerize(root ,s);
	}
	string toString2(TreeNode* root)
	{
		string s;
		return levelOrderSerize(root,s);
	}

};

int main()
{
	TreetoStr ts;
	TreeNode*root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(11);
	string s= ts.toString(root);
	string s1 = ts.toString2(root);
	//printf("%s\t",ts.toString(root)); 
	int len = s.length();
	for (int i=0;i<len ;i++)
	{
		printf("%c\t",s[i]);
	}
	int len2 = s1.length();
	for (int j=0;j<len2;j++)
	{
		printf("%c",s1[j]);
	}
	system("pause");
	getchar();
	return 0;
}