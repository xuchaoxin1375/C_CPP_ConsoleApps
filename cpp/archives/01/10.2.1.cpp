//program 10.2.1.cpp  ��̬�ֲ�����
#include <iostream>
using namespace std;
void Func()
{
	static int n = 4; 
	cout << n << endl;
	++ n;
}
int main()
{
	Func(); Func(); Func();
}

