//program 4.5.5.1.cpp  ����������
#include <iostream>
using namespace std;
void Swap( int & a, int & b)
{ //����a,b��ֵ
	int tmp;
	tmp = a; a = b; b = tmp;
}
int main()
{
	int n1 = 100, n2 = 50;
	Swap(n1,n2) ; // n1,n2��ֵ������
	cout << n1 << " " << n2 << endl; //��� 50 100
}

