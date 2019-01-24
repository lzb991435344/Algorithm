#include <iostream>
using namespace std;
/**
3.求子数组的最大和
题目描述：
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。
*/
//时间复杂度为O(N*N*N)
int MaxSum01(const int arr[],int n)
{
	int res=0,curr=0,i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{	
			//重新置0
			curr=0;
			for(k=i;k<j;k++)
			{
				curr+=arr[k];
				if(curr>res)
				{
					res=curr;
				}
			}
		}
	}
	return res;
}
//时间复杂度为O(N*N)
int MaxSum02(const int arr[],int n)
{
	int res=0;
	int cur=0;
	for(int i=0;i<n;i++)
	{
		cur=0;
		for(int j=i;j<n;j++)
		{
			cur+=arr[j];
			if(cur>res)
			{
				res=cur;
			}
		}
	}
	return res;
}
//时间复杂度为O(N*logN) 将序列分成两部分，分3种情况讨论
int MaxSum03(const int A[],int Left,int Right)
{
	int MaxLeftSum,MaxRightSum;              //左、右部分最大连续子序列值。对应情况【1】、【2】
	int MaxLeftBorderSum,MaxRightBorderSum;  //从中间分别到左右两侧的最大连续子序列值，对应case【3】。
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	if(Left == Right)
		if(A[Left]>0)
			return A[Left];
		else
			return 0;
	Center=(Left+Right)/2;
	MaxLeftSum=MaxSum03(A,Left,Center);
	MaxRightSum=MaxSum03(A,Center+1,Right);
	MaxLeftBorderSum=0;
	LeftBorderSum=0;
	for(i=Center;i>=Left;i--)
	{
		LeftBorderSum+=A[i];
		if(LeftBorderSum>MaxLeftBorderSum)
		 MaxLeftBorderSum=LeftBorderSum;
	}
	MaxRightBorderSum=0;
	RightBorderSum=0;
	for(i=Center+1;i<=Right;i++)
	{
		RightBorderSum+=A[i];
		if(RightBorderSum>MaxRightBorderSum)
			MaxRightBorderSum=RightBorderSum;
	}

	int max1=MaxLeftSum>MaxRightSum?MaxLeftSum:MaxRightSum;
	int max2=MaxLeftBorderSum+MaxRightBorderSum;
	return max1>max2?max1:max2;
}

//时间复杂度为O(N)
int MaxSum04(const int arr[],int n)
{ 
	int cur=0;
	int res=0;
	for(int i=0;i<n;i++)
	{
		cur+=arr[i];
		if(cur>res)
		{
			res=cur;
		}
		cur=cur<0?0:cur;
	}
	return res;
}
int main()
{
	int arr[]={1, -2, 3, 10, -4, 7, 2, -5};
	//int arr[]={-1,-2,-3};
	//cout<< MaxSum02(arr,8)<<endl;
	//cout<< MaxSum03(arr,0,7)<<endl;
	//cout<< MaxSum03(arr,0,2)<<endl;
	cout<< MaxSum04(arr,8)<<endl;
	//cout<< MaxSum04(arr,2)<<endl;
	getchar();
	return 0;
}

