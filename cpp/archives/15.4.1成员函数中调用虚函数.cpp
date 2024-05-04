//program15.4.1.cpp成员函数中调用虚函数
#include < iostream >
using namespace std;
class CBase
{
	int a = 0;
public:
	void func1()
	{/*此时this为CBase* {CDerived} 类型*/
		/*注意到，尽管基类的指针类型是基类的（都告诉你是“基类”指针了，但由于它也兼容其派生类对象的指针（这并不矛盾，因为派生类也是基类（就比如说，🐕类派生出哈巴狗类，说（所有）哈巴狗（都是）狗 也ok的（但不能够反过来说够都是哈巴狗）
		因此在调试的时候，观察到的this指针的类型要小心它即像基类型又像派生类型*/
		cout << "sizeof(*this)=" << sizeof(*this) << endl;/*此为第一次打印的sizeof(*this)=8*/
		cout <<  "this_before_func2:"<<this << endl;
		//func2();//location_2;func2也是某个类的成员函数，它的调用也需要某个对象类出发，这里的对象就是this所指的对象出发的即this->func2()<==>(*this).func2()
		/*version_2;运行结果一样的.*/
		(*this).func2();
		cout << "this_after_func2:"<<this << endl;
		cout << "sizeof(*this)=" << sizeof(*this)<<endl;/*第三次打印的sizeof(*this)=8*/
	}
	/**/
	virtual void func2()
	{
		cout << "sizeof(*this)=" << sizeof(*this);
		cout << "CBase:: func2()" << endl;
	};
};
/*func1不是序函数，func2是虚函数；*/
class CDerived: public CBase
{
	int b = 1;
	/*先从CBase那里继承过来所有成员.*/
public:
	virtual void func2()
	{
		cout << "this_in_func2:"<<this << endl;
		cout << " CDerived:func2()" << endl;
		cout << "sizeof(*this)=" << sizeof(*this)<<endl;/*第二次打印的sizeof（*this）=12 */
	}
	

};
int main()
{
	CDerived d;  
	cout << "&d=" << &d << endl;
	d.func1();
	return 0;
}
/*运行结果：
sizeof(*this)=8
 CDerived:func2()
sizeof(*this)=12
sizeof(*this)=8
*/
/*d.func1成员函数,进入func1函数,调用了func2 函数,
看上去应该调用的是CBase类的func2,但输出结果证明了实际上调用的是CDerived类的func2。
1.知道this->func2()是多态语句
2.this->派生类型(从this表示的地址检测与调用他们的派生类对象d的值的比较中)
虽然观察到的this始终指向的是派生类，但这不代表this的类型最开始就一定不是基类型，基类型指针兼容派生类对象的地址，容易让人感觉this自始至终是派生类型,(基类型的this所指的那个内存地址里,可能存的是基类型对象,也可能是派生类对象;

在基类的func1函数中，“func2();”等价于“this-> func2();”，
(调试的时候看this(或*this)的类型可能有疑惑，由于sizeof的及算方式不够动态，所以看this的地址和最初的那个引起调用的派生类对象d的地址作比较发现，this刚开始=&d；执行func2（）时，this的值变化了，进入到func2（）的函数体中时，this的值回到&d了。)


*/