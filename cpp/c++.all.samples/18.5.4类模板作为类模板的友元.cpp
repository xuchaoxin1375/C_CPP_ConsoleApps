//program 18.5.4.cpp 类模板作为类模板的友元
/*将...声明为当前类的友元,那么主要被声明的(类/成员函数/全局函数(或他们的模板))获得了访问当前类的私有成员的特权;
要么通过传参(主动声明者的对象为参数)的形式访问,要么同过成员对象的方式来访问成员对象的私有成员.*/
#include <iostream>
using namespace std;
/*类模板A*/
template <class T>
class A
{
	T a;//如果T是一个自定义类(非基础类型),那么A将成为一个封闭类
	public:
		A(T a_=0) :a(a_)
		{
			cout << "A::constructor was called!"<<endl;
		}
		void Func( const T & p)
		{
			cout << "p.v=" << p.v << endl;
		}
};
/*类模板B*/
template <class T>
class B
{
	private :
		T v;
	public:
		B(T n):v(n) 
		{
			cout << "B::constructor was called !" << endl;
		}
	/*//把类模板A声明为友元*/
	template <class T2>
	friend class A;  
};//模板类A(实例化出的模板类中的函数对其所定义的B类成员对象有了访问特权);
int main()
{
	B<int> obj_b(5);

	A<float> obj_a1(3.14);
	A< B<int> > obj_a2(4); /*用B<int>替换A模板中的T,以便A利用"友元关系"访问类模板B的某个实例化的模板类的对象(把B<int>看出double/float之类的类型理解就可;在本程序中，A<B<int>>类，成了B<int >类的友元。
					  这种情况下A类已经是封闭类,A的成员a已变成 成员对象,其类型是B<int>,会调用B<int>的构造函数以初始化a成员*/
	/*体现友元的作用*/
	obj_a2.Func (obj_b);//Func是类A的函数,可以访问B类的(成员对象)的私有成员;这里可以访问到B<int> 类型的对象obj_b
	return 0;
}
