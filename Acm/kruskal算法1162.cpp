
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stdio.h>
using namespace std;

/**
   杭电1162最小生成树的kruskal函数
   为啥使用并查集？
    --最小生成子树是极小连通子图，把起点和终点加入并查集
	会使得最后能够形成一个连通图
	--应用：处理一些不相交集合（Disjoint Sets）的合并及查询问题，
*/
class data 
{
public:
	int from, to;//起点和终点
	double dist;//距离
};

class  data Dist[15000];//最大边大概接近于10000
double xy[105][2];
int par[105], n, m;//par为并查集

//排序点之间距离
int cmp(const class data& a,const class data& b)
{
	return a.dist < b.dist;
}
//并查集查找函数
int find(int x)
{
	if (x == par[x])
		return x;
	else
		//递归查找返回值
		return par[x] = find(par[x]);
}
//并查集合并函数
void join(int x,int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		par[y] = x;
}

//kruskal算法
double kruskal()
{
  //初始化并查集函数
	for (int i=0;i<=n;i++)
	{
		par[i] = i;
	}
	//进行排序，指定排序函数
	sort(Dist, Dist + m, cmp);
	double ans = 0.0;
	for (int j=0;j<m;j++)
	{
		if (find(Dist[j].from)!= find(Dist[j].to))
		{
			ans += Dist[j].dist;
			//将符合条件的起点和终点加入并查集
			join(Dist[j].from,Dist[j].to);
		}
	}
	return ans;
}
int main()
{
	while (~scanf_s("%d", &n) != EOF)
	{
		m = 0;
		for (int i=0;i<n;i++)
		{
			scanf_s("%lf%lf", &xy[i][0], &xy[i][1]);
		}
		//循环求出所有的距离 
		for (int j=0;j<n;j++)
		{
			for (int k=j+1;k<n;k++)
			{
				Dist[m].from = j;
				Dist[m].to = k;
				//求距离
				Dist[m++].dist = sqrt(pow((xy[j][0] - xy[k][0]), 2) + pow((xy[j][1] - xy[k][1]), 2));
			}
		}
		double ans = kruskal();
		printf("%.2f\n",ans);
	}
	getchar();
	return 0;
}