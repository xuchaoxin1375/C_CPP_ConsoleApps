#include<iostream>>
using namespace std;
class A
{
public:
	virtual void Print()
	{
		cout << "A::Print" << endl;
	}
};

class B :public A
{
public:
	virtual void Print()
	{
		cout << "B::Print" << endl;
	}
};

void Print(A& r)//形参使用A能够同时兼容传入的基类A型对象(的引用),也能够兼容传入的派生类(的引用)
{
	r.Print();
}

int mian()
{
	A a;
	B b;
	Print(a);
	Print(b);
	return 0;
}