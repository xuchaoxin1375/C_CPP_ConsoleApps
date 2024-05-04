//program 12.9.2.2.cpp  this指针作用
#include <iostream>
using namespace std;
class Complex {
	public:
	double real, imag;
    Complex(double r,double i):real(r),imag(i) { }
	Complex AddOne() 
	{//因为静态成员函数并不作用于某个对象，所以在其内部是不能使用this指针的
	    this->real ++;
	    return * this;
	} 
};
int main()
{
 	Complex c1(1,1),
		c2(0,0);
 	c2 = c1.AddOne();/*c1.AddOne() = c1，所以c2 = c1;
					 此时的this指针= &c1 ；*this = c1;
					 */
 	cout << c2.real << "," << c2.imag << endl;  //输出 2,1
    return 0;
} 
/*this的类型是Complex*。
因为this就指向函数所作用的对象，所以“this->real"和"real是完全等价的。

“*this"代表函数所作用的对象，
进入AddOne函数后“ *this”实际上就是cl因此c2的值会变得和c1相同。*/
