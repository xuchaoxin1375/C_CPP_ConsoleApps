//���� 1.1.1 by Guo Wei 
#include <iostream>
using namespace std;
int main()
{
	int n1 = 1378; 
	short n2;
	char c = 'a';
	double d1 = 7.809;
	double d2;
	n2 = c;		//n2��Ϊ97
	cout << "c=" << c << ",n2=" << n2 << endl; 
	c = n1;		//c��Ϊ 'b'
	cout << "c=" << c << ",n1=" << n1 << endl; 
	n1 = d1;		//n1��Ϊ7
	cout << "n1=" << n1 << endl; 
	d2 = n1;		//d2��Ϊ7
	cout << d2 << endl;
    return 0;
}

