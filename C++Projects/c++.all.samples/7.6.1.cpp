//program 7.6.1.cpp  ָ����Ϊ��������
#include <iostream>
using namespace std;
void Swap( int *p1,  int *p2)
{
	int tmp = *p1; // ��p1ָ��ı�����ֵ������tmp
	*p1 = *p2;	    // ��p2ָ��ı�����ֵ������p1ָ��ı���
	*p2 = tmp;	    // ��tmp ��ֵ����p2ָ��ı�����
}
int main() 
{
	int m = 3,n = 4;
	Swap( &m, & n); //ʹ��p1ָ��m,p2ָ��n
	cout << m << " " << n << endl; //��� 4 3
    return 0;
}

