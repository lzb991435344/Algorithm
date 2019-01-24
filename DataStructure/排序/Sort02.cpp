#include "pch.h"
#include<stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include<time.h>
using namespace std;

/**
基本的排序算法
(1)quicksort
(2)binsort
*/

//快速排序
void quicksort(int* arr , int left, int right)
{
	int i = left;
	int j = right;
	if (left >= right)
	{
		return ;
	}
	int temp = arr[i];
	/*while (i != j) //从大到小排列
	{
		//从后往前找第一个比temp小的数值,放在合适的位置
		while (i < j && arr[j] <= temp) j--;
		if (i < j)
		{
			arr[i++] = arr[j];
		}
		//从前往后找第一个比temp大的数值,放在合适的位置
		while (i < j && arr[i] >= temp) i++;
		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}*/

	//从小到大排列
	while (i != j)
	{
		//从后往前找第一个比temp大的数值,放在合适的位置
		while (i < j && arr[j] >= temp) j--;
		if (i < j)
		{
			arr[i++] = arr[j];
		}
		//从前往后找第一个比temp小的数值,放在合适的位置
		while (i < j && arr[i] <= temp) i++;
		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}
	arr[i] =temp;//确定arr[i]的位置
	quicksort(arr,0,i - 1);
	quicksort(arr, i + 1, right);	
}
//二分查找
int  binsort(int* arr, int left, int right, int number)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (number == arr[mid])
		{
			return mid;
		}
		//以下变化的是left和right的值
		else if (arr[mid] > number)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

//冒泡排序
void buddlesort(int* arr, int n)
{
	//int temp;
	for (int i = 0 ; i < n ; i++)
	{
		//j的值是从0~n-1
		for (int j =0; j < n - 1 ; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//交换数值
void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//选择排序
void selectsort(int* arr, int n)
{
	for (int i = 0 ; i < n - 1 ; i++)
	{
		int min = i;//当前i定为最小的下标
		//for循环用于寻找最小的值
		for (int j = i; j < n ; j++)
		{
			//下标值更新
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		//交换值,最小的值和当前的i交换
		if (min != i)
		{
			swap(arr,min,i);
		}
	}
}

//插入排序
/*void insertsort(int* arr, int n)
{
	int i, j, temp;
	for (int i = 0 ; i < n ; i++)
	{
		temp = arr[i];

	}
}*/

//字符串处理
/**
   句子逆序，“i love you”处理后变成 “you love i”
*/
string reverseString(string s,const int n)
{
	cout<< s<<endl;
	reverse(s.begin(),s.end());
	cout<< s<<endl;
	int i, j;
	for (i = 0 ; i < n ; i++)
	{
		j = i;
		//找到每一个单词
		while (j < n && s[j] != ' ')
		{
			j++;
		}
		//每个单词进行单独的翻转
		reverse(s.begin()+i,s.begin()+j);
		//i值重新赋值
		i = j;
	}
	return s;
}
int main()
{
	int arr[] = {1,3,2,7,4,9,5,8,6};
	int arr2[] = {1,2,3,4,5,6,7,8,9};
	//quicksort(arr,0,8);
	//buddlesort(arr,9);
	/*selectsort(arr, 9);
	for (int i = 0 ; i < 9 ; i++)
	{
		cout << arr[i] << endl;
	}*/
	//cout << binsort(arr2,0,8,4)<<endl;
	string s = "i love you";
	cout << reverseString(s, 10) << endl;
	getchar();
	system("pause");
	return 0;

}