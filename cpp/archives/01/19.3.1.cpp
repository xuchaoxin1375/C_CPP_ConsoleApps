//program 19.3.1.cpp ��������ʾ��
#include <iostream>
using namespace std;
class CAverage  
{
  public:
	double operator()( int a1, int a2, int a3 ) 
	{ //����() ������� 
		return (double)(a1+a2+a3) / 3;
	}
};
int main()
{
	CAverage average;  //�ܹ�����������ƽ�����ĺ�������
	cout << average(3,2,3); // �ȼ���cout <<average.operator(3,2,3);
	return 0;
}
