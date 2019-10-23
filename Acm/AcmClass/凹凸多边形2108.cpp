#include <stdio.h>
#include <string.h>
/**
  凹凸多边形的判断
	方法把点转换成向·量是做叉乘，若叉乘为负则图形定为凹的，
*/
int a[10000], b[10000];
int main()
{
	int i, j, n, k, l;
	while (scanf_s("%d", &n) && n != 0)
	{
		k = 1;
		//循环输入多边形的顶点
		for(i=0;i<n;i++)
		{
			scanf_s("%d%d", &a[i], &b[i]);
        }
		a[n] = a[0];
		b[n] = b[0];
		a[n + 1] = a[1];
		b[n + 1] = b[1];
		//计算多边形的叉积，大于0即为凸多边形
		for (i=0;i<n;i++)
		{
			int s = (a[i + 1] - a[i])*(b[i + 2] - b[i]) - (a[i + 2] - a[i])*(b[i + 1] - b[i]);
		if (s < 0)
		 {
			k = 0;
		 }
		}
		if (k == 1) printf("yes!");
		else printf("no!");
	}


	getchar();
	return 0;
}