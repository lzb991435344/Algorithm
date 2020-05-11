#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
CodeInterview:
1.쳲��������еĵ�n�
2.һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
 �����������һ��n����̨���ܹ��ж�����������
3.һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
  �����������һ��n����̨���ܹ��ж�����������
 4.���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1
 ��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

class Recurssion
{
public:
	//��ը O(2^n)
	int Fibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}
		else
		{
			return Fibonacci(n-2) + Fibonacci(n-1);
		}
	}

	//���� O(N)
	int Fibonacci2(int n)
	{
		long one = 0;
		long  two = 1;
		long res = 0;
		for (int i = 2 ; i <= n ; i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}

	//O(logN)
	static int pre;//�������f(n)��ֵ
	static int post;//�������f(n-1)��ֵ
	int temp;
	
int Fibonacci3(int n)
	{
		if (n < 2)
		{
			if (n == 0)
			{
				return 0;
			}
			pre = 1;
			post = 1;
			return pre;
		}
		// n Ϊ������ ������һ������ �����ص�ʱ
		//  pre��    f(n) = f(n - 1) + f(n - 2)
		//  post��   f(n - 1) = f(n) - f(n - 2)
		if (n % 2 == 1)
		{
			Fibonacci3(n - 1);
			pre = pre + post;
			post = pre - post;
			return pre;
		}

		// nΪż��ʱ���ϳ���
		// �����ص�ʱ,f(n) ͨ�� f(n/2) ������:
		//
		//  �� n = 2k��//nΪ2kʱ�Ƶ���ʽ
		//          f(2k) = f(k)  * f(k + 1) + f(k-1) * f(k)
		//                = f(k) * [f(k) + f(k - 1)] + f(k-1) * f(k)
		//                = f(k) ^ 2 + 2 * f(k) * f(k - 1)
		// �� n = 2k-1��//nΪ 2k-1ʱ�Ƶ���ʽ
		//      f(2k - 1) = f(k) * f(k) + f(k - 1)  * f(k - 1)
		//                = f(k)^2 + f(k - 1)^2
		//ż��ʵ��
		Fibonacci3(n / 2);
		temp = pre;
		pre = pre * pre + 2 * pre * post;
		post = temp *temp + post * post;
		return pre;
	}
	//��̨�ף�ֻ����1,2��
	int jumpFloor(int n)
	{
		if (n <= 2)
		{
			return n;
		}
		long one = 1;
		long two = 2;
		long res = 0;
		for (int i = 3 ; i <= n ;i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}

	//����1����̨�׵Ľ�������
	//*1, (n = 0)
	//* 1, (n = 1)
	//* 2 * f(n - 1), (n >= 2)
	int jumpFloor2(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		else if (n == 1)
		{
			//һ��̨��
			return 1;
		}
		else
		{
			//�ܵķ�����
			return 2 * jumpFloor2(n - 1);
		}
	}
	//����2��ʹ���ݴη�����
	int jumpFloor3(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		else
		{
			return pow(2 , n-1);
		}
	}
	//��Ч����λָ��ֻ��Ҫ2��ָ������
	int jumpFloor4(int n)
	{
		long long res;
		//����8�ֽڣ���������λ
		if (n >= 32)
		{
			res = 1 << 30;
			res = res << (n - 31);
		}
		else
		{
			//����һλ
			res = 1 << (n - 1);
		}
		return res;
	}
	//���θ���

	/**
	2*n�ľ��η���������Ϊf(n).

   ��һ��2*1��С���θ��Ǵ���ε���ߣ�

   *Ҫô���ŷţ�ת����f(n-1),

   *Ҫô���ŷ����Σ�ת����f(n-2),

   ���f(n) = f(n-1) + f(n-2)
   *	1 n = 0
   *	1 n = 1
   *	f(n - 1) + f(n - 2)
	*/
	int retCover(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		else if(n == 1)
		{
			return 1;
		}

		long one=1;
		long two=1;
		long res = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}
};
int Recurssion::pre = 0;
int Recurssion::post = 0;
int main()
{
	Recurssion rs;
	//printf("%d\t", rs.Fibonacci(5));
	//printf("%d\t", rs.Fibonacci2(5));
	//printf("%d\t", rs.Fibonacci3(5));

	//printf("%d\t",rs.jumpFloor(5));
	//printf("%d\t", rs.jumpFloor2(5));
	//printf("%d\t", rs.jumpFloor3(5));
	//printf("%d\t", rs.jumpFloor4(5));
	system("pause");
	getchar();
	return 0;
}