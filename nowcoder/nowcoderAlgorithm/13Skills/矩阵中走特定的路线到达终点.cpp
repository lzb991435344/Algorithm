#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**数组清零
 题目：A与B做游戏。 在一个n*m的矩阵中的出发点是（1，m），
 终点是（n,1），规则是只能向左移动一格，向下一格或向左下
 移动一格，先走到终点的为winner。 A先走。

 给定两个整数n和m，请返回最后的获胜者的名字(A或B)。

测试样例：
5 3
返回：B
*/

class Game
{
public:
	char Winner(int n ,int m)
	{
		if (m%2==1 && n%2==1)
		{
			return 'B';
		}
		else
		{
			return 'A';
		}
	}
};



int main()
{
	Game ga;	
	printf("%c\n",ga.Winner(5,3));
	getchar();
	system("pause");
	return 0;
}