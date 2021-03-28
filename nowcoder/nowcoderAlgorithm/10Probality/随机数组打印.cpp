
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

/**
  题目：随机打印M个数，使得他们随机打印的时候的概率是一致的，也就是等概率打印
    随机打印M个数 每次打印一个数之后就把这个数放到末尾，主要作用就是使得下一次打印
 时不会再有机会出现，这样每次打印的过程中的每一个数的概率都是相等的


 分析：主要是把当前的打印值换到vector的末尾，同时将已打印的元素排除在外，保证等概率地抽到剩下的数
  具体过程如下：
　　1、在arr[0…N-1]中随机得到一个位置a，然后打印arr[a]。 
　　2、把arr[a]和arr[N-1]交换。 
　　3、在arr[0…N-2]中随机得到一个位置b，然后打印arr[b]，因为打印过的arr[a]已经被换到了N-1位置，
     所以这次打印不可能在出现。 
　　4、把arr[b]和arr[N-2]交换。 
　　5、在arr[0…N-3]中随机得到一个位置c，然后打印arr[c]，因为打印过的arr[a]和arr[b]已经被换到
     了N-1位置和N-2位置，所以这次打印不可能在出现。 
　　6、依次类推直到打印M个数 
　 总之，就是把随机选出来的数打印出来，然后将打印的数交换到范围中的最后位置，再把范围缩小，
   使得被打印的数下次不可能再被选中，直到打印结束。
 
*/
/**class RandomPrint
{
public:
	//交换数组中两个数的的值
	void swap(vector<int> arr,int a ,int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	//打印数组
	vector<int> print(vector<int> arr , int m ,int n)
	{
		vector<int> res;
		for (int i=0 ; i < m ; i++)
		{
			int r = rand() % (n);
			res.push_back(arr[r]);
			swap(arr,arr[r],arr[n-1]);
			n--;
		}
		return res;
	}
};*/
class RandomPrint {
public:
	vector<int> print(vector<int> arr, int N, int M) {
		vector<int> res(M);
		int index;
		for (int i = 0; i<M; i++) {
			index = rand() % N;
			res[i] = arr[index];
		}
		return res;
	}
};

int main()
{
	RandomPrint rp;
	vector<int> arr = {1,2,3,4,5,6};
	vector<int> res= rp.print(arr,6,3);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		cout << *it << endl;
	}
	//printf("%d",rand()%5);
	system("pause");
	getchar();
	return 0;
}