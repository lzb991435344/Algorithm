#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**数组清零
   题目：你和你的朋友正在玩棋子跳格子的游戏，而棋盘是一个由n个
 格子组成的长条，你们两人轮流移动一颗棋子，每次可以选择让棋子
 跳1-3格，先将棋子移出棋盘的人获得胜利。我们知道你们两人都会
 采取最优策略，现在已知格子数目，并且初始时棋子在第一格由你操作。请你计算你是否能获胜。

  给定格子的数目n(n为不超过300的正整数)。返回一个整数，1代表能获胜
 0代表不能获胜。

  由于棋子最开始是在第一格，所以棋子剩下可走的格数是n-1格，最优策
 略是留下最后4格，则谁先走谁输。因为两人均选择最优策略，则为了能
 够保证最后留下四格，则每次两人共走四格。

*/

class Game
{
public:
	int  Winner(int n )
	{
		//最后走4格能赢
		if (((n-1)%4) == 0)
		{
		  return 1;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	Game ga;	
	printf("%d\n",ga.Winner(10));
	getchar();
	system("pause");
	return 0;
}