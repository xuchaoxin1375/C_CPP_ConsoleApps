//program 18.5.1.cpp 函数、类、类的成员函数作为 类模板的友元
#include<iostream>
using namespace std;

template <class T>
class Tmpl;

/*全局函数模板:Func1()*/
template <class T>
void Func1(Tmpl<T> &x)
{
	
	cout << "this is a global function :Func1()" << endl<<"\t";
	x.print();

}
/*模板类B*/
template <class T>
class B
{
public:
	void Func(Tmpl<T>& x);
};
/*类模板Tmpl*/
template <class T>
class Tmpl 
{
	T a;
public:
   friend void Func1();//全局友元函数
   friend class A;//友元类A

   template<class T>
   friend void B<T>::Func(Tmpl<T>&);//类B的成员函数作为 类模板Tmpl的友元;
   Tmpl(T a_=0):a(a_)//构造函数
   {
	   cout << "the Tmpl<T>::constructor was called!" << endl;
   }
   void print()
   {
	   cout << "a=" << a << endl;
   }
};

class A
{
	Tmpl<double> obj_in_A;
public:
	void printA()
	{
		cout << "this is a function of class A" << endl;
		
	}
	A(double a_):obj_in_A(a_)
	{
		//obj_in_A.a = a_;
		cout << "从友元类A(普通类A)中访问Tmpl<T>的私有成员a:" <<endl;
		cout << "a=" << obj_in_A.a << endl;
	}
};

template<class T>//不可少
void B<T>:: Func(Tmpl<T>& x)
{
	cout << "this is a function of class B:" << endl;
	cout << "从友元函数(类模板B<T>的函数Func(Tmpl<T>& x))中访问Tmpl<T>的私有成员a:" << endl;
	cout << "x.a=" << x.a<< endl;
}

int main()
{
 	Tmpl<int> i(7); 
	i.print();
	Func1(i);//全局友元函数

	Tmpl<double> f(7.889);
	f.print();

	A obj1(3.14);//类A中有Tmpl<double>类的成员对象,会先调用Tmpl<double>的构造函数.
	B<double> obj2;
	obj2.Func(f);

	B<int> obj3;
	obj3.Func(i);

}
