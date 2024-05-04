
//program 18.5.3.cpp  类也可以将 函数模板声明为友元
#include <iostream>
using namespace std;

class A
{
	int v;
public:
	A(int n) :v(n)
	{
		cout << "A:: theconstructor was called!" << endl;
	}

	template <class T>
	friend void Print(const T& p);//全局函数模板Print<T>实例化出来的模板函数就可以访问A类对象参数的私有成员;
};
/*全局函数模板Print(参数是某个类的对象)*/
template <class T>
void Print(const T& p)
{
	cout <<"p.v="<< p.v<<endl;
}

int main()
{
	A a(4);
	/*调用全局函数模板友实例化的模板函数:此处的函数模板的实例化通过对象a隐式实例化成模板函数Print<const A& p>*/
	Print(a);
	return 0;
}

