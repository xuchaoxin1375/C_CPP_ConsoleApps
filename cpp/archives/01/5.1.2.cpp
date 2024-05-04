//program 5.1.2.cpp ɸ��������
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_NUM = 10000000;
bool isPrime[MAX_NUM + 10]; //�������isPrime[i]Ϊtrue�����ʾi������
int main()
{
	for( int i = 2;i <= MAX_NUM; ++i) //��ʼ������������������
		isPrime[i] = true;
	for( int i = 2;i <= MAX_NUM; ++i) { //ÿ�ν�һ�����������б������Ϊ������
		if( isPrime[i])  //ֻ��������ı���
			for( int j = 2 * i; j <= MAX_NUM; j += i)
				isPrime[j] = false; //������ i �ı������Ϊ������
	}
	for( int i = 2;i <= MAX_NUM; ++i) 
		if( isPrime[i])
			cout << i << endl;
	return 0;
}

