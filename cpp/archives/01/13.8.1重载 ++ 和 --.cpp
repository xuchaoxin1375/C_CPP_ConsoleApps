//program 13.8.1.cpp, 重载 ++ 和 --
#include <iostream>
using namespace std;
class CDemo {
  private :
	int n;
  public:
	CDemo(int i=0):n(i) { }//constructor
	CDemo operator++();      //用于前置形式
	CDemo operator++( int );   //用于后置形式

     operator int ( ) { return n; }//overload_operator_int
     friend CDemo operator--(CDemo & );
     friend CDemo operator--(CDemo & ,int);    
};
CDemo CDemo::operator++()
{//前置 ++
	n ++;
	return * this;
}
CDemo CDemo::operator++( int k )
{ //后置 ++
	/*后置方式的重载函数中，要多生成一个局部对象tmp;对象的生成会引发构造函数(这里是复制构造数调用，需要耗费时间。*/
	CDemo tmp(*this); //记录修改前的对象(复制构造函数的参数是对象的引用(传入对象本身也是兼容的,在函数体内部还是会成为引用)
	n ++;/*为了区别,写作n+=1更好(由于n只是基础整形数用++也挺快*/
	return tmp; //返回  修改前的 对象
}
CDemo operator--(CDemo & d) 
{//前置--
 	  d.n--;
	  return d; 	  
}
CDemo operator--(CDemo & d,int) 
{//后置--
 	 CDemo tmp(d);
	 d.n --;
	 return tmp;  
}    
int main()
{
	CDemo d(5);
	cout << "d==" << d << ",";
	cout <<"(d++) ==" <<(d++ ) << ",";  //等价于 d.operator++(0);返回的是自增前的值;
	cout << "d=="<<d << ",";
	cout << endl;
	cout <<"++d==" <<(++d) << ",";   //等价于 d.operator++();
	cout << "d="<<d << endl;
	cout << "(d--)="<<(d-- ) << ",";  //等价于 operator-(d,0);
	cout << "d=" << d << ",";
	cout << "--d=="<<(--d) << ",";   //等价于 operator-(d);
	cout << "d=" << d << endl;
	return 0;
}

/*本程序将“++”重载为成员函数，
将“--”重载为全局函数。
其实都重载为成员函数更好,这里将“--”重载为全局函数只是为了说明可以这么做而已。

调用后置形式的重载函数时，对于那个没用的int形参，编译器自动以0作为实参。
“d++”等价于“d.operator ++（0）”。

对比前置“++”和后置“++”的重载，可以发现，
后置“++”的执行效率比前置的低。因为后置方式的重载函数中，要多生成一个局部对象tmp，
而对象的生成会引发构造函数调用，需要耗费时间。同理，后置“--”的执行效率也比前置的低。
在有的编译器中（如VisualStudio2010），如果没有后置形式的重载，那么后置形式的：自增或自减表达式也被当做前置形式处理。
而在有的编译器中（如Dev C++），不进行后置形式的重载，那么后置形式的表达式就会编译出错。*/