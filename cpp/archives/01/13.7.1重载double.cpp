//program 13.7.1.cpp  重载double
#include <iostream>
using namespace std;
class Complex/*复数类*/
{
   double real,imag;
   public:
	  Complex(double r=0,double i=0):real(r),imag(i) { };//constructor
      /*将double重载为类Complex的成员函数:*/
	  operator double () { return real; } //重载强制类型转换运算符 double
};
int main()
{
 	Complex c(1.2,3.4);
 	cout << "(double)c ="<<(double)c/*调用了operator double()函数:等价于“c.( operator double（）)”*/
        << endl; //输出 1.2
    /*注意强制类型转换一般不改变被转换的对象的值,只是用它来只读地 访问提取/转换某些(成员变量)值*/
    /*此时的c还是最开始的那个c*/
  	double n = 2 + c; //等价于 double n=2(+c.operator double()
    /*n是double类型的数;double 会先让表达式左右部分的操作的值的类型一致,LHS的double,那RHS的各值也应该变成double(恰好,Complex类的对象c可以调用operator double()函数进行转换并得到double类型的值,和2相加*/
    cout <<"n="<<n<<endl;	//输出 3.2
    double n1;
    n1 = 2+(double)c;
    cout <<"n1="<< n1<<endl;//输出 3.2
    double n2;
    n2 = double (2 + c);//即时用括号将整形2和Complex类型c相加,由于double成员函数的作用,使得RHS的值为double类型.
    cout <<"n2="<< n2<<endl;
    int n3;
    n3 = double(2 + c);/*即便是用int变量作为左值来接受double(2+c),还是会优先触发对象c中的operator double函数(即<=>c.operator double()+2<=>(double)c+2;
                       其中,operator double()是一个成员函数的整体名*/
    cout << "n3=" << n3 << endl;
    int n4;
    n4 = n2;/*浮点数复制给整形数丢失小数部分.*/
    cout << "n4=" << n4 << endl;
}
/*
* 
重载强制类型转换运算符时，(函数头/函数声明)不要指定返回值类型，
因为返回值类型是确定的，就是那个运算符代表的类型，在这里就是double。

重载后的效果是“（double）c"，就等价于“c.operator double（）”。
有了对double运算符的重载，本该出现double类型的变量或常量的地方，
如果出现了一个Complex类型的对象，那么该对象上的operator double成员函数就会被调用，
然后取其返回值(Complex类对象的real成员)使用。
编译器认为本行中“c”这个位置如果出现的是一个double类型的变量或常量的话，这条语句就能够解释得通(LHS和RHS类型一致,都为double了,允许相加)，
而Complex类正好重载了double运算符，
因而本行就等价于：double n = 2 + c.operator double（）；*/
