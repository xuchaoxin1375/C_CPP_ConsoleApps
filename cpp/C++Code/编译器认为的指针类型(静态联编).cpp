/*
* 编译器认为的指针类型
编译器看到的是类X的指针，那么就会认为通过它访问的就应该是类X的成员；
即:编译器看到的是哪个类的指针，那么就会认为通过它访问的，就应该是哪个类的成员；
*/
#include < iostream >
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A::Print" << endl;
	}
};/*类和类之间用;隔开*/

class B :public A
{
public:
	void Print()
	{
		cout << "B::Print" << endl;
	}
};

int main()
{
	A a;
	B b;


	A* pa = &a;
	B* pb = &b;

	pa->Print();
	pa = pb;
	pa->Print();


	return 0;
}
