//program 2.7.1.2.cpp  ��������
#include <iostream>
using namespace std;
int main() 
{
	int a = 10;
	int b = 3;
	double d = a/b; //����a��b�������ͣ����Ա��ʽa/b ��ֵҲ�����ͣ���ֵ��3
	cout << d << endl;  //��� 3
	d = 5/2;            //d��ֵ��Ϊ2.0
    cout << d << endl; //��� 2
	d = 5/2.0;          
	cout << d << endl; //��� 2.5
	d = (double)a/b;
	cout << d << endl; //��� 3.33333
    return 0;
}

