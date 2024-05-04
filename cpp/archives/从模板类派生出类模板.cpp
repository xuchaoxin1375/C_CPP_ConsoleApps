#include<iostream>
using namespace std;
//从模板类派生出类模板
/*类模板A*/
template <class T1 ,class T2 >
class A
{
protected:
	T1 v1;
	T2 v2;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
		cout << "v2=" << v2 << endl;
	}
	void setA(T1 v1_,T2 v2_)
	{
		v1 = v1_; v2 = v2_;
	}
};

template<class T>
class B :public A<int, double>//A<int,double>是具体的模板类;类模板B从基类A<int,double>共有派生而来
{
	/*此前从A<int,double>基类继承过来所有成员*/
	T v;
public:
	void print()
	{
		cout << "v=" << v << endl;
	}

	void setB(T v_)
	{
		v = v_;
	}
};
int main()
{
	B<char> obj;
	/*此时编译器已经生成两个模板类:B<char>和它的基类A<int,double>*/
	obj.setA(7, 7.77);
	obj.setB('N');
	obj.A<int, double>::print();
	obj.print();
	return 0;
}