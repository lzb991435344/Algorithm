#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
   字符串移位
   将 helloworld 右移两位为 ldhellowor  .
*/
/**
  (1)先把全部字符串翻转
  (2)把（0,len）翻转
  (3)把（len,end）翻转
*/
string moveString(string s, int n, int len)
{
	cout << s << endl;
	reverse(s.begin() + 0, s.end());
	cout << s << endl;
	reverse(s.begin() + 0, s.begin()+len);
	cout << s << endl;
	reverse(s.begin() + len, s.end());
	cout << s << endl;
	//reverse(s.begin(), s.end());
	//cout << s << endl;
	return s;
}
int main(int srgc, char* argv[])
{
	string s = "helloworld";
	cout << moveString(s,10,2) << endl;
	getchar();
	return 0;
}