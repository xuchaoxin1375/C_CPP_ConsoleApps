//program 7.4.1.cpp  ָ����÷�
#include <iostream>
using namespace std;
int main()
{
	int * p1, * p2;
	int n = 4;
	char * pc1, * pc2;
	p1 = (int *) 100;				//��ַp1Ϊ100
	p2 = (int *) 200;				//��ַp2Ϊ200
	cout<< "1) " << p2 - p1 << endl;			//��� 1) 25
	//��� 1) 25, ��Ϊ(200-100)/sizeof(int) = 100/25 = 4
	pc1 = (char * ) p1;				//��ַpc1Ϊ100
	pc2 = (char * ) p2;				//��ַpc2Ϊ200
	cout<< "2) " << pc1 - pc2 << endl;		//��� 2) -100
	//��� 2) -100,��Ϊ(100-200)/sizeof(char) = -100
	cout<< "3) " << (p2 + n) - p1 << endl;		//��� 3) 29
	int * p3 = p2 + n;		// p2 + n ��һ��ָ�룬���������� p3��ֵ
	cout<< "4) " << p3 - p1 << endl;			//��� 4) 29
	cout<< "5) " << (pc2 - 10) - pc1 << endl;  //��� 5) 90
    return 0;
}

