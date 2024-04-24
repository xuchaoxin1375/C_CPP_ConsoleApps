//program 12.1.4.1.cpp  类型转换构造函数(只有一个参数的构造函数)
#include <iostream>
using namespace std;
class Complex   {
   public:  
       double  real, imag;
	   Complex( int i)  //类型转换构造函数
	   { 
		   cout << "IntConstructor called" << endl;
		   real = i; imag = 0; 
	   }
	   Complex(double r,double i)
	   {
	   		real = r; imag = i;		  
	   }
};
int main ()
{
	Complex  c1(7,8);
 	Complex  c2 = 12;
 	c1 = 9; // 9被自动转换成一个临时Complex对象 
 	cout << c1.real << "," << c1.imag << endl;
     return 0;
}
/*Complex（int）这个构造函数就是类型转换构造函数。
可以看出，该构造函数-共被调用了两次。

第一次来自于对c2的初始化，
第二次来自于赋值语句: c1 = 9;

这条赋值语句的等号两边类型是不匹配的，之所以不会报错，就是因为Complex（int）这个类型转换构造函数能够接受一个整型参数。
因此，编译器在处理这条赋值语句的时候会在等号右边自动生成一个临时的Complex对象，该临时对象以9为实参，用Complex（int）这个构造函数初始化，然后再将这个临时对象的值赋给c1，
也可以说是9被自动转换成一个Complex对象然后再赋值给cl。

要注意，第19行是初始化语句而不是赋值语句，所以不会将12转换成一个临时对象，而是直接以12作为参数调用Complex（int）构造函数来初始化c2。*/
