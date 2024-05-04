#include<iostream>
using namespace std;
class Complex
{
	double real, imag;
public:
	/*析构函数*/
	Complex(double r = 0, double i = 0) :real(r), imag(i) {}
	/*"+"在Complex类中重载函数(成员函数)*/
	Complex operator+(double r);
	/*将"+"的全局的重载函数声明名为该类的友元函数;(定义的时候不需要friend 一下.*/
	friend Complex operator + (double r, const Complex& c);

	/*返回成员变量*/
	double getVarReal()
	{
		return real;
	}
	double getVarImag()
	{
		return imag;
	}
};
/*"+"在Complex类中重载函数(成员函数)*/
Complex Complex:: operator+(double r)/*参数是第二个操作数对象*/
{//解释c+5
	return Complex(real + r, imag);/*real+r这里的+不是重载的!
								   返回所构造的临时对象,也就是说,临时对象的real=0, */
}
/*将"+"的全局的重载函数声明名为该类的友元函数;*/
Complex operator+(double r, const Complex& c)
{//解释5+c;
	
	return Complex(c.real + r/*实部相加*/, c.imag/*虚部不变*/);/*返回所构造的临时对象(先生成一个对象,通过构造函数将参数写入到新对象中 */
}
int main()
{
	/*实例化出一些对象:*/
	Complex n1;
	/*根据表达式的对象的类型安排顺序,会调用对应的重载运算符函数*/
	
	cout << (5+n1).getVarReal() << endl;//调用的是全局友元函数.(double r, const Complex& c);先进入参数表对应的重载运算符函数中
	n1 = n1 + 5;//注意如果不讲n1作为左值赋值一下,那么n1还是没变.(除非在重载"+"时将赋值这一步骤包含进去,但这显然多余且不灵活;
	cout << (n1+5).getVarReal() << endl;//(double r)
}