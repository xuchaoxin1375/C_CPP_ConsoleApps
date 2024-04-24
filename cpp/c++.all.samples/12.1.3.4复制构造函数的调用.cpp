//program 12.1.3.4.cpp  复制构造函数用于函数返回对象
#include <iostream>
using namespace std;

class A 
{
   public:
   int v;
   /*普通构造函数(用于初始化对象)*/
   A(int n) { v = n; };

   /*复制构造函数:*/
   A( const A & a) { 
  	  v = a.v;
   	  cout << "Copy constructor called" <<endl;
   }		
};
A Func()
{
   A a(4);/*调用构造函数初始化对象a,参数直接跟在对象a后面,且用括号引起来,看起来像调用函数,其实也的确调用了函数,不过函数名是和类名相同的构造函数,这里函数名没有写(A),所以又不是一般意义上的调用函数*/
   return a;/*按照标准C++的话,会调用复制构造函数*/
}
int main(){
	cout << Func().v << endl;
	return 0;
}

