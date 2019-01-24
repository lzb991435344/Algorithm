#include <iostream>

using namespace std;


/** 虚函数修饰的成员函数：
    a、通过基类引用或指针调用基类中定义的函数时，我们并不知道执行函数的对象的确切类型，执行函数的对象可能是基类类型的，也可能是派生类型的。
	非虚函数：
	b、如果调用非虚函数，则无论实际对象是什么类型，都执行基类类型所定义的函数（如上述第1点所述）。如果调用虚函数，则直到运行时才能确定调用哪个函数
	，运行的虚函数是引用所绑定的或指针所指向的对象所属类型定义的版本。*/
class A
{
public:
	virtual void p()
		{
		  cout<< "A"<<endl;
		}

};

class B:public A
{
public:
	virtual void p()
	{
		cout<<"B" <<endl;
	}
};
int main()
{
	A* a=new A();
	A*b=new B();
	a->p();
	b->p();
	delete a;
	delete b;
	getchar();
	return 0;
}