#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
   小规模排序，使用堆排序

   已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
   并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。

   给定一个int数组A，同时给定A的大小n和题意中的k，请返回排序后的数组。

   测试样例：
   [2,1,4,3,6,5,8,7,10,9],10,2
   返回：[1,2,3,4,5,6,7,8,9,10]

    由于是几乎有序，每个元素移动的距离可以不超过k，则说明最小的那一个树一定在前k个里面，这样可以考虑用一个小顶堆，
   大小正好为k，每次把堆顶的元素弹出,在把新的元素（后一个元素）加入，一直到剩下最后k个元素，再利用堆排序对剩下的k个元素即可。
*/

//调整堆
void heap_and_just(vector<int> &arr , int start ,int end)
{
	int temp = arr[start];
	int child = 2 * start + 1;
	
	while (child < end)
	{
		//比较当前的节点
		if (child+1 < end &&  arr[child+1] < arr[child])
		{
			child++;
		}
		//三个节点满足条件
		if (temp < arr[child])
		{
			break;
		}	
		//寻找合适的节点
		arr[start] = arr[child];
		start = child;
		child = child * 2 + 1;
	}
	arr[start] = temp;
}

//使用堆排序对前k个数进行排序
vector <int> heapSort(vector<int> arr,int n ,int k)
{
	int i;
	//创建一个k值大小的小根堆
	vector<int> minheap(k);
	////利用数组arr的前K个值初始化小根堆
	for(i=0 ; i < k ; i++)
	{
		minheap[i] = arr[i];
	}
	//调整初始堆
	for (i = k/2 ; i >= 0 ; i--)
	{
		heap_and_just(minheap , i , k);
	}

	//将数组arr的值和小根堆堆顶替换，然后做堆调整。
	for (i = 0 ; i <n-k ; i++)
	{
		arr[i] = minheap[0];
		minheap[0] = arr[i + k];
		heap_and_just(minheap , 0 , k);
	}
//剩下最后k个数，每次调整小根堆，把堆顶元素赋值给arr数组后，就缩小小根堆的大小
	for (i = n-k ; i < n ; i++)
	{
		arr[i] = minheap[0];
		minheap[0] = minheap[k-1];
		heap_and_just(minheap , 0 , k--);
	}
	return arr;
}
int main()
{
	vector<int> v = { 2,1,4,3,6,5,8,7,10,9 };
    vector<int> v2;
	v2=heapSort(v,10,2);
	for (vector<int>::iterator it=v2.begin();it != v2.end() ; it++)
	{
		cout << *it<< endl;
	}
	getchar();
	return 0;
}