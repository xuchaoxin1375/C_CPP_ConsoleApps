// program 3.4.2.cpp   ��ţ�ٵ����������������ƽ������
#include <iostream>
using namespace std;
const double EPS = 0.001; // ���Կ��Ƽ��㾫��
int main()
{
	double a;
	cin >> a; // ����a,Ҫ��a��ƽ����
	if (a >= 0)
	{
		double x = a / 2, lastX = x + 1 + EPS; // ȷ���ܹ���������һ�ε���
		while (x - lastX > EPS || lastX - x > EPS)
		{ // ֻҪ����δ��Ҫ�󣬾ͼ�������
			lastX = x;
			x = (x + a / x) / 2;
		}
		cout << x;
	}
	else
		cout << "It can't be nagitive.";
	return 0;
}
