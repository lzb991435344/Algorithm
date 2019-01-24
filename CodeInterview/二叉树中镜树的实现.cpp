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
 ���������Ķ�����������任ΪԴ�������ľ���

**��������**

�������ľ����壺Դ������
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		���������
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
	//�����ӡ������--��������
	vector<vector<int> > printTree(TreeNode* root) {
		vector< vector<int> > v;
		vector<int> v1;

		queue<TreeNode *> q;
		//ѹ����ڵ�
		q.push(root);

		TreeNode *last = NULL;
		TreeNode *nlast = NULL;
		last = root;
		while (!q.empty())
		{
			//ʹ��tempָ������е�ͷ���
			TreeNode *temp = q.front();
			//�����ڵ�
			q.pop();
			//v1���ڱ��浱ǰֵ
			v1.push_back(temp->val);
			// �ѵ�ǰ�ڵ���ڵ��������� ע��������Ƚ��ȳ�
			//�����ݽṹ �����ӡ��Ҫ���Ǵ����� ����Ҫע��
			//���ҽڵ������е�˳
			//nlastָ��ǰ��temp��������
			if (temp->left != NULL)
			{
				q.push(temp->left);
				nlast = temp->left;
			}
			//nlastָ��ǰ��������
			// �ѵ�ǰ�ڵ��ҽڵ���������
			if (temp->right != NULL)
			{
				q.push(temp->right);
				nlast = temp->right;
			}
			//��ͷԪ�ص��ڸ�Ԫ��
			// ����һ�е�ĩβ
			if (temp == last)
			{
				v.push_back(v1);
				v1.clear();
				last = nlast;
			}
		}
		return v;
	}

	//ͨ�������ʵ�־�����ʵ��
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

	//ǰ�����
	void mirrorPre(TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		//��ѹ����ڵ�
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
	//���չ�����ȱ���
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
			//����������Ϊ�յ�ʱ�򽻻���������
			if (temp->left != NULL || temp->right != NULL )
			{
				swap(temp->left , temp->right);
			}
			//��������ջ
			if (temp->left != NULL)
			{
				s.push(temp->left);
			}
			//��������ջ
			if (temp->right != NULL)
			{
				s.push(temp->right);
			}
		}		 
	}
	//�������
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
			//���ҵ������Ԫ��
			while (temp != NULL)
			{
				//������ȫ��ѹջ
				s.push(temp);
				temp = temp->left;
			}
			//����ȫ��ת���������������н����ڵ㣬�����ڵ�֮��
			//�������������Ľڵ�ȫ��ѹջ������ֵ���������
			if (!s.empty())
			{
				//�ӵײ����еݹ飬һֱ�����ڵ�
				temp = s.top();
				//����������Ϊ�գ�����ֵ
				if (temp ->left != NULL || temp->right != NULL)
				{
					swap(temp->left ,temp->right);
				}
				s.pop();
				//ָ��ǰ�ڵ��������
				temp = temp->left;
			}
		}
	}
	//�������ʵ��
	void mirrorPost(TreeNode* root)
	{
		if (root == NULL)
		{
			return ;
		}
		TreeNode* curr = NULL;//��ǰ���ʵĽڵ�
		TreeNode* pre = NULL;//ǰһ�����ʵĽڵ�
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			curr = s.top();//ȡջ��

			if ((curr->left == NULL && curr->right == NULL) || 
				((pre != NULL) &&((pre == curr->left) || (pre == curr->right))))
			{
				//����������Ϊ�գ�������������
				if (curr->left != NULL || curr->right != NULL)
				{
					swap(curr->left ,curr->right);
				}
				s.pop();
				//���õ�ǰ���ʵĽڵ�
				pre = curr;
			}
			else
			{
				//����������Ϊ��ѹջ
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