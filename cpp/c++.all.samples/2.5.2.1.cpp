#include <iostream>
using namespace std;
int main()
{
	int n1 = 1378;  //1378��ʮ��������ʽ�� 0x562
	short n2;
	char c = 'a';
	double d1 = 7.809;
	double d2;
	n2 = c;		//n2��Ϊ97 , 97��'a'��ASCII��
	cout << "c=" << c << ",n2=" << n2 << endl; //��� c=a,n2=97
	c = n1;		// n1��0x562, 0x62������ASCII�븳ֵ��c,c��Ϊ 'b'
	cout << "c=" << c << ",n1=" << n1 << endl; //��� c=b,n1=1378
	n1 = d1;		// d1=7.809, ȥ��С�����ֺ�ֵ��n1,n1��Ϊ7
	cout << "n1=" << n1 << endl;   //��� n1=7
	d2 = n1;		//d2��Ϊ7
	cout << d2 << endl;  //��� d2=7.000000
    return 0;
}
