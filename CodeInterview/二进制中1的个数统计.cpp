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
>����һ��������������������Ʊ�ʾ��1�ĸ�����
���и����ò����ʾ��
**��������**
>4
>5
>-1
**�������**
>1
>2
>32
*/

class findBinary1InInteger
{
public:
    //ֻ����������--ȱ�ݣ�������λ�ᷢ����ѭ��
	int countNumber(int n )
	{
		int count = 0;
		while (n)
		{
			if (n & 1 == 1)
			{
				count++;
			}
			n >>=  1;//���Ƴ�ȥ
		}
		return count;
	}

	//���⸺�����ֵ���ѭ��
	/**���ӣ�
	����һ���з���λ��8λ��������11001101���߼����ƾͲ���
	����λ�������һλ�ͱ��01100110����������Ҫ�ܷ���λ��
	����һλ���10100110��

	*    �߼�����=�������ƣ��ұ�ͳһ��0
	*    �߼����ƣ����ͳһ��0
	*    �������ƣ������ӵ����ͷ����й�


	>e.g:1010101010������[]λ����ӵ�����
	>
	>�߼�����һλ��010101010[0]
	>
	>��������һλ��010101010[0]
	>
	>�߼�����һλ��[0]101010101
	>
	>��������һλ��[1]101010101

	���������븺������ô���ǵ��㷨�򵥵��ж��ǲ���0��
	�սᣬ����Ҫ��ѭ��

	#���⸺����λ����ѭ��
	Ϊ�˸���ʱ�������ѭ�������ǿ���**����������n��ת��
	ȥ�ƶ�����λ**

	  ��ô˼�����ǵ�ѭ������������flagһֱ���ƣ�����2����
	��������ʾ��ʶ��Χ��ʱ�����ǾͿ�����ֹ�ˣ����������ӵĻ���
	���λ�ķ���λû�в��ԣ����Ҫ�������ԣ�ͬʱ���ڻ������
	���ǵ�flag��Ҫ��long����ʶ

	| ���� | ��Χ |
	| ------------- |:-------------:|
	|unsigned   int   | 0��4294967295   |
	| int  | 2147483648��2147483647 |
	| unsigned long |0��4294967295|
	| long   |2147483648��2147483647|
	| long long|���ֵ��9223372036854775807|
	| long long|��Сֵ��-9223372036854775808|
	| unsigned long long|���ֵ��1844674407370955161|
	| __int64|���ֵ��9223372036854775807|
	| __int64|��Сֵ��-9223372036854775808|
	| unsigned __int64|���ֵ��18446744073709551615
	*/
	int countNumber2(int n)
	{
		int count = 0;
		int i = 0;
		unsigned long flag = 1;
		//��λ�Ĵ���Ϊ31λ�����һ������λҪ�����ж�
		while ( flag <= INT_MAX)
		{
			if ((n & flag) != 0)
			{
				count++;
			}
			//�ƶ�����λ�����⸺������ѭ��
			//���ֻʣ�·���λ
			flag <<= 1;
		}
		//��������жϷ���λ
		if ((n & flag) != 0)
		{
			count++;
		}
		return count;
	}

	//�Ż�ѭ�����ж�--����ѭ��
	int countNumber3(int n)
	{
		int count = 0;
		int i = 0;
		unsigned long flag = 1;
		//�޸������жϣ��������ض�ʱ���ڽضϴ�ֹͣ
		//���������������Ƶ�32λ
		while (flag != 0)
		{
			if ((n & flag) != 0)
			{
				count++;
			}
			//���ƣ��ֱ��ж�ÿһλ��ֵ
			flag <<= 1;
		}
		return count;
	}

	//���Ż���ѭ���Ĵ����պ��Ƕ������е�1�ĸ���
	/**

* ���n!=0����ô�������λ��������һ��1
* ���n�����λ��1������������ôn-1���ð�������λ��1
  ���0������λ����
* ���n�����λ��0��ż��������ô�����������һ��1λ��mλ
����mλ����ȫ��0����ôn-1�ĵ�mλ��1���0������mλ�������
  ��0�����1��mλ֮ǰ������λ���ֲ��䡣
	
	exg: 1100 & (1100 - 1) =1000 �����������е�1�ĸ�������
	�ı�Ĵ���
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

	//���Ҽ���
	/**  #include <bitset>
	bitset<32> bit(n);
����һ������foo��bitset��
 foo.size() ���ش�С��λ����
 foo.count() ����1�ĸ���
 foo.any() �����Ƿ���1
 foo.none() �����Ƿ�û��1
 foo.set() ȫ�����1
 foo.set(p) ����p + 1λ���1
 foo.set(p, x) ����p + 1λ���x
 foo.reset() ȫ�����0
 foo.reset(p) ����p + 1λ���0
 foo.flip() ȫ��ȡ��
 foo.flip(p) ����p + 1λȡ��
 foo.to_ulong() ������ת��Ϊunsigned long�Ľ�������������Χ�򱨴�
 foo.to_ullong() ������ת��Ϊunsigned long long�Ľ�������������Χ�򱨴�
 foo.to_string() ������ת��Ϊstring�Ľ��
	
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