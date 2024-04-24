#include<iostream>
using namespace std;
/*欲得到模板类,就必须定义一个类模板,然后从才能从类模板按需求实例化出某个模板类*/

template<class T>
class A
{
	T v1;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
	}
};

/*普通类B 从 模板类A<int> 派生*/
class B :public A<int>//模板类A<int>
{
	int a;
public:
	B(int a_ = 0) :a(a_) { cout << "constructor was called !" << endl; }
	void set(int a_)
	{
		a = a_;
	}
	void print()
	{
		cout << "a=" << a << endl;
	}
};
int main()
{
	B obj(5);
	obj.print();
	obj.set(7);
	obj.print();
}