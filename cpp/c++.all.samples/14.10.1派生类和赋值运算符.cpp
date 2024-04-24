//program 14.10.1.cpp 派生类和赋值运算符
#include <iostream>
using namespace std;
class CBase 
{
	int a;
	public:
		CBase(int a_=0) :a(a_)
		{
			cout << "constructor_of_CBase is called!" << endl;
			cout << "a=" << a << endl;
		}//defult_Args_constructor
		CBase(CBase& c)
		{
			cout << "CBase::copy constructor called" << endl;
		}
		/*overload_constructor;a=b(a,b都是CBase类型的值)等效解释为:a.operator=(b)*/
		CBase& operator=(const CBase& b)	//
		{
			cout << "CBase::opeartor= called" << endl;
			//*this = b;两者是CBase的对象,将而导致反复调用重载的"="
			this->a = b.a;
			return *this;
			
		}
};
class CDerived:public CBase 
{  

	/*在此之前,已经从CBase那里继承过来所有的成员.
	(生成一个CDerived对象当然也优先调用基类CBase的构造函数.*/
	int b;
public:/*不显式声明为公有的化,将无法实例化对象的时候将无法初始化（即便无参/默认参数的constructor也不行）*/
	CDerived(int a_=0,int b_ = 0) :b(b_),CBase(a_)
	{
		cout << "\tconstructor_of_CDerived is called!" << endl;
		cout << "\t\tb=" << b << endl;
	}

	CDerived(CDerived& objBeCopyed)//copy_constructor_of_CDerived(以引用作为参数,提高效率)
	{
		cout << "copy_constructor_of_CDerived is called!" << endl;
		/*在CDerived类中"="没有被重载,在CBase类中"="被重载;而从基类继承过来的那些成员变量在遇到"="会调用在基类CBase中重载中后的"="(即operator=()函数),而派生类中独有的成员变量遇到"="则只是普通的"="而已;(这些赋值在调试过程中会默默的执行掉);
		我们可以看到的过程就是重载后的"="的"复制"过程(根据"="符重载函数的编写情况,未必是做复制工作))*/
		*this = objBeCopyed;//此时*this是CDerived类型的对象,由于CDerived是基类CBase所派生出来的,在基类中对"="运算符进行了重载,.(还要区别于复制构造函数)

		/*派生类中独有的成员变量遇到"="则只是普通的"="而已;(这些赋值在调试过程中会默默的执行掉);*/
	}

};
int main()  
{  		
	CDerived 
		d1(1,1),
		d2(2,2);
	d2 = d1;  //在CDerived类中"="没有被重载,在CBase类中"="被重载;而从基类继承过来的那些成员变量在遇到"="会调用在基类CBase中重载中后的"="(即operator=()函数),而派生类中独有的成员变量遇到"="则只是普通的"="而已;(这些赋值在调试过程中会默默的执行掉)


	/*第一类引发复制构造函数的情况:用一个对象去初始化另一个对象.;(区别于对以对象为参数的函数的调用的情况)*/
	CDerived d3(d2); /*d3初始化过程中会调用CBase类复制构造函数;
					 先调用基类中的构造函数将从基类中继承过来的那部分成员进行初始化
					 
					 我们可以看到的过程就是重载后的"="的"复制"过程(根据"="符重载函数的编写情况,未必是做复制工作));派生类中独有的成员变量遇到"="则只是普通的"="而已;(这些赋值在调试过程中会默默的执行掉);*/
	
	return 0;
}
/*如果需要生成一个临时CDerived类对象:
生成一个临时对象又需要调用构造函数进行初始化,并且CDerived是一个CBase的派生类,先调用基类中的构造函数将从基类中继承过来的那部分成员进行初始化*/
