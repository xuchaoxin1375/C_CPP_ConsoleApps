//program 9.1.3.cpp ȡ������
#include <iostream> 
#include <cmath>
using namespace std;
const int NUMS = 16;
int num[NUMS + 10]; //���鿪���û����
inline int Bit(int n,int i) { return ( n & (1 << i)); } //��n�ĵ�iλ�Ƿ��0
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int totalSolutions = 0; //�ⷨ����
		for( int i = 0;i < n; ++ i)
			cin >> num[i];
		int tmp = pow(2.0,n);  //�ÿ⺯��pow��2��n�η�
		for( int i = 0; i < tmp; ++ i ) { //ö�����е�ȡ��
			int sum = 0; //ȡ���������ĺ�
			for( int k = 0; k < n; ++ k )
				if(Bit(i,k))  //���i�ĵ�kλΪ1
					sum += num[k]; //ȡ��k��������k��0��ʼ�㣩��
			if( sum % 7 == 0 )
				totalSolutions ++;
		}
		cout << totalSolutions << endl;
	}
	return 0;
}

