#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/**
  对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。

 给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。

  需要判断A树中是否存在B的子树，我们可以把树进行一个前序遍历（图片左边的树为A树，右边的树为B树）：A：12453 B：245，
我们可以发现A中有245字串和B中的子串相等，发现了这个东西后，再仔细思考是否可以把两个树的子树问题变换为字符串匹配的问题呢，
但这里还有一个问题，你怎么知道B中的2是一个节点，4是一个节点，5是一个节点的？而不是24是一个节点或者5是一个节点呢？
，所以在这样的情况下我们就用到了树的序列化！
   树的按层遍历：12345  245
（比如A树可以使用前序遍历序列化为1！2！4！#！#！5！#！#！3！#！#！ 其中！号为分隔符，#号代表空。
   -----转换成字符串匹配之后时间复杂度即为KMP算法的复杂度O(M+N)
*/

struct TreeNode
{
	int  val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

//对树进行序列化
string Serialization(TreeNode* A , string& s)
{
	if (A==NULL)
	{
		//对空的节点加上一个特定的字符串
		s += "#!";
		return s;
	}
	//将字符串连接到一起
	char ch = A->val + '0';
	s += ch;
	s += '!';
	//递归序列化左右子树
	Serialization(A->left, s);
	Serialization(A->right, s);
	return s;
}

//kmp算法生成next数组
int* generaternext(string s,int len)
{
	int j = 0, k = -1;
	int* next = new int[len];
	next[0] = -1;
	while (j < len-1)
	{
		if (k == -1 && s.at(k) != s.at(j))
		{
			j++;
			k++;
			if (s.at(k) == s.at(j))
			{
				next[j] = k;
			}else 
			{
				next[j] = next[k];
			}
		}
		else
		{
			k = next[k];
		}

	}
	return next;
}

//kmp算法 时间复杂度为O(M+N)
int kmpSearch(string s1 , string s2 , int len1 , int len2)
{
	int i = 0, j = 0;
	int *next = generaternext(s2,len2);
	while(i < len1 && j < len2)
	{
		if (j == -1 || s1.at(i) == s2.at(j))
		{
			i++; 
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == len2)
	{
		return i-j;
	}
	else 
	{
		return -1;
	}

}
int chkIsSameStructure(TreeNode* A,TreeNode* B)
{
	//对树进行序列化
	string str1;
	Serialization(A , str1);
	string str2;
	Serialization(B , str2);

    int res = kmpSearch(str1,str2,str1.size(),str2.size());
	return res!=-1;
}
int main()
{
	struct TreeNode* node1;
	struct TreeNode* node2;
	
	cout<< chkIsSameStructure(node1,node2) << endl;
	getchar();
	return 0;
}