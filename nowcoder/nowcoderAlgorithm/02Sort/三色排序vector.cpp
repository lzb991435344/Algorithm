#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/**
  问题：有一个只由0，1，2三种元素构成的整数数组，请使用交换、原地排序而不是使用计数进行排序。
  给定一个只含0，1，2的整数数组A及它的大小，请返回排序后的数组。保证数组大小小于等于500。

测试样例：[0,1,1,0,2,2],6返回：[0,0,1,1,2,2]

思路：这是一个经典的荷兰国旗问题。类似于视频中的快速排序算法（实际我的快排使用成对调换而不是这种方式）。
  要求原地排序而不能使用额外的空间复杂度，要求将0都放在左边，2都放在右边，1都放在中间。思路很简单，
  只有3种值，于是在数组的左边和右边设置一个抽象的空区域{0区域}{2区域}，0区域和2区域各自有一个指针p0,p2,
  初始时p0==-1;p2=n遍历数组p，遇到1就跳过，遇到0时 ，将其与0区域后面的一个元素交换，即先p0++；然后将p与p0元素交换，
  交换之后p++；p0不变；当p遇到2时，要将其与2区域前面的元素交换，先p2--;然后将p与p2的元素交换，交换过后注意p2保持不变，
  对于p由于这个交换过来的值在2区域前面，在原来p的后面，还没有遍历过，并不知道它是0还是1还是2，于是p也保持不变，
  继续对这个元素进行判断，看其是0、1还是2，对于不同的情况作出不同的操作即可，最后当p>=p2时遍历结束，
  所有的元素已经放入到合适的位置了。需要注意的是本题中p0从-1开始；p2从n开始，当要向0区域或者2区域添加元素时是先
  移动指针p0,p2再交换元素
*/

void swap(vector<int> &arr ,int a ,int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

vector<int> soreThreeColor(vector<int> arr , int n)
{
	int i = 0;
	int index_0 = 0;
	int index_2 = n - 1;

	while (i < index_2)
	{
		if (arr[i] == 1)
		{
			i++;
		}else if(arr[i]==0)
		{
			swap(arr, index_0 , i);
			//上一次0出现的下一个位置
			index_0++;
			i++;
		}
		else if(arr[i]==2)
		{
			swap(arr , index_2 , i);
			//和最后一个元素交换之后，回退一个元素
			index_2--;
		}
	}
	return arr;
}

int main()
{
	int arr[6] = { 0,1,1,0,2,2 };
	vector<int> v;
	vector<int> v2;
	for (int i = 0 ; i< 6 ; i++)
	{
		v.push_back(arr[i]);
	}
	v2 = soreThreeColor(v, 6);
	for (vector<int>::iterator it=v2.begin();it!=v2.end();it++)
	{
		cout << *it<< endl;
	}
	getchar();
	return 0;
}