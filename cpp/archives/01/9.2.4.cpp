//program 9.2.4.cpp N�ʺ�����
#include <iostream>
#include <cmath>
using namespace std;
int N; //��N���ʺ�
int  queenPos[1000]; //���������õĻʺ�λ��
void NQueen( int n)  //�ڷŵ�n���ʺ󡣻ʺ��Ŵ�0��ʼ��
{
	int i;
	if( n == N ) { // N ���ʺ��Ѿ��ں�
		for( i = 0; i < n;++i ) //�����
			cout << queenPos[i] << " ";
		cout << endl;
		return ;
	}
	for( i = 0;i < N; ++i) { //���Ե�n���ʺ��λ��
		int j;
		for( j = 0; j < n; ++j ) { 
			//���Ѿ��ںõ� n ���ʺ��λ�ñȽϣ����Ƿ��ͻ
			if( queenPos[j] == i || 
				abs(queenPos[j] - i) == abs(n-j)) {
				break; //��ͻ��������һ��λ��
			}
		}
		if( j == n ) { //��ǰѡ��λ�� i ����ͻ
			queenPos[n] = i; //����n���ʺ�ڷ���λ�� i
			NQueen(n+1);     //�ڷŵ�n+1���ʺ�
		}
	}
}
int main()
{
	cin >> N;
	NQueen(0); //�ӵ�0���ʺ�ʼ�ڷ�
	return 0;
}

