//program 12.1.4.1.cpp  ����ת�����캯��(ֻ��һ�������Ĺ��캯��)
#include <iostream>
using namespace std;
class Complex   {
   public:  
       double  real, imag;
	   Complex( int i)  //����ת�����캯��
	   { 
		   cout << "IntConstructor called" << endl;
		   real = i; imag = 0; 
	   }
	   Complex(double r,double i)
	   {
	   		real = r; imag = i;		  
	   }
};
int main ()
{
	Complex  c1(7,8);
 	Complex  c2 = 12;
 	c1 = 9; // 9���Զ�ת����һ����ʱComplex���� 
 	cout << c1.real << "," << c1.imag << endl;
     return 0;
}
/*Complex��int��������캯����������ת�����캯����
���Կ������ù��캯��-�������������Ρ�

��һ�������ڶ�c2�ĳ�ʼ����
�ڶ��������ڸ�ֵ���: c1 = 9;

������ֵ���ĵȺ����������ǲ�ƥ��ģ�֮���Բ��ᱨ��������ΪComplex��int���������ת�����캯���ܹ�����һ�����Ͳ�����
��ˣ��������ڴ���������ֵ����ʱ����ڵȺ��ұ��Զ�����һ����ʱ��Complex���󣬸���ʱ������9Ϊʵ�Σ���Complex��int��������캯����ʼ����Ȼ���ٽ������ʱ�����ֵ����c1��
Ҳ����˵��9���Զ�ת����һ��Complex����Ȼ���ٸ�ֵ��cl��

Ҫע�⣬��19���ǳ�ʼ���������Ǹ�ֵ��䣬���Բ��Ὣ12ת����һ����ʱ���󣬶���ֱ����12��Ϊ��������Complex��int�����캯������ʼ��c2��*/
