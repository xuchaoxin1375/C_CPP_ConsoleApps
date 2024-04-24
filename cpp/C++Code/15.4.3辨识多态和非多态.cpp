//program 15.4.3. cpp  区分语句是多态还是非多态
# include < iostream>
using namespace std;
class A
{
public:
	void func1() { cout << "A:: func1" << endl; };
	virtual void func2() { cout << "A:: func2" << endl; };
};
class B :public A
{
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}
	void func2()/*B类中有和其基类A中同名同参数表的func2;同时A类中的func2是虚函数,派生类中的func2 自动成为虚函数*/
	{
		cout << "B::func2" << endl; 
	}
};

class C :public B
{
	//C以A为间接基类,以B为直接基类
public:
	void func1() { cout << "C::func1" << endl; }//func1自动成为虛函数(继承自B类)
	
	void func2() { cout << "C::func2" << endl; }//func2自动成为虚函数(继承自A类)
	
};
int main()
{
	C obj;
	A* pa = &obj;/*间接基类接受派生类对象的指针;完成该语句后pa的类型成为 A*{C} (意思是,pa在定义的时候的类型是A*,而			现在它所指的对象的类型是它的派生类(即C类)的对象.*/
	B* pb = &obj;/*直接基类接受派生类的指针;完成该语句后pa的类型成为 B*{C} (意思是,pa在定义的时候的类型是A*,而			现在它所指的对象的类型是它的派生类(即C类)的对象.*/
	/*但是到目前为止,想要确定一下语句是否为多态语句,要看相关列类中是否有满足要求的多态类(本质有时虚函数)
		基类中没有virtual的函数,那它的派生类中即使有同名虚函数,也无法构成多态语句.*/
	pa->func2();/*A,C类中去找func2看是否都有这样的func2;如果都有,那在此基础上判断func2是否均为虚函数(至少其中(直接/间接)基类中的func2是虚函数是即可;不过一般在类中提前将从(间接/直接)基类继承过来的virtual属性的虚函数标注下,判断这一点,需要把所有间接/直接基类都看过去*/
	//多态
	pa->func1();//该语句不是多态;编译时根据pa的类型,就可以确定func1 就是类A的func1。
	pb->func1();/*看定义它(pb)的B类和最终指向的派生类对象对应的C类;
				对于C类来说,pb是基类B指针,func1是基类B和派生类C中都有的同名、同参数表的虚函数,故这条函数调用语句就是多态。*/
	//多态
	return 0;
}
/*运行结果:
C::func2
 A:: func1
C::func1
*/
/*
* 多态语句离不开(间接/直接)基类和派生类;多态是建立在这两者之上的一种现象.
基类A中func2是虚函数，因此派生类B,C中的func2声明时虽然没有写virtual关键
字,也都自动成为虚函数。

编译时根据pa的类型,就可以确定func1 就是类A的func1。
func1在类B中成为虚函数,那么在B的直接和间接派生类中，func1都自动成为虚函数。


*/