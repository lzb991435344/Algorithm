
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

/**题目：随机吐球---蓄水池抽样算法
    题目：有一个机器按自然数序列的方式吐出球，1号球，2号球，3号球等等。你有一个袋子，
  袋子里最多只能装下K个球，并且除袋子以外，你没有更多的空间，一个球一旦扔掉，就再也不
  可拿回。设计一种选择方式，使得当机器吐出第N号球的时候，你袋子中的球数是K个，同时可以
  保证从1号球到N号球中的每一个，被选进袋子的概率都是K/N。举一个更具体的例子，有一个只能
  装下10个球的袋子，当吐出100个球时，袋子里有10 球，并且1~100号中的每一个球被选中的概率
  都是10/100。然后继续吐球，当吐出1000个球时，袋子里有 10个球，并且1~1000号中的每一个球
  被选中的概率都是10/1000。继续吐球，当吐出i个球时，袋子里有10个球，并且1~i号中的每一个
  球被选中的概率都是10/i。也就是随着N的变化，1~N号球被选中的概率动态变化成k/N。请将吐出
  第N个球时袋子中的球的编号返回。

  题目中要求接球的时候等概率，即在1-k号球的时候，直接接球，不然重新随机
  * 蓄水池抽样算法：
  * 1.处理1-k号球时，直接放入袋子中
  * 2.处理第i号球(此时i大于k)的时候，以k/i的概率决定是否把i号球放入袋中，
  *若放入还要在袋子中随机扔掉一个
  *思路：当N小于k时，N必定选进袋子，否则以k/N的概率选进袋子。

  int rand(void)；
  返回一个[0,RAND_MAX]间的随机整数。

*/

class Bag
{
public:
	vector<int> res;
	vector<int> carryBalls(int N , int k)
	{
		//当前数比k小，直接压入vector
		if (N <= k)
		{
			res.push_back(N);
		}
		else
		{
			//随机出一个索引值
			int r = rand() % (N);
			if (r < k)
			{
				res[r] = N;
			}
		}
		return res;
   }
};

int main()
{
	Bag bg;
	vector<int> res;
	res = bg.carryBalls(8,5);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		cout << *it<< endl;
	}
	system("pause");
	getchar();
	return 0;
}