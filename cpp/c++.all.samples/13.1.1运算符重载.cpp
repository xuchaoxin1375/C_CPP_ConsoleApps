//program 13.1.1.cpp  ���������
#include <iostream>
using namespace std;
class Complex 
{
  public:
    double real,imag;    
    /*���ó�ʼ���б�� ���캯��:(�����������ǿյ�);
    ���캯���Ĳ������õ�Ĭ�ϲ���.*/
    Complex( double r = 0.0, double i= 0.0 ):real(r),imag(i)   {     }
    /*����-������Ϊһ����Ա����:(������const �����������Ϊ���غ����Ĳ���)*/
    Complex operator-(const Complex & c); 
};
/*��Ա����operateor- �Ķ���*/
Complex Complex::operator-(const Complex & c)
{
 	return Complex(real - c.real, imag - c.imag);	//����һ����ʱ����(�����ʱ����ȻҲҪ�����¹��캯������ʼ��һ��.
}
/*����+������Ϊһ��ȫ�ֺ���*/
Complex operator+( const Complex & a, const Complex & b)
{
	return Complex( a.real+b.real,a.imag+b.imag); //Ҳ�᷵��һ����ʱ����
} 

int main()
{
 	Complex 
        a(4,4),
        b(1,1),
        c;/*���ܲ��������������"+"���������Ķ���*/
 	c = a + b; //�ȼ���c=operator+(a,b);
 	cout << c.real << "," << c.imag << endl;
 	cout << (a-b).real << "," 
        << (a-b).imag << endl;//a-b�ȼ���a.operator-(b);Ҳ����˵,������Ϊ��Ա��������������غ����ڱ�����ʱ(���������������ͻ��Ϊ�������������Ĳ�����(����������Ĳ���֮һ)֮һ);operator-�������ص���ʱ�����ڱ�������������.
 	return 0;
}
/*���򽫡�+������Ϊһ��ȫ�ֺ�����ֻ��Ϊ����ʾ�������������������سɳ�Ա�������ã���
����-������Ϊһ����Ա������
���������Ϊȫ�ֺ���ʱ�������ĸ���������������������������ĸ�������
����Ϊ��Ա����ʱ�������ĸ��������������Ŀ����1.

���ڡ�-�������س���Complex��ĳ�Ա��������ˣ���a-b���ͱ�����������ɣ�a.operator-��b����
�ɴ˾��ܿ�����Ϊʲô���������Ϊ��Ա����ʱ����������Ҫ�������Ŀ����1�ˡ�
*/
