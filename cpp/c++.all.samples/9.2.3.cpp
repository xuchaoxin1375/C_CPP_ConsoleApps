//program 9.2.3.cpp ��ƻ��
#include <iostream>
using namespace std;
int Count(int m,int n)
{
	if( m == 0 || n == 1)
		return 1;
	if( n > m)
		return Count(m,m);
	return Count(m,n-1)+Count(m-n,n);
}
int main()
{
	int m,n;
	cin >> m >> n; //m��ƻ����n������
	cout << Count(m,n);
	return 0;
}

