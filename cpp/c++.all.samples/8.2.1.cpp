//program 8.2.1.cpp  ���ϵ�ʾ������
#include <iostream>
using namespace std;
union UTest
{
	int a;
	short b;
	char s[16];
	char c;
};
int main()
{
	UTest u;
	cout << sizeof(u) << endl; //��� 16
	memset(&u, 0,sizeof(u));  //u���ȫ0
	u.a = 0x61626364;
	cout << hex << u.a << "," << u.b << "," << u.c <<  "," << u.s;
     //hex����cout,�˺���������ʮ��������ʽ�������� 61626364,6364,d,dcba
}

