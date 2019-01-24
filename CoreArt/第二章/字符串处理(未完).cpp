#include <iostream>
#include <string>
using namespace std;

/**
 5.1 字符串比较问题
题目描述：
假设两个字符串中所含有的字符和个数都相同我们就叫这两个字符串匹配，比如：abcda和adabc,
由于出现的字符个数都是相同，只是顺序不同，所以这两个字符串是匹配的。

要求高效实现下面的函数： boolen Is_Match(char *str1,char *str2)。

分析：可以看出，此字符串的匹配问题，是与上述字符串包含的问题相类似的，这个问题可以先排序再比较，
也可以利用hash表进行判断。这里给出一种hash表的方法

*/

//字符串比较问题
bool isMatch(const char*src,const char* dest)
{
	int len1=strlen(src);
	int len2=strlen(dest);
	//长度不等
	if(len1!=len2)
	{
		return false;
	}
	int hash[26]={0};
	//扫描原字符串
	for(int i=0;i<strlen(src);i++)
	{
		//字符串转换成辅助数组中的索引
		int index=src[i]-'A';
		//对应数组的索引加1，表示字符的个数
		hash[index]++;
	}
	//扫描目标字符串
	for(int j=0;j<strlen(dest);j++)
	{
		int index=dest[j]-'A';
		if(hash[index]!=0)
		{
			hash[index]--;
		}else 
		{
			return false;
		}
	}
	return true;
}

/**
5.2、在字符串中查找子串
题目描述：
给定一个字符串A，要求在A中查找一个子串B。
如A=”ABCDF”，要你在A中查找子串B=“CD”。
*/
int strStr(char* string,char* substring)
{
	int i,j;
	int len1=strlen(string);
	int len2=strlen(substring);
	//时间复杂度为O(M*N)
	for( i=0;i<len1-len2;i++)
	{
		for (j=0;j<len2;j++)
		{
			if(string[i+j]!=substring[j])
			{
				break;
			}
			
		}
		if(j==len2)
		{
			return i+1;
		}
	}
	return 0;
}

/**

题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b
*/

char FirstNotReaptChar1(char* str)
{
	/**int data[256];
	char* p;
	if(str==NULL)  return '/0';
	//初始化为0
	memset(data,0,sizeof(data));
	p=str;
	//遍历字符串
	while(*p!='/0')
	{
		data[(unsigned char) *p++]++;
	}
	//输出第一个只出现一次的字符
	while(*str!='/0')
	{
		if(data[(unsigned char)*str]==1) 
			return *str;
		str++;
	}
	return '/0';*/
	int data[256];
	char *p;

	if (str == NULL)
		return '/0';

	memset(data, 0, sizeof(data));    //数组元素先全部初始化为0
	p = str;
	while (*p != '/0')
		data[(unsigned char)*p++]++;  //遍历字符串，在相应位置++，（同时，下标强制转换）

	while (*str != '/0')
	{
		if (data[(unsigned char)*str] == 1)  //最后，输出那个第一个只出现次数为1的字符
			return *str;

		str++;
	}

	return '/0';

}

//实现方法2
char FirstNotReaptChar2(char* str)
{
	if(!str)
	{
		return '/0';
	}
	const int tableSize=256;
	int hastTable[tableSize]={0};

	char* pHashKey=str;
	while(*(pHashKey)!='/0') hastTable[*(pHashKey++)]++;

	while(*str!='/0')
	{
		if(hastTable[*str]==1)
		{
			return *str;
		}
		str++;
	}
	return '/0';
}

/**字符串转换成数字
//题目：输入一个表示整数的字符串，把该字符串转换成整数并输出。
//例如输入字符串”345”，则输出整数345。

1、由于整数可能不仅仅之含有数字，还有可能以'+'或者'-'开头，表示整数的正负。
 如果第一个字符是'+'号，则不需要做任何操作；如果第一个字符是'-'号，则表明这个整数是个负数，
 在最后的时候我们要把得到的数值变成负数。
2、如果使用的是指针的话，在使用指针之前，我们要做的第一件是判断这个指针是不是为空。
 如果试着去访问空指针，将不可避免地导致程序崩溃（此第2点在下面的程序不需注意，因为没有用到指针）。
3、输入的字符串中可能含有不是数字的字符。
 每当碰到这些非法的字符，我们就没有必要再继续转换。
4、溢出问题。由于输入的数字是以字符串的形式输入，因此有可能输入一个很大的数字转换之后会超过能够
 表示的最大的整数而溢出。
*/


