//program 16.6.2.cpp  �������long long���ͺ�double���ͱ���
#include <iostream>
using namespace std;
int main() 
{
	int a;
	float f;
	double df;
	long long n = 9876543210001133LL; //64λ���ͳ���Ҫ�� "LL"��β
	scanf("%x:%e%le,%lld",&a,&f,&df,&n); //�����������е�":"��"��" 
	printf("%d,%x,%f,%lf,%lld",a,a,f,df,n);
	return 0; 
}
