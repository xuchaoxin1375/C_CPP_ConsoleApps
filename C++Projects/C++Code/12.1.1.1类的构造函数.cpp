/*���캯��������Ϊ��д,������һ�����Զ����ö�����Ϊ����!
�ж�����캯��ʱ,����ݴ���Ĳ����������ö�Ӧ�Ľṹ����.*/
#include <iostream>
using namespace std;/*�ǵ�д��,���Ծ��ܰ�����<iostream>Ҳ�᲻��cout����*/
class Complex {
private:
	double real, imag;
public:
	void Set(double r, double i);
	Complex(double r);
	Complex(double r, double i);
	Complex(Complex c1, Complex c2);
};
Complex::Complex(double r)
{
	real = r;/*���ܲ�������ʼ��real��Ա*/
	imag = 0;/*�̶�Ĭ��imag��Ա*/

}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex::Complex(Complex c1, Complex c2)
{
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
}

int main()
{
	cout<<"������..."<<endl;
	Complex c1(3), /*����Complex���͵Ķ���c1,ͬʱ���ö�Ӧ���½ṹ������ʼ��c1(�������ɾͲ�ָ����,���еĽṹ������������һ��,���ڲ����б�����������.*/
		c2(1, 2), 
		c3(c1, c2),
		c4 = 7;/*����c4=7�൱��c4(7),�Ǵ��ε���˼.*/

}