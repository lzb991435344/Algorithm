#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

/**
CodeInterview:
>输入一个整数，输出该数二进制表示中1的个数。
其中负数用补码表示。
**样例输入**
>4
>5
>-1
**样例输出**
>1
>2
>32
*/

class findBinary1InInteger
{
public:
    //只能用于正数--缺陷：负数移位会发生死循环
	int countNumber(int n )
	{
		int count = 0;
		while (n)
		{
			if (n & 1 == 1)
			{
				count++;
			}
			n >>=  1;//右移出去
		}
		return count;
	}

	//避免负数出现的死循环
	/**例子：
	比如一个有符号位的8位二进制数11001101，逻辑右移就不管
	符号位，如果移一位就变成01100110。算术右移要管符号位，
	右移一位变成10100110。

	*    逻辑左移=算数左移，右边统一添0
	*    逻辑右移，左边统一添0
	*    算数右移，左边添加的数和符号有关


	>e.g:1010101010，其中[]位是添加的数字
	>
	>逻辑左移一位：010101010[0]
	>
	>算数左移一位：010101010[0]
	>
	>逻辑右移一位：[0]101010101
	>
	>算数右移一位：[1]101010101

	因此如果输入负数，那么我们的算法简单的判断是不是0来
	终结，岂不是要死循环

	#避免负数移位的死循环
	为了负数时候避免死循环，我们可以**不右移数字n，转而
	去移动测试位**

	  那么思考我们的循环结束条件，flag一直左移（乘以2），
	当超出表示标识范围的时候，我们就可以终止了，但是这样子的话，
	最高位的符号位没有测试，因此要单独测试，同时由于会溢出，
	我们的flag需要用long来标识

	| 类型 | 范围 |
	| ------------- |:-------------:|
	|unsigned   int   | 0～4294967295   |
	| int  | 2147483648～2147483647 |
	| unsigned long |0～4294967295|
	| long   |2147483648～2147483647|
	| long long|最大值：9223372036854775807|
	| long long|最小值：-9223372036854775808|
	| unsigned long long|最大值：1844674407370955161|
	| __int64|最大值：9223372036854775807|
	| __int64|最小值：-9223372036854775808|
	| unsigned __int64|最大值：18446744073709551615
	*/
	int countNumber2(int n)
	{
		int count = 0;
		int i = 0;
		unsigned long flag = 1;
		//移位的次数为31位，最后一个符号位要单独判断
		while ( flag <= INT_MAX)
		{
			if ((n & flag) != 0)
			{
				count++;
			}
			//移动符号位，避免负数的死循环
			//最后只剩下符号位
			flag <<= 1;
		}
		//最后这里判断符号位
		if ((n & flag) != 0)
		{
			count++;
		}
		return count;
	}

	//优化循环的判断--精简循环
	int countNumber3(int n)
	{
		int count = 0;
		int i = 0;
		unsigned long flag = 1;
		//修改条件判断，当发生截断时，在截断处停止
		//正好是整数二进制的32位
		while (flag != 0)
		{
			if ((n & flag) != 0)
			{
				count++;
			}
			//左移，分别判断每一位的值
			flag <<= 1;
		}
		return count;
	}

	//再优化，循环的次数刚好是二进制中的1的个数
	/**

* 如果n!=0，那么其二进制位中至少有一个1
* 如果n的最低位是1（奇数），那么n-1正好把这个最低位的1
  变成0，其他位不变
* 如果n的最低位是0（偶数），那么假设其右起第一个1位于m位
，即m位后面全是0，那么n-1的第m位由1变成0，而第m位后面的所
  有0均变成1，m位之前的所有位保持不变。
	
	exg: 1100 & (1100 - 1) =1000 这样二进制中的1的个数就是
	改变的次数
	*/
	int countNumber4(int n)
	{
		int count = 0;
		while (n)
		{
			count++;
			n = n &(n - 1);
		}
		return count;
	 }

	//开挂计算
	/**  #include <bitset>
	bitset<32> bit(n);
对于一个叫做foo的bitset：
 foo.size() 返回大小（位数）
 foo.count() 返回1的个数
 foo.any() 返回是否有1
 foo.none() 返回是否没有1
 foo.set() 全都变成1
 foo.set(p) 将第p + 1位变成1
 foo.set(p, x) 将第p + 1位变成x
 foo.reset() 全都变成0
 foo.reset(p) 将第p + 1位变成0
 foo.flip() 全都取反
 foo.flip(p) 将第p + 1位取反
 foo.to_ulong() 返回它转换为unsigned long的结果，如果超出范围则报错
 foo.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
 foo.to_string() 返回它转换为string的结果
	
	*/
	int countNumber5(int n)
	{
		bitset<32> bit(n);
		return bit.count();
	}
};

int main()
{
	findBinary1InInteger fi;
	printf("%d\t",fi.countNumber(3));
	printf("%d\t", fi.countNumber2(3));
	printf("%d\t", fi.countNumber3(3));
	printf("%d\t", fi.countNumber4(3));
	printf("%d\t", fi.countNumber5(3));
	system("pause");
	getchar();
	return 0;
}