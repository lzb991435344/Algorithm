#include <iostream >

using namespace std;


char * RoateString(char * arr,int k,int n)
{
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
 // char* res;
  RoateString(arr,4,8);
  for(int i=0;i<8;i++)
  {
   cout<<arr[i]<<endl;
  }
  cout<< sizeof(arr)<<endl; 
  getchar();
  return 0;
}