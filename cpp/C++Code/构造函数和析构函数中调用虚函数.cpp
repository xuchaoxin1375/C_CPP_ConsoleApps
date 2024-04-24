# include < iostream >//program15.4.2.cpp构造函数和析构函数中调用虚函数
using namespace std;
class A
{
public:
	virtual void hello()
	{
		cout << "this:" << this << endl;
		cout << " A::hel1o" << endl;
	};
	virtual void bye()
	{
		cout << "this:" << this << endl;
		cout << "A::bye" << endl;
		cout << "this:" << this << endl;
	};
};
class B :public A
{
public:
	virtual void hello() { cout << "B::he11o" << endl; };
	B()
	{
		/* 
		"当前位于B类中;此时this是B*类型的,同时this指向的是B的派生类C类的对象obj(如果构成多态,那么下面调用的hello就会执行obj对象所对应的C类中的hello函数),但由于析构函数调用虚函数不属于多态的现象,*this调用的不是它所指的对象的类型中的函数,而是调用*this类型(也就是B类自己)的同名函数hello(静态联编)" */
		cout << "B::B()" << endl;
		cout << "this:" << this << endl;
		hello();
		cout << "this:" << this << endl;
	}
	~B()
	{
		cout << "this:" << this << endl;
		bye();/*B类自己没有bye函数,再往上一层基类中去找bye()函数*/
		cout << "this:" << this << endl;
	}
};
/*间接派生:*/
class C :public B
{
public:
	virtual void hello() { cout << "C::hello" << endl; }
	C()
	{
		cout << "C::C()" << endl;
	}
};
int main()
{
	C obj;
	cout << "C类对象obj的地址:&obj="<<&obj << endl;
	return 0;//obj对象生成时,会调用B类的构造函数
}
/*
* 在构造函数和析构函数中调用虚函数不是多态的,编译时即可确定调用的是哪个函数:
	如果本类有该函数,调用的就是本类的;
	如果本类没有，调用的就是直接基类的;
	如果直基类还没有,调用的就是间接基类....:

A派生出B,B派生出C。
在B类的构造函数中调用了hello。
由于构造函数中调用虚函数不是多态,所以此时不会调用C类的(尽管obj被定义为是C类的对象)
hello,而是调用B类自己的hello。

obj对象消亡时,会引发B类析构函数的调用,在B类的析构函数中，调用了bye函数。
B类没有自己的bye丽数,只有从基类A继承的bye函数，因此执行的就是A类的bye。

将构造函数中调用虚函数实现为多态,是不合适的。

以上面程序为例,obj对象生成时,要先调用基类构造函数初始化其中的基类部分。
在基类构造函数执行过程中,派生类部分还未完成初始化。
此时在基类B的构造函数中调用派生类C的hello,那么很可能就是不安全的了。

析构函数中调用虚函数不能是多态,原因也是类似的,因为执行到基类的析构函数时,
派生类的析构函数已经执行,派生类对象中的成员变量的值 可能已经不正确了。
*/