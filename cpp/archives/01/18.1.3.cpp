//program 18.1.3.cpp  函数或函数模板调用语句的匹配顺序示例
#include <iostream>
using namespace std;
/*第一个函数模板*/
template <class T> //定义一个模板类型T
T Max( T a, T b)
{
	cout << "Template Max 1" <<endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
};
/*第二个函数模板(而且是对第一个函数模板的重载,但参数列表发生了变化)*/
//template <class T,class T> //previous declaration as 'class T'//相同名字没必要定义两个;
/* 由于模板参数表类型一样(形参名不一样是不具有区分模板的能力);导致的错误 */
//template <class T>//'template<class T> T Max(T, T)' previously declared here
//template <class T2>//'template<class T> T Max(T, T)' previously declared here

/* */
/*不同模板类型定义语句之间具有区分度的还是所定义的模板类型的个数啊!;不同名字的模板类型只有在同一个模板类型定义语句中才有区分度*/
template <class T,class T2> //定义两个不同的模板类型 T和T2;(同一个模板定义语句中出现几个不同的名字就会产生几个模板类型)
T Max( T a, T2 b)
{
	cout << "Template Max 2" <<endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
}
 
double Max(double a, double b){
	cout << "Function Max" << endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
}
int main() {
	int i=4, j=5;
	cout<<(i<j?i:j)<<endl;
	Max(1.2,3.4);  //调用Max函数
	Max(i,j);     //调用第一个Max模板生成的函数
	Max(1.2,3);   //调用第二个Max模板生成的函数
	return 0;  
}
/* 在有多个函数和函数模板名字相同的情况下，
一条函数调用语句，到底应该被匹配成对哪个函数或对哪个模板的调用呢？
C++编译器遵循以下优先顺序。
（1）先找参数完全匹配的普通函数（非由模板实例化而得的函数）。
（2）再找参数完全匹配的模板函数。
（3）然后找实参数经过自动类型转换后能够匹配的普通函数。
（4）上面的都找不到，则报错。 */
/* 
如果把程序中的普通函数 Max(double a, double b)和第二个Max模板都去掉,
按照上面所说的4条匹配规则,
“Max(1. 2,3) ;”编译时就会报错。
因为从第一个Max模板没法生成与之类型完全匹配的模板函数Max(double,int)。
虽然从该Max模板可以生成int Max(int, int)和double Max( double, doube) ,
但是到底应该把1.2自动转换成int类型然后调用前者,
还是应该把3自动转换成double类型然后调用后者,
看上去都可以，即这是有二义性的。因此编译器会报错。 */
