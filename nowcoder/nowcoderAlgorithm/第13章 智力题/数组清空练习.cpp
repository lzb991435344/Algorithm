#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**数组清零
 题目：现在有一个整数数组，其元素值均为1-n范围内的某个整数，现在你和你的朋友在玩一个游戏，
  游戏的目的是把数组清空，你们轮流操作，你是先手，每次操作你可以删除数组中值为某个数的元素
  任意多个(当然数组中值为这个数的元素个数应大于等于你删除的个数,且你至少要删除一个数)。最先
  把数组清空的人获得胜利。假设你们都采取最优策略，请你计算你能否获得胜利。

 给定一个整数数组A和元素个数n。请返回一个整数，1代表你能获胜，0代表你不能获胜。

测试样例：
[1,1,1]
返回：1
*/

class ClearArray
{
public:
	int getWnner(vector<int> arr , int n)
	{
		//先排序
		sort(arr.begin(),arr.end());
		int j;
		int res = 0;
		for (int i=0 ; i< n;)
		{
			int num = 0;
			j = i;
			//该循环主要是判断当前数组的值是否相等，等
			//值索引值往下加，当前的下标值中心赋值给i，
			//当前结果与下标值进行异或
			while (j < n && arr[i] == arr[j])
			{
				j++; 
				num++;
			}
			i = j;
			//异或运算，同0异1
			res ^= num;
		}
		return res != 0;
	}
};


int main()
{
	ClearArray ca;
	vector<int> arr = {1,1,1};
	printf("%d\n",ca.getWnner(arr,3));
	getchar();
	system("pause");
	return 0;
}