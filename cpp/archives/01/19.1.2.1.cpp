//program 19.1.2.1.cpp �������÷�ʾ��
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v; // v�Ǵ��int�����Ŀɱ䳤���飬��ʼû��Ԫ��
	for( int n = 0;n < 5; ++n) 
		v.push_back(n); //push_back ��Ա������vector����β�����һ��Ԫ��
	vector<int>::iterator i; //�������������
	for( i = v.begin();i != v.end(); ++i ) { //�õ�������������
		cout << * i << " " ; // * i���ǵ�����iָ���Ԫ��
		*i *= 2; //ÿ��Ԫ�ر�Ϊԭ����2��
	}
	cout << endl;
	//�÷����������������
	for( vector<int>::reverse_iterator j = v.rbegin();j != v.rend (); ++j ) 
		cout << * j << " " ;
	return 0;
}

