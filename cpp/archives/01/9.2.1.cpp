//program 9.2.1.cpp �ݹ�⺺ŵ������
#include <iostream>
using namespace std;
void Hanoi(int n, char src,char mid,char dest)
//��src���ϵ�n�����ӣ���mid��Ϊ��ת���ƶ���dest��
{
	if( n == 1) {  //ֻ���ƶ�һ������
		cout << src << "->" << dest << endl; //ֱ�ӽ����Ӵ�src�ƶ���dest����
		return ;   //�ݹ���ֹ
	}
	Hanoi(n-1,src,dest,mid); //�Ƚ�n-1�����Ӵ�src�ƶ���mid 
	cout << src << "->" << dest << endl; //�ٽ�һ�����Ӵ�src�ƶ���dest
	Hanoi(n-1,mid,src,dest); //���n-1�����Ӵ�mid�ƶ���dest
     return ;
}
int main()
{
	int n;
	cin >> n; //����������Ŀ
	Hanoi(n,'A','B','C');
	return 0;
}

