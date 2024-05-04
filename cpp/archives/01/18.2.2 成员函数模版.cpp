//program 18.2.2.cpp  成员函数模版
#include <iostream>
using namespace std;

/*定义模板类型T
类模板A:*/
template <class T> //可有可无没有的话就不是类模板了
class A/*类模板名*/
{
	T x;
public:
	A(T x_ = 1) :x(x_)
	{
		cout << "constructor was called" << endl;
		cout << "x=" << x << endl;
	}
	/*用到模板类型T2的成员函数模板(调用前,需要将其实例化才可,称之为模板)*/
	template<class T2>  /*可以专门在类模板中为成员函数模板定义一个新的模板类型T2*/
	void Func(T2 t) { cout << t << endl; } //成员函数模板
};
int main()
{
	A<int> a;
	//A a;
	a.Func('K'); //成员函数模板 Func被实例化(模板类型T2被char替代)
	return 0;
}
