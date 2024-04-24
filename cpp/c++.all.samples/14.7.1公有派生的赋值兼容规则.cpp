//program 14.7.1.cpp 公有派生的赋值兼容规则
#include<iostream>
using namespace std;
class A
{
	int a = 0;
public:
	void print()
	{
		cout << "a=" << a << endl;
	}
protected:
	void modify()
	{
		a += 2;
	}
};
class B:public A //公有派生
{
	int b = 100;
public:
	void print()
	{
		cout << "Class B" << endl;
		A::print();
	}
	void modify()
	{
		A::modify();/*通过调用基类的公有成员函数来达到间接访问基类的私有成员.;但是注意,modify()最终修改的是B类对象中的成员对象的a,不影响到独立定义的基类对象中的成员变量*/
		cout << "modified!" << endl;
	}
	
};
int main()
{
   A a;
   B b;
   b.print();
   b.modify();
   /*总之,基类对共有派生类有单向的兼容性*/
   a = b; //派生类对象赋值给基类对象 (但也只是将基类中所具有的成员变量做一个值上面的复制(赋值),派生类中所独有的成员变量是不会对基类产生作用.
   A& r = b; //派生类对象初始化基类引用 
   A * pa = & b; //派生类对象地址赋值给基类指针 
   B * pb = & b; 
   pa = pb; //派生类指针赋值给基类指针 
   return 0;
}
