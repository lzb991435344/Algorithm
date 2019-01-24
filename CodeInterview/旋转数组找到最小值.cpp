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
>把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
>输入一个非递减序列的一个旋转，输出旋转数组的最小元素。

例如
>数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
>
>该数组的最小值为1。
*/

class findMin
{
public:
	//直接循环找到最小值,时间复杂度O(N)
	int RoateArray(vector<int> arr )
	{
		int min = INT_MAX;
		for (int i=0 ; i < arr.size() ; i++ )
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}

	//最大值后面的即是最小值（通过部分测试用例）
	int RoateArray2(vector<int> arr)
	{
		for (int i = 0 ; i < arr.size() ; i++)
		{
			if (arr[i] > arr[i+1])
			{
				//i位置和i+1位置比较，找到最大值
				//之后返回最大值之后的数组值
                return arr[i + 1];
			}		
		}
		return arr[0];
	}

	//二分法,arr2={1,0,1,1,1}  测试用例
	int binSearch(vector<int> arr)
	{	
		if (arr.size() == 0)
		{
			printf("arrSize error!\n");
		}
		int low = 0;
		int high = arr.size() - 1;
		int mid = low;
		/**if (arr[low] > arr[high])
		{
			printf("arr is not roate!\n");
		}*/
		while (arr[low] >= arr[high])
		{
			if (high - low == 1)
			{
				mid = high;
				break;
			}
			int mid = low + (high - low) / 2;
            //特殊值，只能使用顺序查找，平均时间复杂度是O(N)
			if (arr[low] == arr[mid] && arr[mid] == arr[high])
			{
				//顺序查找
				return inOrder(arr, low, high);
			}
			//mid左边的序列都是递增的子数组
			//目标元素值在数组的mid右边
			else if (arr[mid] >= arr[low])
			{
				 low = mid;
			}//右边是递增的序列，目标在mid的左部寻找
			else if(arr[mid] <= arr[high])
			{
				 high = mid ;
			}
		}
		return arr[mid];
	}
	//顺序查找最小值
	int inOrder(vector<int> &arr , int low ,int high)
	{
		int result = arr[low];
		for (int i = low + 1 ; i < high ; i++)
		{
			if (arr[i] < result)
			{
				result = arr[i];
			}
		}
		return result;
	}
};
int main()
{
	vector<int> arr = { 3,4,5,1,2};
	vector<int> arr2 = {1,0,1,1,1};
	findMin fm;
	//printf("%d\n",fm.RoateArray(arr));
	//printf("%d\n",fm.RoateArray2(arr));
	//printf("%d\n", fm.RoateArray2(arr));//特殊测试用例，结果不符合
	printf("%d\n",fm.binSearch(arr2));
	printf("%d\n",fm.binSearch(arr));
	system("pause");
	getchar();
	return 0;
}