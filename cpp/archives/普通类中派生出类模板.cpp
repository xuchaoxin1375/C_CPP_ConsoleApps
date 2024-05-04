#include<iostream>
using namespace std;

/*普通类A*/
class A
{
protected:
	int v1;
	double v2;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
		cout << "v2=" << v2 << endl;
	}
	void setA(int v1_, double v2_)
	{
		v1 = v1_; v2 = v2_;
	}
};

template<class T>
class B :public A
{
	/*此前从基类A继承过来所有成员*/
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
	obj.setA(7, 7.677);
	obj.setB('N');
	obj.A::print();
	obj.print();
	return 0;
}