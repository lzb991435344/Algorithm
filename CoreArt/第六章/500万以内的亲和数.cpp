
/**
第一节、亲和数问题
题目描述：
 求500万以内的所有亲和数
如果两个数a和b，a的所有真因数之和等于b,b的所有真因数之和等于a,则称a,b是一对亲和数。
例如220和284，1184和1210，2620和2924。
  220的真因子是：1、2、4、5、10、11、20、22、44、55、110；
284的真因子是：1、2、4、71、142。
而这两个数恰恰等于对方的真因子各自加起来的和（sum[i]表示数i 的各个真因子的和），即
220=1+2+4+71+142=sum[284],
284=1+2+4+5+10+11+20+22+44+55+110=sum[220]。
得284的真因子之和sum[284]=220，且220的真因子之和sum[220]=284，即有sum[220]=sum[sum[284]]=284。


1.看到这个问题后，第一想法是什么？模拟搜索+剪枝？回溯？时间复杂度有多大？其中bn为an的伪亲和数，
 即bn是an的真因数之和大约是多少？至少是10^13（@iicup：N^1.5 对于5*10^6 , 次数大致 10^10 而不是 10^13.）
 的数量级的。那么对于每秒千万次运算的计算机来说，大概在1000多天也就是3年内就可以搞定了（iicup的计算: 10^13 / 10^7 =1000000(秒) 大约 278 小时）。
 如果是基于这个基数在优化，你无法在一天内得到结果的。
2.一个不错的算法应该在半小时之内搞定这个问题，当然这样的算法有很多。节约时间的做法是可以生成伴随数组，也就是空间换时间，
 但是那样，空间代价太大，因为数据规模庞大。
3.在稍后的算法中，依然使用的伴随数组，只不过，因为题目的特殊性，只是它方便和巧妙地利用了下标作为伴随数组，来节约时间。
 同时，将回溯的思想换成递推的思想（预处理数组的时间复杂度为logN（调和级数）*N，扫描数组的时间复杂度为线性O（N）。
 所以，总的时间复杂度为O（N*logN+N）（其中logN为调和级数） ）。


 假设是求10以内的亲和数，求解步骤如下：

 因为所有数的真因数都包含1，所以，先在各个数的下方全部置1

 然后取i=2,3,4,5（i<=10/2），j依次对应的位置为j=（4、6、8、10），（6、9）,（8）,（10）各数所对应的位置。
 依据j所找到的位置，在j所指的各个数的下面加上各个真因子i（i=2、3、4、5）。
 整个过程，即如下图所示（如sum[6]=1+2+3=6，sum[10]=1+2+5=8.）：
 1 2 3 4 5 6 7 8 9 10
 1 1 1 1 1 1 1 1 1 1
 2 2 2 2
 3 3
 4
 5
 然后一次遍历i从220开始到5000000，i每遍历一个数后，
 将i对应的数下面的各个真因子加起来得到一个和sum[i]，如果这个和sum[i]==某个i’，且sum[i‘]=i，
 那么这两个数i和i’，即为一对亲和数。
 i=2；sum[4]+=2，sum[6]+=2，sum[8]+=2，sum[10]+=2，sum[12]+=2...
 i=3，sum[6]+=3，sum[9]+=3...
 ......
 i=220时，sum[220]=284，i=284时，sum[284]=220；即sum[220]=sum[sum[284]]=284，
 得出220与284是一对亲和数。所以，最终输出220、284，...

*/


#include <iostream>
using namespace std;

int sum[5000010];   //为防越界

//时间为O(N*logN)
void  findQinHeNumber()
{
	int i, j;
	//前两次for是logN*N次遍历
	for(i=0;i<5000000;i++)
	{
		//元素置1
		sum[i] = 1;
	}
	//递推
	for (i=2;i+i<5000000;i++)
	{
		//真因子，不能算本身，从2倍开始
		j = i + i;
		while (j<5000000)
		{   
			//将所有i的倍数的位置上加i
			sum[j] += i;
			j += i;
		}
	}
	//扫描O(N)
	for (i=220;i<=5000000;i++)
	{
		//去重，不越界
		if (sum[i]>i && sum[i]<5000000 && sum[sum[i]]==i)
		{
			printf("%d\n%d\n",i,sum[i]);
		}
	}
}
int main()
{

	findQinHeNumber();
	getchar();
	return 0;
}