/**第二节、寻找满足条件的多个数	
	编程求解：
	输入两个整数 n 和 m，从数列1，2，3.......n 中 随意取几个数,
	使其和等于 m ,要求将其中所有的可能组合列出来。*/

#include <iostream>
#include <list>
#include<stdio.h>
#include <memory.h>
using namespace std;

list<int> list1;
//解法1
void  findFactor(int sum,int n)
{
 if(sum<=0 || n<=0)
 {
	 return ;
 }
 //输出结果
 if(sum==n)
 {
  list1.reverse();
  list<int>::iterator it;
  for(it=list1.begin();it!=list1.end();it++)
   cout<< *it<<"+";
  cout<<n<<endl;
  list1.reverse();
 }
// 放n，和不放n个区别
 list1.push_front(n);
 findFactor(sum-n,n-1);//放n,n-1个数填满sum-n
 list1.pop_front();
 findFactor(sum,n-1); //不放n，n-1个数填满sum
}

/**
这个问题属于子集和问题（也是背包问题）。本程序采用 回溯法+剪枝
X数组是解向量，t=∑(1,..,k-1)Wi*Xi, r=∑(k,..,n)Wi
若t+Wk+W(k+1)<=M,则Xk=true，递归左儿子(X1,X2,..,X(k-1),1)；否则剪枝；
若t+r-Wk>=M && t+W(k+1)<=M,则置Xk=0，递归右儿子(X1,X2,..,X(k-1),0)；否则剪枝；
本题中W数组就是(1,2,..,n),所以直接用k代替WK值。
*/

//子解
void sumofsub(int t, int k ,int r, int& M, bool& flag, bool* X)
{
	X[k] = true;   // 选第k个数
	if (t + k == M) // 若找到一个和为M，则设置解向量的标志位，输出解
	{
		flag = true;
		for (int i = 1; i <= k; ++i)
		{
			if (X[i] == 1)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else
	{   // 若第k+1个数满足条件，则递归左子树
		if (t + k + (k+1) <= M)
		{
			sumofsub(t + k, k + 1, r - k, M, flag, X);
		}
		// 若不选第k个数，选第k+1个数满足条件，则递归右子树
		if ((t + r - k >= M) && (t + (k+1) <= M))
		{
			X[k] = false;
			sumofsub(t, k + 1, r - k, M, flag, X);
		}
	}
}
//寻找解
void search(int& N, int& M)
{
	// 初始化解空间
	bool* X = (bool*)malloc(sizeof(bool) * (N+1));
	memset(X, false, sizeof(bool) * (N+1));
	int sum = (N + 1) * N * 0.5f;
	if (1 > M || sum < M) // 预先排除无解情况
	{
		printf("not found\n");
		return;
	}
	bool f = false;
	sumofsub(0, 1, sum, M, f, X);
	if (!f)
	{
		printf("not found\n");
	}
	free(X);
}
int main()
{
	//int sum=5;
	//int n=10;
	//findFactor(5,10);
	int N, M;
	printf("请输入整数N和M\n");
	scanf("%d%d", &N, &M);
	search(N, M);
	getchar();
	getchar();
	return 0;
}