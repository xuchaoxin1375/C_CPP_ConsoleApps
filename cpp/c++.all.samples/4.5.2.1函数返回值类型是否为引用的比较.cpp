//program 4.5.3.1.cpp  ������Ϊ��������ֵ
#include <iostream>
#define TURN_Reference 1/*�޸�Ϊ0,�������Ƿ���ֵΪ���������͵����*/
using namespace std;
int n = 4;

/*Ԥ���봦�����䲻Ҫ�й���Ļ�����*/
#if TURN_Reference

int& SetValue()
{
	return n;  //���ض�n������
}

#else

int SetValue()
{
	return n;
}

#endif


int main()
{
	SetValue() = 40;   /*����ֵ�����õĺ������ñ��ʽ��������Ϊ��ֵʹ��;����˴�SetValue(),������һ������Ϊint& ��(����)������,����ֵ�����¸�ֵΪ40��,setValue()==40;���SetValue()���ص���int(�Ǹ�����ֵ,ͬʱ���ܹ���Ϊ��ֵ����������ʼ��),��,���Ƿ���������,��ô�Ͳ��ܹ���SetValue()��Ϊ���ʽ��ֵ
	*/
	cout << n << endl; //��� 40
	int& r = SetValue();/*��SetValue()����ʼ���¶����int&���͵�����r;rҲ��=40;*/
	cout << r << endl; //��� 40
	return 0;
}


