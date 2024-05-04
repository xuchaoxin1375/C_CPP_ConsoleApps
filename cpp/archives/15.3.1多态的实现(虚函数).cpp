//program 15.3.1. cpp多态类对象的体积
# include < iostream>
using namespace std;
class A
{
public:
	int i;
	virtual void func() { }
	virtual void func2() { }
};
class B :public A
{
	int j;
	virtual void func() { }

};
int main()
{
	cout << "sizeof(A)="<<sizeof(A) << endl
		<< "sizeof(B)="<<sizeof(B); //输出8,12;
	/*派生类B由于继承了基类A的所有成员,所以它的体积是除了自身的成员变量外,还要加上基类的成员*/
	/*对比发现,有了虚函数以后,对象的体积比没有虚函数时多了4个字节。
	实际上,任何有虛函数的类及其派生类的对象,
	都包含这多出来的4个字节,这4个字节就是实现多态的关键,
	它位于对象存储空间的最前端，里面存放的是虚函数表的地址。
*/
	return 0;
}