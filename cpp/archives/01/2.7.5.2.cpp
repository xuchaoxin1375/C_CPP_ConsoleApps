// program 2.7.5.2.cpp  ���������
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n1 = 15;
	short n2 = 15;
	unsigned short n3 = 15;
	n1 <<= 15;
	cout << "n1=" << showbase << hex << n1 << dec << endl; // ��� n1=78000
	n2 <<= 15;
	cout << "n2=" << showbase << hex << n2 << dec << ";" << n2 << endl; // ��� n2=-32768
	bitset<16> binary(n2);
	cout << binary << endl;
	n3 <<= 15;
	cout << "n2=" << n2 << ",n3=" << n3 << endl; // ��� n2=-32768,n3=32768
	unsigned char c = 7;						 // c�Ķ�������ʽ 0000 0111
	cout << "c<<4=" << (c << 4) << endl;		 // ��� c<<4=112
	c <<= 4;
	cout << "c=" << c; // ��� c=p
	return 0;
}
