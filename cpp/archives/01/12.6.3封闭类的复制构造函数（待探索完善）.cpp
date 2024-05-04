//program 12.6.3.cpp  封闭类的复制构造函数
#include <iostream>
using namespace std;
class A
{
public:
	int x = 0;
public:
	/*constructor*/
	A() {
		x = 10;
		cout << "default constructor_A" << endl;
	}
	/*copy_constructor*/
	A(A& a) { 
		/*自己编写复制构造函数,尽量做和复制相关的事,否则可能出现形参和实参不等的情况.*/
		/*明确左值和右值:*/
		x = a.x;
		cout << "copy_constructor_of_A_class(defined by me)" << endl;
	}
};
/*封闭类B*/
class B
{
	/*为便于比较,再设定基础类型变量*/
	int p;
		A a;/*不指定作用范围,默认是private*/
		

public:/*成员函数如果不加,导致出错;:不可tmp访问  如果是private也会出错;.*/
		/*B类的默认构造函数:*/
		B() {
			/*进入函数体前会先调用A()*/
			a.x = 100;
			cout << "default constructor_B" << endl;
		}
		/*B类的复制构造函数:*/
		//B(B& b_)
		//{
		//	a = b_.a;/*同类对象之间允许赋值，这里需要复制参数对象的数据，在一级成员的层面赋值即可，不必深入成员对象的成员里赋值*/
		//	cout << "copy_constructor_of_B_class(defined by me)" << endl;
		//}
};
int main()
{
		B b1,/*第一个对象b1*/
			b2(b1);/*第二个对象用b1对象来初始化,调用类B的复制构造函数.*/
		return 0;
}
/*说明b2.a是用类A的复制构造函数初始化的，而且调用复制构造函数时的实参就是
b1.a。
自己编写复制构造函数需要注意:
	复制生成的新对象中的成员变量和成员对象应该得到赋值!*/