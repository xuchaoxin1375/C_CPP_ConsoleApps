//program 15.1.1.cpp多态类和多态的规则
/*调用基类和派生类中都有的同名、同参数表的虚函数 的语句,是符合多态规则的语句.*/
/*多态的语句调用哪个类的成员函数，是在运行时才能确定的，编译时不能确定。
因此多态的函数调用语司被称为是“动态联编”的，而普通的函数调用语句被称为是“静态联编”的。

由于Print是虚函数，尽管pa是基类A的指针，编译时也不能确定调用的是哪个类的Print();(不能够像静态联编那样在编译的时候就确定了指针pa将调用那个类的Print();
当程序运行到 对应语句时,pa指向的是哪个类的对象，被调用的就是哪个类的Print(根据指向的对象所属的类来决定调用那个类的Print();
例如，程序执行到第26行时，pa指向的是基类对象a,那就调用的是基类中的Print();*/
#include < iostream >
using namespace std;
class A
{
public:
	virtual void Print()
	{
		cout << "A::Print" << endl;
	}
};/*类和类之间用;隔开*/

class B :public A
{
public:
	virtual void Print()
	{
		cout << "B::Print" << endl;
	}
};
class D :public A
{
public:
	virtual void Print() { cout << "D::Print" << endl; }
};
class E :public B
{
	virtual void Print() { cout << "E::Print" << endl; }
};

int main()
{
	A a;
	B b;
	D d;
	E e;
	A* pa = &a;
	B* pb = &b;

	pa->Print();
	pa = pb;
	pa->Print();
	pa = &d;
	pa->Print();
	pa = &e;
	pa->Print();
	return 0;
}

//多态,a.Print()被调用,输出:A::Print pa = pb;
//基类指针pa指向派生类对象b pa-> Print();
//b.Print()被调用,输出:B::Print pa =&d;
//基类指针pa指向派生类对象d pa-> Print();
//多态,d.Print()被调用,输出:D::Print pa =&e;
//基类指针pa指向派生类对象d pa-> Print();
//多态,e.Print()被调用,输出:E::Print return 0;
