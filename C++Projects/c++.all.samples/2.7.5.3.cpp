//program 2.7.5.3.cpp  ���������
#include <iostream>
using namespace std;
int main()
{
	int n1 = 15; 
	short n2 = -15; //n2 ��������ʽ 1111 1111 1111 0001
	unsigned short n3 = 0xffe0;
	unsigned char c = 15;
	n1 = n1>>2;  //n1��ֵ��0xf������2λ�󣬱��0x3
	n2 >>= 3;
	n3 >>= 4;
	c >>= 3; 
	cout << n1 << "," << n2 << "," << hex << n3 << "," << (int)c ;
	return 0;
}

