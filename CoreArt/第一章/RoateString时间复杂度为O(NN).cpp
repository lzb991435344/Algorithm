#include <iostream>
using namespace std;

//当K>N时，右移K-N的位数和右移K位时结果一直
char * RoateString(char* arr,int n,int k)
{
	k%=n;
	while(k--)
	{
		char t=arr[n-1];
		for(int i=n-1;i>0;i--)
		arr[i]=arr[i-1];
		arr[0]=t;
	}
	return arr;
}
int main()
{
	char arr[]="abcd1234";
	RoateString(arr,8,18);
	for(int i=0;i<8;i++)
	{
     cout<<arr[i] <<endl;
	}
	getchar();
	return 0;
}

