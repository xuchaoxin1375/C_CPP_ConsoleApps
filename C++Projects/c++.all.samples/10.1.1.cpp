//program 10.1.1.cpp   ȫ�ֱ����;ֲ�����
#include <iostream>
using namespace std;
int n1 = 5, n2 = 10;
void Function1()
{
	int n3 =4;
	n2 = 3;
}
void Function2()
{
	int n4;
	n1 = 4;
//	n3 = 5;   //�������
}
int main()
{
     n2 = 1;   //�����n2��ȫ�ֱ���n2
	int n5;
	int n2;   //��ȫ�ֱ���n2ͬ������main�������õ��������n2
	if( n1 == 5 ) {
		int n6;
		n6 = 8;
	}
	n1 = 6;
//	n4 = 1;   //�������
//	n6 = 9;	 //�������
	n2 = 7;
	::n2 = 9;   // :: ָ����Ҫ����ǰ����������ȥ��n2 
	return 0;
}

