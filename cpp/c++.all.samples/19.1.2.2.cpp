//program 19.1.2.2.cpp  ����vector����
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v(100); //v����ʼ������100��Ԫ��
	for(int i = 0;i < v.size() ; ++i) //size����Ԫ�ظ���
		cout << v[i]; //����ͨ����һ��ʹ��vector����
	vector<int>::iterator i;
	for( i = v.begin(); i != v.end (); ++i ) //�� != �Ƚ�����������
		cout << * i;
	for( i = v.begin(); i < v.end ();++i) //�� < �Ƚ�����������
		cout << * i;
	i = v.begin();
	while( i < v.end()) { //���һ�����
		cout << * i;  
		i += 2; // ������ʵ�����֧�� "+= ����"  �Ĳ���
	}
}

