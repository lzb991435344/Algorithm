#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

/**
 杭电ACM 1162
  最小生成树解决的问题：AB之间带权路径的最小值
 1.最小生成树prim算法
 2.最小生成树的kruskal算法
*/

#define INF 1<<30
//用来存储带权路径，点与点之间要求计算之间的距离
double a[101], b[101], map[101][101];
double dist[101];//当前路径和
int used[101];

void prim(int n)
{
	int c = 0;
	int i = 0, j = 0;
	double sum = 0;
	dist[1] = 0;//初始化最初路径和为0
	for (i=0;i<=n;i++)
	{
		double min = INF;//设置为最大值
		c = 0;
		//和当前的最小路径和比较
		for (j=1;j<=n;j++)
		{
			if (!used[j] && dist[j] < min)
			{
				min = dist[j];
				c = j; //索引设置为当前索引
			}
		}
		//设置为已经使用
		used[c] = 1;
		//找出最短的路径
		for (j=1;j<=n;j++)
		{
			//没有使用过且在二维数组中比当前的路径和小
			if (!used[j] && dist[j] > map[c][j])
			{
				dist[j] = map[c][j];
			}
		}
		//打印出带权路径的总和
		for (int i=1;i<=n;i++)
		{
			sum += dist[j];
			printf("%2.1f\n",sum);
		}
	}

}
int main()
{
	int n = 0;
	while (~scanf_s("%d",&n))
	{
		//初始化两个一维数组
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int i = 0, j = 0;
		//初始化
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				map[i][j] = INF; 
			}
			dist[i] = INF;
			used[i] = 0;
		}
		//键盘输入两个数组
		for (int i=0;i<=n;i++)
		{
			scanf_s("%lf%lf", &a[i], &b[i]);
		}
		double m = 0, x = 0;
		//二维数组存两点之间的距离
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				//两点之间距离的平方和
				x = (a[j] - a[i])*(a[j] - a[i]) + (b[j] - b[i])*(b[j] - b[i]);
				//两点之间的距离
				m = sqrt(x);
				//赋值
				map[i][j] = map[j][i] = m;
			}
		}
		//调用prim函数
		prim(n);
	}
	getchar();
	return 0;
}