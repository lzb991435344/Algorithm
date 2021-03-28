#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
   有序数组合并

*/
int* mergeAB(int* A,int* B,int n,int m)
{
	int end = n + m - 1;
	int j = m - 1;
	int i = n - 1;
	//从后往前移动
	while (j >= 0 && i >= 0)
	{
		if (A[i] > B[j])
		{
			A[end--] = A[i--];
		}
		else
		{
			A[end--] = B[j--];
		}
	}

	//复制数组中的值
	while (j >= 0)
	{
		A[end--] = B[j--];
	}
	return A;
}

int main()
{
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	//int* arr3 = mergeAB(arr1, arr2, 3, 3);
	mergeAB(arr1, arr2, 3, 3);
	for (int i = 0 ; i < 6 ; i++)
	{
		cout << arr1[i]<< endl;
	}
	getchar();
	return 0;
}