//program 7.6.2.cpp  ָ����Ϊ��������Ҳ�Ǵ�ֵ
#include <iostream>
using namespace std;
void Swap(int *p1, int *p2)
{
	int *tmp = p1; //����p1ָ���λ��
	p1 = p2;  //p1ָ��p2ָ���λ��
	p2 = tmp; //p2ָ��p1ԭ��ָ���λ��
}
int main()
{
	int m = 4, n = 3;
	int *pm = & m; //p1ָ��m
	int *pn = & n; //p2ָ��n
	Swap(pm,pn); 
	cout << *pm << "," << *pn;  //��� 4,3
}

