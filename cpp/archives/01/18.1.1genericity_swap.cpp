//program 18.1.1.cpp  Swap����ģ��(����ʵ��)
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
	Swap(n, m); //�������Զ����� void Swap(int & ,int & )����
	cout << "after swap():" << endl;
	cout << "n=" << n << ","
		 << "m=" << m << endl;

	double f = 1.2, g = 2.3;
	cout << "before swap():" << endl;
	cout << "f=" << f << ","
		 << "g=" << g << endl;
	Swap(f, g); //�������Զ����� void Swap(double & ,double & )����
	cout << "after swap():" << endl;
	cout << "f=" << f << ","
		 << "g=" << g << endl;
	return 0;
}
