//program 2.6.1.1.cpp
#include <iostream>
using namespace std;
int main()
{
		int a ,b = 100;
		unsigned int c;
		a = 0xffffffff; //a�з��ţ���˸�ֵ����ֵΪ-1
		c = 0xffffffff; //c���޷�����������˸�ֵ����ֵΪ 4294967295
		cout << a << "," << c << endl; //���  -1, 4294967295
		cout << a - b << "," << c - b << endl; //��� -101,4294967195
		return 0;
}

