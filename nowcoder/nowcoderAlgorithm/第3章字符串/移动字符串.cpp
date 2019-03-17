#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
   字符串移位
   将 helloworld 右移两位为 ldhellowor  .
*/
string moveString(string s , int n , int len)
{
	cout << s << endl;
	reverse(s.begin()+0,s.end()+len);
	cout << s<< endl;
	reverse(s.begin()+len,s.end());
	cout << s<< endl;
	reverse(s.begin(),s.end());
	cout << s << endl;
	return s;
}

int main()
{
	string s = "i love you";
	cout << moveString(s,10,2) << endl;
	getchar();
	return 0;
}