#include <iostream>
using namespace std;

/**
  将不变的部分整体移动，递归实现

*/
char* reverse(char* arr,int b,int e)
{
	for(;b<e;b++,e--)
	{
		int temp=arr[b];
		arr[b]=arr[e];
		arr[e]=temp;
	}
	return arr;
}
char * RoateString(char* arr,int n,int k)
{
	k%=n;
	reverse(arr,0,n-k-1);
	reverse(arr,n-k,n-1);
	reverse(arr,0,n-1);
	return arr;
}
int main()
{
	char arr[]="abcd1234";
	RoateString(arr,8,12);
	for(int i=0;i<8;i++)
	{
     cout<<arr[i] <<endl;
	}
	getchar();
	return 0;
}

