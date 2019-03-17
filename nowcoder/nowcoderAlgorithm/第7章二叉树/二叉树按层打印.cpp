/**
题目：二叉树按层打印
    有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。 
给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组
进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素
按照从左往右排列。保证结点数小于等于500。

*/

#include <iostream>
#include<stdio.h>
#include <stack>
#include <vector>
#include <queue> 
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class TreePrinter {
public:
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
};
int main()
{
	TreePrinter tp;
	//初始化树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	vector<vector<int>> res;
	res = tp.printTree(root);
	for (int i = 0;i < res.size() ; i++)
	{
		for (int j = 0 ;j < res[i].size() ; j++)
		{
			cout << res[i][j]<< endl;
		}
		//换行,输出数据的格式
		cout << endl;
	}
	getchar();
	system("pause");
	return 0;
}