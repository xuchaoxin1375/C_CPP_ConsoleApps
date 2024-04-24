#define _CRT_SECURE_NO_WARNINGS
//program 13.2.1.cpp  重载"="
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
	char* str;

public:
	/*利用初始化列表来建立构造函数(无参默认构造函数String(),该函数讲str初始化为NULL.*/
	String() :str(NULL) { }
	/*带参构造函数:*/
	String( const char* str_)
	{
		str = (char*)str_;
	}
	/*
	返回值str的 类型是const char* 常量指针,以便打印(主要是str成员是私有的时候只能通过同类成员函数来访问到str)
	(即str所指的字符串不能够通过这个str指针来更改(保证安全). */
	const char* c_str()
	{
		return str;/*返回成员变量str字符指针的值(是一个指向字符的地址)*/
	};

	/*声明 名为operator = () 的运算符重载函数'
	运算符重载函数的返回值和形参类型有讲究.*/
	String & operator = (const String & s);/*const char* 的类型比char *的范围更广些 */
	/*声明析构函数.*/

	/*析构函数*/
	//~String()/*析构函数没有参数,但实际上有个this指针.(总有对象来调用它的嘛)*/
	//{
	//	if (str)/*原来非NULL,才有必要进入if来释放内存*/
	//	{
	//		/*以下delete发生错误:(估计在释放s1和s2时发生的错误,它们str所指区域不是通过new到的内存.*/
	//		delete[] str;
	//	}
	//};
};//class String{}

/* "="被重载为string类的(重载运算符)成员函数,可用于深复制的重载"=";
* 使用说明:
要被复制的内容位于参数对象s中.,复制到目标对象*this中(其内存在复制的时候申请) */
String & String::operator = (const String& s) //重载"="以使得 obj = "hello"能够成立
{
	/*s对象参数不会被修改,*this会被修改*/
	if (str == s.str)/*str是引起调用重载运算符函数operator= 的那个对象的成员(也就是说此时的 *this 是第一个操作数);s.str传入函数的第二个参数对象s的成员变量(同时参数对象s是第二个操作数))*/
	{
		return *this;
	}
	if (str)/*this->str*/
	{
		delete[] str;
	}
	if (s.str)
	{
		str = new char[strlen(s.str) + 1];/*为存放所复制字符串的目标对象申请存放字符串的内存*/
		strcpy(str, s.str);
	}
	else
	{
		str = NULL;
	}
	return *this;/*返回当前对象本身*/
}


int main()
{
	String s;
	String s1("test");/*调用带参构造函数*/
	String s2 = "testAgain";/*构造临时对象,调用带参构造函数(而非重载"="的调用)*/
	s = s1;
	cout << s.c_str() << endl;
	//delete[] s.c_str();只需要在最后一次复制后释放即可.
	s = s2;
	cout << s.c_str() << endl;
	delete[] s.c_str();
	return 0;
}

