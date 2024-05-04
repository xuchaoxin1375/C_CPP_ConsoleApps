/*构造函数可以人为编写,但调用一定是自动调用而非人为调用!
有多个构造函数时,则根据传入的参数个数调用对应的结构函数.*/
#include <iostream>
using namespace std;/*记得写上,否自尽管包含了<iostream>也会不到cout对象*/
class Complex {
private:
	double real, imag;
public:
	void Set(double r, double i);
	Complex(double r);
	Complex(double r, double i);
	Complex(Complex c1, Complex c2);
};
Complex::Complex(double r)
{
	real = r;/*接受参数来初始化real成员*/
	imag = 0;/*固定默认imag成员*/

}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex::Complex(Complex c1, Complex c2)
{
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
}

int main()
{
	cout<<"调试中..."<<endl;
	Complex c1(3), /*定义Complex类型的对象c1,同时调用对应道德结构函数初始化c1(函数名旧就不指出了,所有的结构函数都和类名一致,仅在参数列表上有所区别.*/
		c2(1, 2), 
		c3(c1, c2),
		c4 = 7;/*这里c4=7相当于c4(7),是传参的意思.*/

}