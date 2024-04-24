//program 12.5.1.cpp 常量成员函数
#include <iostream>
using namespace std;
class Sample
{
	int a;

public:
	Sample() : a(-1) {}	   //constructor;
	/* 常量成员函数不允许修改成员变量;所有成员变量对于常量成员函数都是只读(而不可改写的) */
	void GetValue() const; //常量成员函数声明
	/*普通成员函数*/
	void test(){
		cout<<"test() was called!"<<endl;
		cout<<"obj.a="<<a<<endl;
		
	};
};
void Sample::GetValue() const
{
	cout << "GetValue() const  was called!" << endl;
	//a += 5;/* 所有成员变量对于常量成员函数都是只读(而不可改写的)  */
	cout<<"obj.a="<<a<<endl;
	
}

int main()
{
	const Sample obj; //定义Sample的一个常量对象obj
	obj.GetValue();			//常量对象上可以执行常量成员函数
	//obj.test(); 常量对象拒绝普通成员函数的访问;
	return 0;
}
/*常量对象上可以执行常量成员函数，是因为常量成员函数确保不会修改任何非静态成员变量的值。编译器如果发现常量成员函数内出现了有可能修改非静态成员变量的语句，就会报错。因此，常置成员函数内部也不允许调用同类的其他非常置成员函颤（静态成员函数除外）。*/