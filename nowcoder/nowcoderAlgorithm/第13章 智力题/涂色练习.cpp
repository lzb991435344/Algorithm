#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**涂色练习：
  题目：要在一个nxm的格子图上涂色，你每次可以选择一个未涂色
的格子涂上你开始选定的那种颜色。同时为了美观，我们要求你涂
色的格子不能相邻，也就是说，不能有公共边，现在问你，在采取
最优策略的情况下，你最多能涂多少个格子？

给定格子图的长n和宽m。请返回最多能涂的格子数目。

测试样例：
1,2
返回：1

*/

class Paint {
public:
	int getMost(int n, int m) {
		return (n*m % 2 == 0) ? n*m / 2 : n*m / 2 + 1;
	}
};

int main()
{
	Paint ga;	
	printf("%d\n",ga.getMost(1,3));
	getchar();
	system("pause");
	return 0;
}