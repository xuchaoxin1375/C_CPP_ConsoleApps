//program 20.1.1.cpp  static_castʾ��
#include <iostream>
using namespace std;
class A
{
public:
	operator int()	{ return 1; }
	operator char * (){ return NULL; }
};
int main()
{
	A a;
	int n; char * p = "New Dragon Inn"; 
	n = static_cast<int>(3.14);  // n ��ֵ��Ϊ 3
	n = static_cast<int>(a);     //����a.operator int, n��ֵ��Ϊ 1
	p = static_cast<char*>(a);   //����a.operator int *,p��ֵ��Ϊ NULL
	n = static_cast<int> (p);    //�������static_cast���ܽ�ָ��ת��������
	p = static_cast<char*>(n);   //�������static_cast���ܽ�����ת����ָ��
	return 0;
}

