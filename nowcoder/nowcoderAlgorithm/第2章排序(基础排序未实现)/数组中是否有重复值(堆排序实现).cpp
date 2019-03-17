#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**堆排序--建堆O(N)，调整堆O(logN)
请设计一个高效算法，判断数组中是否有重复值。必须保证额外空间复杂度为O(1)。
给定一个int数组A及它的大小n，请返回它是否有重复值。
测试样例：
[1,2,3,4,5,5,6],7
返回：true

这道题目要求高效，并且要求空间复杂度为O(1).这样就不能用哈希表是实现，只能先排序再遍历实现
经典排序算法空间复杂度如下：
O(1)
冒泡排序，选择排序，插入排序，希尔排序，堆排序
O(logN)~O(N)
快速排序
O(N)
归并排序
O(M)
计数排序和基数排序

所以选择堆排序，并且不能使用递归时间，因为递归函数要如栈，需要额外的空间开销。利用大根堆，循环实现排序

*/
//交换值
void swap(vector<int> arr , int a , int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

//调整堆
void heap_and_just(vector<int> arr ,int parent , int n )
{
	int tmp = arr[parent];//记录父节点值
	int child = parent * 2 + 1;//取出子节点索引

	while (child < n)
	{
		//这里是构建大根堆
		//取两个孩子节点中最大的那个
		if (child + 1 < n && arr[child + 1] > arr[child]) 
		{
			child++;
		}
		//如果父节点大于孩子节点则退出，三个节点满足
		if (tmp > arr[child])
		{
			break;
		}
		//循环向子节点进行
		arr[parent] = arr[child];
		parent = child;
		child = child * 2 + 1;
	}
	//把最初的父节点放回二叉树中
	arr[parent] = tmp;
}

//堆排序
vector<int>  heapSort(vector<int> arr , int n)
{
	//构建初始堆 从n/2开始调整二叉树
	for (int i = n/2 ; i > 0 ; i--)
	{
		heap_and_just(arr , i , n-1);
	}
	//把堆顶元素也就是最大值放到最后，然后每次进行一次堆调整
	for (int i = n-1 ; i > 0 ; i--)
	{
		swap(arr , 0 , i);
		heap_and_just(arr , 0 , i);
	}
	return arr;
}

//检查是否有重复值
bool chkReapte(vector<int> arr , int n)
{
	arr = heapSort(arr,n);
	for (int i = 0 ; i < arr.size()-1 ; i++)
	{
		if (arr[i] == arr[i+1])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	vector<int> v = { 1,2,3,4,5,5,6 };
	cout << chkReapte(v,7) << endl;
	getchar();
	return 0;
}