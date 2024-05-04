//program 12.3.1.cpp  构造函数，析构函数和变量生存期
#include <iostream>
using namespace std;
class Demo {
	int id;/*这个类的记录器,默认是private.*/
public:	
	 Demo(int i) 	 
     {
		id = i;
		cout << "id=" << id << " constructed" << endl;
	 }
	~Demo()  
     {
		cout << "id=" << id << " destructed" << endl;
	 }
};
Demo d1(1);/*全局变量在main()之前就被初始化完毕,应该首先关注全局对象*/
void Func()  /*全局函数Func()*/
{
	static Demo d2(2);
	Demo d3(3);
	cout << "func" << endl;
}
int main ()  
{
	Demo d4(4);
	d4 = 6;
	cout << "main" << endl;
	{    Demo d5(5); 	
     }
	Func();
	cout << "main ends" << endl;
	return 0;
}

