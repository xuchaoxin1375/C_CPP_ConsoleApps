//program 2.7.6.1.cpp  ���������
#include <iostream>
using namespace std;
int main()  
{  		
	int a = 4;
	int b = 5;
	int c = a>b ? a:b; // c = b
	cout << c << endl; //���5
	c = a<b ? a:b;     // c = a  
	cout << c << endl; //���4
	c = 3<5 ? ++a:++b; //++a���㲢��Ϊ����ֵ��++b�����㣬c = 5
	cout << a << "," << b << "," << c << endl; //���5,5,5
	b = 8;
	c = 3>5 ? ++a:++b; //++b���㲢��Ϊ����ֵ��++a������, c = 9
	cout << a << "," << b << "," << c << endl; //���5,9,9
	return 0;
}

