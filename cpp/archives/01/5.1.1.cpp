//program 5.1.1.cpp  ѡ������
#include <iostream>
using namespace std;
const  int MAX_NUM =100;
int main()
{
	int a[MAX_NUM];
	int n;
	cin >> n; //����n������������ 
	for( int i = 0;i < n ;++i )  //����n������	
		cin >> a[i];
	//���������������д�С��������
	for( int i = 0; i < n - 1; ++i ){  //��i��ѭ����ͽ���iС��Ԫ�طź�
		int tmpMin = i;    //������¼�ӵ�i������n-1��Ԫ���У���С���Ǹ�Ԫ�ص��±�
		for( int j = i; j < n; ++j) {
			if( a[j] < a[tmpMin] ) 
				tmpMin = j;
		}
	 //���潫��iС��Ԫ�ط��ڵ�i��λ���ϣ�����ԭ��ռ�ŵ�i��λ�ӵ��Ǹ�Ԫ��Ų������
		int tmp = a[i];
		a[i] = a[tmpMin];  
		a[tmpMin] = tmp;   
	}
	//�������н�����õ�n��Ԫ�����
	for( int i = 0;i < n ;++i)
		cout << a[i] << endl;
	return 0;
}

