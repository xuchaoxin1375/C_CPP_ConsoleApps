//program 2.7.3.1.cpp  ��ϵ�����
#include <iostream>
using namespace std;
int main()
{
	int n1 = 4,  n2 = 5,  n3;
	n3 = ( n1 > n2 );   // n3 ��ֵ��Ϊ 0
	cout << n3 << ",";  // ��� 0,
	n3 = ( n1 < n2);    // n3 ��ֵ��Ϊĳ��0ֵ
	cout << n3 << ",";	 // ��� 1,
	n3 = (n1 == 4);     // n3 ��ֵ��Ϊĳ�� 0 ֵ
	cout << n3 << ",";	 // ��� 1,
	n3 = (n1 != 4);     // n3 ��ֵ��Ϊ0
	cout << n3 << ",";	 // ��� 0,
	n3 = (n1 == 5);     // n3 ��ֵ��Ϊ0 
	cout << n3 ;	      // ��� 0,
	return 0;
}

