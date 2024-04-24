//program 14.8.1.cpp 基类和派生类指针互相转换
#include <iostream>
using namespace std;
class CBase 
{
	protected:	
		int n;
	public:
		CBase(int i):n(i)  { } //constructor_CBase
		void Print() { cout << "CBase:n=" << n << endl; }
};
class CDerived:public CBase  
{
	public:
		int v;
		CDerived(int i):CBase(i),v(2 * i) { } //constructor_CDerived
		/*member_function_CDerived*/
		void Func() { } ;
		void Print() 
		{ 
			cout << "CDerived:n=" << n << endl;/*n为基类的protected成员变量*/
			cout << "CDerived:v=" << v << endl;
		}
};
int main()  
{  	
	/*为两个类型分别定义一个对象*/
	CDerived objDerived(3); //n=3;v = 6;
	CBase objBase(5);//n=3;

	CBase * pBase = & objDerived ; // 使得基类指针指向派生类对象
	//pBase->Func(); //错, CBase类没有Func()成员函数
	//pBase->v = 5;  //错 CBase类没有v成员变量
	pBase->Print(); //编译器看到的是CBase * pBase,而不会区分析pBase最后是指向CBase类(基类)对象还是是它的派生类Derived类对象
	cout << "1)------------" <<endl;
	//CDerived * pDerived = & objBase; //错，不能将基类指针赋值给派生类指针 
	CDerived * pDerived = (CDerived *)(& objBase); /*基类的兼容性比其派生类要强;派生类(做作值时)就只能接受派生类,基类作左值是既能够接受基类,也能够接受派生类;如过使用强制类型转换,将基类强制转换派生类,从结果上看,"基类间接赋值给派生类"*/
	pDerived->Print();  //慎用，可能出现不可预期的错误（这里的的错误体现在，pDerived所指的那个对象是CBase类型的对象objBase，而objBase中的对象里没有派生类中才有的成员变量v(此时打印这样的变量使会出问题的），由于编译器认类而不认对象的缘故，pDerived会进入派生类CDerived中去访问该类的成员。;
	/*pDerived会进入类CDerived中去访问成员。*/
	cout << "2)------------" <<endl;		
	objDerived.Print();
	cout << "3)------------" <<endl;				
	/*由于....空间发生变化？*/
	cout << "sizeof(CBase)=" << sizeof(CBase) << endl;
	cout << "sizeof(objCBase)=" << sizeof(objBase) << endl;
	cout << "sizeof(CDerived)=" << sizeof(CDerived) << endl;
	cout << "sizeof(*pDerived)=" << sizeof(*pDerived) << endl;

	//pDerived->v= 128;  //往别人的空间里写入数据，会有问题:Stack around the variable 'objBase' was corrupted.
	//objDerived.Print();
	//(*pDerived).Print();
	pDerived->Print();
	
	return 0;
}

/*基类指针 pbase指向派生类对象 objderived，这是合法的。虽然执行完此
行语句后， pbase指向的是派生类对象，尽管基类和派生类都有 Print（）成员函数，而且 pbase指向的是派生类对象，本行依然执行的是
基类的 Print（）成员函数，产生第一行输出。
编译器看到的是哪个类的指针，那么就会认为通
过它访问的，就应该是哪个类的成员，编译器不会分析基类指针到底指向的是基类对象还是
派生类对象*/

/*通过强制类型转换，使得派生类的指针 pderived指向了基类对象 objbase；
pDerived调用的 Print就是 CDerived类的Pint，这是有风险的语句。
在 Cderived对象中，成员变量ν紧换成员变量n存放，

那么执行 pDerivedー>Print(）时，虽然 pderived指向的是一个基类对象，但这不影响
成员变量v的地址计算方式；
*/
/*
存放v位置并不属于objBase对象，可能属于其他变量；该值是不确定且不可预测的，
此处存放什么，不同编译器的处理办法不同；
如果该位置是操作系统规定不可访问的区域，那么程序就可能由于出错而中止
不同编译器在栈上放置局部变量的方式有所不同，用 DevC++编译本程序，输出结果就未必如此
*/