enum Status{kValid=0,kInValid};
int g_Status=kValid;
int str2int(const char* str)
{
	g_Status=kInValid;
	long long num=0;
	if(str!=NULL)
	{
     const char* digit=str;
	 //"+"或者"-"的符号
	 bool minus=false;
	 //正数
	 if(*digit=='+')
	 {
		 digit++;
	 }
	 //负数
	 else if(*digit=='-')
	 {
		 digit++;
		 minus=true;
	 }
	 //字符串中的结尾字符
	 while(*digit!='/0')
	 {
		 //数字
		 if(*digit>=0 && *digit<=9)
		 {
		  num=num*10+(*digit-'0');
		  //溢出
		  if(num>std::numeric_limits<int>::max())
		  {
			  num=0;
			  break;
		  }
		  digit++;
		 }
		 //不是一个数字
		 else
		 {
			 num=0;
			 break;
		 }
	 }
	 if(*digit=='/0')
	 {
		 g_Status=kValid;
		 if(minus)
		 {
			 num=0-num;
		 }
	 }
	}
	return static_cast<int> (num);
}

/**
字符串拷贝
要求实现库函数strcpy，

原型声明：extern char *strcpy(char *dest,char *src); 
功能：把src所指由NULL结束的字符串复制到dest所指的数组中。 　
说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。 　
返回指向dest的指针。

*/
/**
//2分
void strcpy1(char* strDest,char* strSrc)
{
	while((*strDest++==*strSrc++)!='/0');
}
//4分，源字符串加const
void strcpy2(char* strDest,const char* strSrc)
{
	while((*strDest++==*strSrc++)!='/0');
}

//7分-增加断言
void strcpy3(char* strDest,const char* strSrc)
{
	assert((strSrc!=NULL) && (strDest!=NULL));
	while((*strDest++==*strSrc++)!='/0');
}

//10分,增加链式操作，返回目的地址
char* strcpy4(char* strDest,const char* strSrc)
{
	assert( (strDest != NULL) && (strSrc != NULL) );
	char *address = strDest; 
	while( (*strDest++ = * strSrc++) != '/0' ); 
	return address;
}*/

//实现内存拷贝函数，注意当类型是pod对象时才能拷贝

void* memcpyTest(void *dst,const void*src,size_t len)
{
	if(NULL==dst || NULL==src)
	{
		return NULL;
	}
	void* ret=dst;
	//没有内存重叠，从低地址开始复制
	if(dst<=src || (char *)dst>(char*)src+len)
	{
		while(len--)
		{
			*(char*) dst=*(char*)src;
			dst=(char*)dst+1;
			src=(char*)src+1;
		}
	}
	//有内存重叠，从高地址开始复制
	else
	{
		src=(char*)src+len -1;
		dst=(char*)dst+len-1;
		while(len--)
		{
			*(char*)dst=*(char*)src;
			dst=(char*)dst-1;
			src=(char*)src-1;
		}
	}
	return ret;
}
int main()
{
	/**string src="ABBA";
	string dest="BBAA";

	bool ismatch=isMatch(src.c_str(),dest.c_str());
	if(ismatch)
	{
		cout<<"Match!";
	}else 
	{
		cout<<"Not Match！";
	}*/
	
	/**char* string="ABCDEF";
	//字符串的长度
	cout<<strlen(string);
	//字节数
	cout<<sizeof(string);
	char* substring="ABC";
	cout<<strStr(string,substring);*/

	/**char* str="afacced";
	cout<<FirstNotReaptChar2(str);*/
	
	/**char p1[256]="hello world!";
	char p2[256]="";
	memcpyTest(p2,p1,strlen(p1)+1);
	printf("%s\n",p2);*/

	const char* str="90";
	cout<<str2int(str);
	getchar();
	return 0;
}