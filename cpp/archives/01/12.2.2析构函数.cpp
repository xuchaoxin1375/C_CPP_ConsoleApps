//program 12.2.2.cpp 析构函数
#include <iostream>
using namespace std;
class CDemo {
	public:
	~CDemo() { cout << "destructor" << endl; }/*析构函数:  ~类名*/
};

void Func(CDemo obj ) /*调用这个以对象为参数的函数,会引发复制构造函数的调用(这里调用的是编译器生成的默认复制函数*/
{
	cout << "func" << endl;
}

CDemo d1;/*全局的CDemo类型对象,在整个程序结束后也会消亡*/
CDemo Test( ) 
{
	cout << "test" << endl;
	return d1;
}

int main(){
	CDemo d2;/*调用默认构造函数*/
	Func(d2);/*调用了复制构造函数,离开此函数后d2的副本对象(参数对象obj)消亡_1*/
	Test();/*返回的临时对象在调用该函数的语句结束后消亡_2*/
	cout << "after test" << endl;
	return 0;/*主函数结束后d2对象消亡_3*/
}
/*整个程序结束,d1对象消亡_4;即,c++中,main函数结束后,可能还有一些善后工作*/

