/**
 问题：如何随机从n个对象中选择一个对象，这n个对象是按序排列的，但是在此之前你是不知道n的值的。
 (1)概率计算如下：
   p=1/m*(m/(m+1)*(m+1/m+2)...*(n-1/n))=1/n --即等概率地抽取n个元素
 (2)蓄水池抽样算法
   
**/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
 
using namespace std;
 
/**typedef vector<int> IntVec;
typedef typename IntVec::iterator Iter;
typedef typename IntVec::const_iterator Const_Iter;
 

//随机生成i,k之间的数
int randint(int i, int k)
{
	if (i > k)  //交换两个值
	{
		int t = i; i = k; k = t; // swap
	}
	//随机生成一个数
	int ret = i + rand() % (k - i + 1);
	return ret;
}
 
//n未知的情况下
bool reservoir_sampling(const IntVec &input, int &result)
{
	srand(time(NULL));
	if (input.size() <= 0)
		return false;
 
	Const_Iter iter = input.begin();
	result = *iter++;
	for (int i = 1; iter != input.end(); ++iter, ++i)
	{
		//生成0，i之间的数
		int j = randint(0, i);
		if (j < 1)
			result = *iter;	
	}
	return true;
}
 
int main()
{
	const int n = 10;
	IntVec input(n);
	int result = 0;
 
	for (int i = 0; i != n; ++i)
		input[i] = i;
	if (reservoir_sampling(input, result))
		cout << result << endl;
	return 0;
}**/
https://blog.csdn.net/huagong_adu/article/details/7619665

/**蓄水池抽样伪代码：
array S[n];    //source, 0-based
array R[k];    // result, 0-based
integer i, j;
 
 //填充数组数据
// fill the reservoir array
for each i in 0 to k - 1 do
        R[i] = S[i]
done;
 
// replace elements with gradually decreasing probability
for each i in k to n do
      //0-i中随机生成一个数
        j = random(0, i);   // important: inclusive range
        if j < k then
                R[j] = S[i]
        fi
done
*/

/**假设n很大，且已知的情况
 #include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// generate a random number between i and k,
// both i and k are inclusive.
//生成随机数 
int randint(int i, int k)
{
	if (i > k)
	{
		int t = i; i = k; k = t; // swap
	}
	int ret = i + rand() % (k - i + 1);
	return ret;
}
 
// take m samples to result from input of n items.
bool reservoir_sampling(const int *input, int n, int *result, int m)
{
	srand(time(NULL));
	if (n < m || input == NULL || result == NULL)
		return false;
	for (int i = 0; i != m; ++i)
		result[i] = input[i];
 
	for (int i = m; i != n; ++i)
	{
	//randint(m,n)生成的（M,N) 矩阵的随机二进制数字,“ 0 ”和“ 1 ”出现的概率均等。
		int j = randint(0, i);
		if (j < m)
			result[j] = input[i];	
	}
	return true;
}
 
int main()
{
	const int n = 100;
	const int m = 10;
	int input[n];
	int result[m];
 
	for (int i = 0; i != n; ++i)
		input[i] = i;
	if (reservoir_sampling(input, n, result, m))
		for (int i = 0; i != m; ++i)
			cout << result[i] << " ";
	cout << endl;
	return 0;
}
*/

/**
  假设n未知，使用vector,模拟可变的集合大小，
使用迭代器实现集合元素的遍历
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
 
using namespace std;
 
typedef vector<int> IntVec;
typedef typename IntVec::iterator Iter;
typedef typename IntVec::const_iterator Const_Iter;
 
// generate a random number between i and k,
// both i and k are inclusive.
int randint(int i, int k)
{
	if (i > k)
	{
		int t = i; i = k; k = t; // swap
	}
	int ret = i + rand() % (k - i + 1);
	return ret;
}
 
// take m samples to result from input of n items.
bool reservoir_sampling(const IntVec &input, IntVec &result, int m)
{
	srand(time(NULL));
	if (input.size() < m)
		return false;
 
	result.resize(m);
	
	//制定集合元素中的值
	Const_Iter iter = input.begin();
	for (int i = 0; i != m; ++i)
		result[i] = *iter++;
 
 
	for (int i = m; iter != input.end(); ++i, ++iter)
	{
		int j = randint(0, i);
		if (j < m)
			//取迭代器的值
			result[j] = *iter;
	}
	return true;
}
 
int main()
{
	const int n = 100;
	const int m = 10;
	IntVec input(n), result(m);
 
	for (int i = 0; i != n; ++i)
		input[i] = i;
	if (reservoir_sampling(input, result, m))
		for (int i = 0; i != m; ++i)
			cout << result[i] << " ";
	cout << endl;
	return 0;
}



*/






