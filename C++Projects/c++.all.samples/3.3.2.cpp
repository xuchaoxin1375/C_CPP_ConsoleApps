//program 3.3.2.cpp  ȡ������ʹ�ú�����һ���������ӣ��ж�����ȡ��
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	int total = 0;  //ȡ������
	cin >> n >> m;  //��1...n��n������ȡ������������m���� 
	for( int i = 1; i < n; ++i )  //ȡ��һ��������n-1��ȡ��
		for( int j = i + 1; j <= n; ++j ) //�ڶ�����Ҫ�ȵ�һ������,����ȡ���ظ�
			if( m % (i + j) == 0 )
		  		  ++ total ;
     cout << total;  
  	return 0;
}
