#include<iostream>
using namespace std;
class Complex
{
	double real, imag;
public:
	/*��������*/
	Complex(double r = 0, double i = 0) :real(r), imag(i) {}
	/*"+"��Complex�������غ���(��Ա����)*/
	Complex operator+(double r);
	/*��"+"��ȫ�ֵ����غ���������Ϊ�������Ԫ����;(�����ʱ����Ҫfriend һ��.*/
	friend Complex operator + (double r, const Complex& c);

	/*���س�Ա����*/
	double getVarReal()
	{
		return real;
	}
	double getVarImag()
	{
		return imag;
	}
};
/*"+"��Complex�������غ���(��Ա����)*/
Complex Complex:: operator+(double r)/*�����ǵڶ�������������*/
{//����c+5
	return Complex(real + r, imag);/*real+r�����+�������ص�!
								   �������������ʱ����,Ҳ����˵,��ʱ�����real=0, */
}
/*��"+"��ȫ�ֵ����غ���������Ϊ�������Ԫ����;*/
Complex operator+(double r, const Complex& c)
{//����5+c;
	
	return Complex(c.real + r/*ʵ�����*/, c.imag/*�鲿����*/);/*�������������ʱ����(������һ������,ͨ�����캯��������д�뵽�¶����� */
}
int main()
{
	/*ʵ������һЩ����:*/
	Complex n1;
	/*���ݱ��ʽ�Ķ�������Ͱ���˳��,����ö�Ӧ���������������*/
	
	cout << (5+n1).getVarReal() << endl;//���õ���ȫ����Ԫ����.(double r, const Complex& c);�Ƚ���������Ӧ�����������������
	n1 = n1 + 5;//ע���������n1��Ϊ��ֵ��ֵһ��,��ôn1����û��.(����������"+"ʱ����ֵ��һ���������ȥ,������Ȼ�����Ҳ����;
	cout << (n1+5).getVarReal() << endl;//(double r)
}