#include <iostream>
#include <stdio.h>
using namespace std;

/////////////////////////////////交换型排序////////////////////////////
/**
@common:快速排序-挖坑+分治（递归）
@param:a为待排序数组，left，right为两个指针
@return:void
@平均时间复杂度：O(N*logN)
@稳定性：不稳定
*/
void  quickSort(int* a, int left, int right)
{
	int i, j;
	int temp;
	if (left >= right)
	{
		return;
	}
	//初始化
	i = left;
	j = right;
	temp = a[i];
	while (i != j)
	{
		//从后向前扫描第一个比temp大的数
		//降序的时候改变从右往左扫描找第一个比temp小的数
		while (i<j && a[j] <= temp) j--;
		if (i<j)
		{
			//换到合适的位置
			a[i++] = a[j];
		}
		while (i<j && a[i] >= temp) i++;
		if (i<j)
		{
			a[j--] = a[i];
		}

	}
	//找到temp的位置
	a[i] = temp;
	//分治，递归左边和右边部分
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}
/**
@common:冒泡排序
@param:a为待排序数组
@return:void
@平均时间复杂度：O(N*N)
@稳定性：稳定
*/
void buddleSort(int* a , int n)
{
	int i, j, temp;
	for (i = 0; i<n; i++)
	{
		//j循环变量初始循环的设置
		for (j = n - i - 1; j<n; j++)
		{
			//交换位置，互换数据
			if (a[j] <= a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////




////////////////////////////////选择型排序//////////////////////////////////////
/**
@common:简单选择排序
@param:a为待排序数组
@return:void
@平均时间复杂度：O(N*N)  空间度复杂度O(1)
@稳定性：不稳定
*/
//交换数组下标对应的值
void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		//先找到最小值，然后把下标复制给min
		for (int j = i; j < n; j++)
		{
			//将下标值赋值给min，即能够找出最小元素的下标值
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr, min, i);
		}
	}
}

/**
@common:堆排序
@param:arr为待排序数组，index为调整的位置，size为数组大小
@return:void
@平均时间复杂度：O(N*logN)  空间度复杂度O(1)
@稳定性：不稳定
*/

//堆的调整
void heapModify(int* arr, int index, int size)
{
	//左孩子和右孩子的下标值
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	//max记录当前最大的下标值

	// 选出当前结点与其左右孩子三者之中的最大值
	int max = index;

	if (left < size && arr[left] > arr[max])
	{
		max = left;
	}
	if (right < size && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != index)
	{
		// 把当前结点和它的最大(直接)子节点进行交换
		swap(arr, max, index);
		//递归调用，继续从当前结点向下进行堆调整
		heapModify(arr, max, size);
	}
}
//建堆，时间复杂度为O(N)
int  buildHeap(int* arr, int n)
{
	int maxSize = n;
	// 从每一个非叶结点开始向下进行堆调整
	for (int i = maxSize / 2 - 1; i >= 0; i--)
	{
		heapModify(arr, i, maxSize);
	}
	//返回最大值
	return maxSize;
}
//堆排序--进行排序
void   heapSort(int* arr, int n)
{
	int size = buildHeap(arr, n);//建立一个最大堆
	while (size > 1)  //堆的元素大小>1,则未完成排序
	{
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		swap(arr, 0, --size);

		// 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
		heapModify(arr, 0, size);
	}
}
////////////////////////////////////////////////////////////////////////////


////////////////////////////////插入型排序//////////////////////////////////////

/**
@common:直接插入排序
@param:a为待排序数组
@return:void
@平均时间复杂度：O(N*N) 空间复杂度O(1)
@稳定性：稳定
*/
void insertSort(int a[],int n)
{
	int i, j;
	int temp;
	for (i = 0; i<n; ++i)
	{
		temp = a[i];
		//从后往前找
		for (j = i - 1; a[j]>temp && j >= 0; j--)
		{
			//大记录后移
			a[j + 1] = a[j];
		}
		if (j != i - 1) a[j + 1] = temp;
	}
}

/*
@common:希尔排序
@param:a为待排序数组
@return:void
@平均时间复杂度：O(N*logN)-O(N*N) 空间复杂度O(1)
@稳定性：不稳定
*/
void swapInt(int * a, int*b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void shell(int*data, int len)
{
	if (len <= 1 || data == NULL)
		return;
	for (int div = len / 2; div >= 1; div = div / 2)//定增量div，并不断减小
	{
		for (int i = 0; i < div; ++i)//分组成div组
		{
			for (int j = i; j < len - div; j += div)//对每组进行插入排序
				for (int k = j; k<len; k += div)
					if (data[j] > data[k])
						swapInt(data + j, data + k);//交换两个数的值
		}
	}
}

//////////////////////////////////////////////////////////////////////////

/*
@common:二分查找--已排好序的数组
@param:a为已排好序的数组，left，right为两个指针，number为待查找的数
@return:void
@平均时间复杂度：O(log2N) 
*/
//BinSearch--inorder
int  binSearch(int* a, int left, int right, int number)
{
	//int  left = m;
	//int  right = n;
	while (left <= right)
	{
		//int mid = right + (left-right) / 2;
		int mid = (left + right) >> 1;
		if (a[mid] == number)
		{
			return mid;
		}
		else if (a[mid] > number)
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

///////////////////////////////////////////////////////////////////////////
/*
@common:归并排序
@param:待排序的数组，辅助数组，开始索引，中间索引，结束的索引
@return:void
@平均时间复杂度：O(N*logN)  空间复杂度为O(N)
*/
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			//复制数组的值(复制小的那部分值)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//内部使用递归
//参数：待排序的数组，辅助数组，开始索引，结束的索引
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		//防止溢出
		midIndex = startIndex + (endIndex - startIndex) / 2;
		//左部
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		//右部
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		//整个数组
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}
//////////////////////////////////////////////////////////////////////////

int main()
{
	int arr[8] = {80,30,50,20,10,90,40,60};
	for (int i = 0; i < 8; i++)
	{
		printf("%d\t", arr[i]);
	}

	//quickSort测试
	quickSort(arr,0,7);
	printf("\n");
	printf("quickSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//buddleSort测试
	buddleSort(arr,8);
	printf("\n");
	printf("buddleSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//selectSort测试
	selectSort(arr,8);
	printf("\n");
	printf("selectSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//heapSort测试
	heapSort(arr, 8);
	printf("\n");
	printf("heapSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//insertSort测试
	insertSort(arr,8);
	printf("\n");
	printf("insertSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//shell测试
	shell(arr,8);
	printf("\n");
	printf("shell排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", arr[j]);
	}

	//MergeSort测试
	int temp[8];
	MergeSort(arr,temp,0,7);
	printf("\n");
	printf("MergeSort排序结果为：\n");
	for (int j = 0; j<8; j++)
	{
		printf("%d\t", temp[j]);
	}
	getchar();
	system("pause");
	return 0;
}