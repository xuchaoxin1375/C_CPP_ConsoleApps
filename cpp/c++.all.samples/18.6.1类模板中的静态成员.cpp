//program 18.6.1.cpp 类模板中的静态成员
#include <iostream>
using namespace std;

template <class T>
class A
{
 private:
	static int count;//静态成员变量count
public:
 	A() { 
		cout << "A::constructor was called!" << endl;
		count ++;  }
	~A() { count -- ; };

	A( A & ) { count ++ ; }	//copy_constructor
	/*static member function:only can visit the static variable !
	there,it can visit the static variable :count */
	static void PrintCount() { cout << "count="<<count << endl; }
};
/*对 静态成员变量 在类外部加以声明，是必须的:
在外部将类模板A分别实例化为A<int>,A<double> 并分别将其中的静态成员变量count(全局变量)赋值为0;它们是最优先开始执行的语句*/
//template<class T> int A<int>::count = 0;//A<int> 不是类模板;
template<> int A<int>::count = 0;
template<> int A<double>::count = 10;
/*
vs中,可以简写成:
 int A<int>::count = 0;
 int A<double>::count = 10;
*/
int main()
{
 	A<int> ia;
	cout << "ia:";
	ia.PrintCount();
	
 	A<double> da;

	cout << "ia:";
 	ia.PrintCount();
	cout << "da:";
 	da.PrintCount();
	return 0;
}

