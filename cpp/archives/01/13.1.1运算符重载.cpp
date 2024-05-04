//program 13.1.1.cpp  运算符重载
#include <iostream>
using namespace std;
class Complex 
{
  public:
    double real,imag;    
    /*利用初始化列表的 构造函数:(函数体往往是空的);
    构造函数的参数表用到默认参数.*/
    Complex( double r = 0.0, double i= 0.0 ):real(r),imag(i)   {     }
    /*将“-”重载为一个成员函数:(往往用const 对象的引用作为重载函数的参数)*/
    Complex operator-(const Complex & c); 
};
/*成员函数operateor- 的定义*/
Complex Complex::operator-(const Complex & c)
{
 	return Complex(real - c.real, imag - c.imag);	//返回一个临时对象(这个临时对象当然也要调用下构造函数来初始化一番.
}
/*将“+”重载为一个全局函数*/
Complex operator+( const Complex & a, const Complex & b)
{
	return Complex( a.real+b.real,a.imag+b.imag); //也会返回一个临时对象
} 

int main()
{
 	Complex 
        a(4,4),
        b(1,1),
        c;/*接受并保存重载运算符"+"的运算结果的对象*/
 	c = a + b; //等价于c=operator+(a,b);
 	cout << c.real << "," << c.imag << endl;
 	cout << (a-b).real << "," 
        << (a-b).imag << endl;//a-b等价于a.operator-(b);也就是说,被定义为成员函数的运算符重载函数在被调用时(调用它的这个对象就会成为这个重载运算符的操作数(运算符函数的参数之一)之一);operator-函数返回的临时对象在本语句结束后消亡.
 	return 0;
}
/*程序将“+”重载为一个全局函数（只是为了演示这种做法，否则还是重载成成员函数更好），
将“-”重载为一个成员函数。
运算符重载为全局函数时，参数的个数等于运算符的数（即操作数的个数）；
重载为成员函数时，参数的个数等于运算符的目数减1.

由于“-”被重载成了Complex类的成员函数，因此，“a-b”就被编译器处理成：a.operator-（b）；
由此就能看出，为什么运算符重载为成员函数时，参数个数要比运算符目数少1了。
*/
