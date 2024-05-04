//program 18.1.1.cpp  Swap函数模板(泛型实例)
#include <iostream>
using namespace std;

template <class T>
void Swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int n = 1, m = 2;
	cout << "before swap():" << endl;
	cout << "n=" << n << ","
		 << "m=" << m << endl;
	Swap(n, m); //编译器自动生成 void Swap(int & ,int & )函数
	cout << "after swap():" << endl;
	cout << "n=" << n << ","
		 << "m=" << m << endl;

	double f = 1.2, g = 2.3;
	cout << "before swap():" << endl;
	cout << "f=" << f << ","
		 << "g=" << g << endl;
	Swap(f, g); //编译器自动生成 void Swap(double & ,double & )函数
	cout << "after swap():" << endl;
	cout << "f=" << f << ","
		 << "g=" << g << endl;
	return 0;
}
