//program 7.11.1.1.cpp  ����ָ���÷�
#include <iostream>
using namespace std;
void PrintMin(int a, int b)
{
	if( a<b )
			cout << a;
	else
			cout << b;
}
int main(){
    void (* pf)(int , int);	//���庯��ָ��pf
    int x = 4,  y = 5;			
    pf = PrintMin;			//��PrintMin������ָ��pf���и�ֵ
    pf(x, y);				//����pfָ��ĺ�������PrintMin
    return 0;
}

