
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include<string.h>
using namespace std;

/**
 1878 --欧拉回路

 1.无向图中：所给定的图为连通图，且所有节点的度为偶数；
 2.有向图中：所给定的图为连通图，且所有节点的度为零。

 需用并查集将节点连接，判断连通（即生成一棵树），
 再判断所有节点的度数是否都为偶数即可。
*/
int f[12121212];
int path[12121212];
int n, m;
//初始化数组的值 
void init()
{
	for (int i=0;i<n;i++)
	{
		f[i] = i;
	}
}
//查找
int find(int a )
{
	int r = a;
	while (f[r] != r)
	{
		r = f[r];
	}
	return r;
}

//将节点联结起来，构成连通图
void merge(int a, int b)
{
	int A, B;
	A = find(a);
	B = find(b);
	if (A != B)
		f[B] = A;
}
int main()
{
	while (~scanf_s("%d", &n))
	{
		if (n == 0)break;
		scanf_s("%d", &m);
		init();
		memset(path, 0, sizeof(path));
		//判断节点 度数是否为偶数
		while (m--)
		{
			int x, y;
			scanf_s("%d%d", &x, &y);
			x--;
			y--;
			merge(x, y);
			path[x]++;
			path[y]++;
		}
		int huan = 0;
		int tongji = 0;
		for (int i = 0; i < n; i++)
		{
			if (f[i] == i) { huan++; if (huan > 1)break; }
			if (path[i] != 2)tongji++;
		}
		if (huan > 1)
		{
			printf("0\n");
			continue;
		}
		if (tongji == 0)
			printf("1\n");
		else
			printf("0\n");	
	}
	getchar();
    return 0;
}