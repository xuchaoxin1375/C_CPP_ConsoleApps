//program 16.5.1.cpp  ��cin�ж��������
#include <iostream>
using namespace std;
int main()
{
	int n;
	int maxN = 0;
	while( cin >> n)  {//����û�н�����������Ϊ��
		if( maxN < n )
			maxN = n;
	}
	cout << maxN;
	return 0;
}
