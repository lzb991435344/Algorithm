#include <iostream >
using namespace std;
//二分查找有序数组中的值
int binSearch(int arr[],int n,int value)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
    // int middle=(left+right)/2;
	 int middle=left + ((right-left)>>1);  //防止溢出，移位也更高效。同时，每次循环都需要更新。
	 if(arr[middle]>value)
	 {
		 right=middle-1;
	 }else if(arr[middle]<value)
	 {
		 left=middle+1;
	 }else 
	 {
		 return middle;
	 }
	}
}

int main()
{
	int arr[]={-1,-3,0,3,4,6,8,9,};
	cout<< binSearch(arr,8,8)<<endl;
	getchar();
	return 0;
}

//二分查找时： left <= right，right = middle - 1;left < right，right = middle; 
//算法所操作的区间,是左闭右开区间,还是左闭右闭区间,这个区间,需要在循环初始化,
//循环体是否终止的判断中,以及每次修改left,right区间值这三个地方保持一致,否则就可能出错.

//二分查找实现一
int search(int array[], int n, int v)
{
int left, right, middle;

left = 0, right = n - 1;

while (left <= right)
{
  middle = left + (right-left)/2; 
if (array[middle] > v)
{
right = middle - 1;
}
else if (array[middle] < v)
{
    left = middle + 1;
}
else
{
return middle;
}
}

return -1;
}

//二分查找实现二
int search(int array[], int n, int v)
{
int left, right, middle;

left = 0, right = n;

while (left < right)
{
middle = left + (right-left)/2; 

if (array[middle] > v)
{
right = middle;
}
else if (array[middle] < v)
{
left = middle + 1;
}
else
{
return middle;
}
}

return -1;
}

