//program 12.9.2.2.cpp  thisָ������
#include <iostream>
using namespace std;
class Complex {
	public:
	double real, imag;
    Complex(double r,double i):real(r),imag(i) { }
	Complex AddOne() 
	{//��Ϊ��̬��Ա��������������ĳ���������������ڲ��ǲ���ʹ��thisָ���
	    this->real ++;
	    return * this;
	} 
};
int main()
{
 	Complex c1(1,1),
		c2(0,0);
 	c2 = c1.AddOne();/*c1.AddOne() = c1������c2 = c1;
					 ��ʱ��thisָ��= &c1 ��*this = c1;
					 */
 	cout << c2.real << "," << c2.imag << endl;  //��� 2,1
    return 0;
} 
/*this��������Complex*��
��Ϊthis��ָ���������õĶ������ԡ�this->real"��"real����ȫ�ȼ۵ġ�

��*this"�����������õĶ���
����AddOne������ *this��ʵ���Ͼ���cl���c2��ֵ���ú�c1��ͬ��*/
