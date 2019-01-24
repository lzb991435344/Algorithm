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
 >给定一个数字N，打印从1到最大的N位数。

**输入**
>每个输入文件仅包含一组测试样例。
>对于每个测试案例，输入一个数字N(1<=N<=5)。
**输出**
>对应每个测试案例，依次打印从1到最大的N位数。

**样例输入**

>1
**样例输出**
>1
>2
>3
>4
>5
>6
>7
>8
>9
*/
class printNUmber
{
public:
	//小白版本
	void print(int n)
	{
		int len = pow(10 , n);
		for (int i = 0 ; i < len ; i++)
		{
			cout << i << endl;
		}
	}

	//优化版 --未通过测试
	//(1)N未知，是否超出了INT_MAX的范围
	//(2)程序的截断和溢出都未知
	//(3)使用字符串解决
	/**
	* 初始就开辟一个N+1大小的串，用来存储数字
    *用字符串模拟数字的自增，进位，输出
    *当串长度超过N+1时，或者第0位产生进位时就溢出
	*/
	//构造函数初始化
	/*printNUmber(int n)
	{
		this->m_N = n;
		this->m_isOverFlow = false;
		this->m_number = new char[n + 1];
		memset(m_number , '\0', n + 1);
		this->m_number[n - 1] = '1';
		this->m_length = 1;
		//m_N总是大于m_length
		//信息串存在m_number[m_N - length , m_N]之间
	}
	//进位操作
	void  increment()
	{
		int nSum = 0;//当前位
		int takeOver = 0;//进位

		for (int i = m_N - 1 ; i >= m_N - m_length ; i--)
		{
			if (m_number[i] != '\0')
			{
				nSum = m_number[i] - '\0' + takeOver;
			}
			else
			{
				nSum = 0;
			}
			nSum++;
			//大于10进位操作
			if (nSum >= 10)
			{
				//i=0 时表示已经溢出
				if (i == 0)
				{
					m_isOverFlow = true;
					delete m_number;
				}
				else
				{
					nSum -= 10;
					m_number[i] = '0' + nSum;

					takeOver = 1;
					if (i == m_N - m_length)
					{
						m_length++;
						//当前进行进位
					}
				}
			}
			//没有进位操作
			// 没有进位, 则当前位增加1以后循环立即结束
			else
			{
				if (takeOver == 1)
				{
					//当前位+1
					m_number[i] = '0' + nSum;
					break;
         		}

			}
		}
	}
	//打印字符数组
	void printNumber()
	{
		for (int i = m_N - m_length ; i < m_N ; i++)
		{
			cout << m_number[i] << endl;
		}
		cout << endl;
	}
	void print2()
	{
		if (m_N <= 0)
		{
			return ;
		}
		//没有发生溢出的时候调用函数打印
		while (this->m_isOverFlow != true)
		{
			//打印字符数组
			printNumber();
			//进位检测处理
			increment();
		}
	}*/


	//再优化版--递归全排列数字
	/**
>如果我们在数字前面补上0的话，那么我们发现，n位所有的十进制数起始就
	是n个从0到9的全排列。
>也就是说，我们把数字的每一位都从0到9排列一遍，就得到了所有的十进制数。
只要我们在打印的时候，数字排在前面的0不用打印出来而已。
*全排列用递归很容易表示，数字的每一位都可能是0~9中的一个数，然后设置下一位。
*递归结束的条件是我们已经设置了数字的最后一位	
	*/

void printNumber2(char* number)
{
	int len = strlen(number);
	int i;
	for (i = 0 ; i < len ; i++)
	{
		//当前数组中的位置不为0，设置为0
		if (number[i] != '0')
		{
			break;
		}
	}
	//当前下标值小于len
	if (i != len)
	{
		cout << &number[i]<< endl;
	}

}
void printWithRecurrion(char* number , int length , int index)
{
	//直接打印
	if (index == length - 1)
	{
		printNumber2(number);
	}
	//当前位循环0-9位
	for (int i = 0 ; i < 10 ; i++ )
	{
		number[index + 1] = i + '0';
		printWithRecurrion(number, length, index + 1);
	}

}

void  print3(int n)
{
	if (n <= 0)
	{
		return;
    }
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0 ; i < 10 ; i++)
	{
		number[0] = i + 0;
		printWithRecurrion(number, n, 0);
	}
	delete[] number;
}


private:
	int m_N;//N位数
	char* m_number;//存储数据的字符串
	bool m_isOverFlow;//是否溢出，有溢出时说明
	/* volatile定义变量的用处：
	   当要求使用 volatile 声明的变量的值的时候，
	系统总是重新从它所在的内存读取数据，即使它
	前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存。
	*/
	volatile int m_length;//当前数字的位数，每次都会进内存去读取

};
int main()
{
	/*int n;
	while (cin >> n)
	{
		printNUmber pn(n);
		pn.print2();
	}*/
	
	printNUmber pn;
	pn.print3(1);
	system("pause");
	getchar();
	return 0;
}