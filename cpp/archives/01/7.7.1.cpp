//program 7.7.1.cpp  ָ�������Ĺ�ϵ
#include <iostream>
using namespace std;
int main()  
{
	int a[200];
	int * p ;
	p = a;				// pָ������a����ʼ��ַ���༴pָ����a[0]
	* p = 10;				//ʹ��a[0] = 10
	*( p + 1 ) = 20;		//ʹ�� a[1] = 20
	p[0] = 30;				// p[i] �� *(p+i) �ǵ�Ч�ģ�ʹ��a[0] = 30
	p[4] = 40;				//ʹ�� a[4] = 40
	for( int i = 0;i < 10; ++i) //��ѭ��������a��ǰ10��Ԫ�ؽ��и�ֵ
		  *( p + i) = i;
	p++;					// pָ�� a[1]
	cout << p[0] << endl;	// ���1  p[0] ��Ч�� * p, p[0]����a[1]
	p = a + 6;				// pָ��a[6]
	cout << * p << endl;	// ��� 6
    return 0;
}

