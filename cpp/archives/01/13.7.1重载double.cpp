//program 13.7.1.cpp  ����double
#include <iostream>
using namespace std;
class Complex/*������*/
{
   double real,imag;
   public:
	  Complex(double r=0,double i=0):real(r),imag(i) { };//constructor
      /*��double����Ϊ��Complex�ĳ�Ա����:*/
	  operator double () { return real; } //����ǿ������ת������� double
};
int main()
{
 	Complex c(1.2,3.4);
 	cout << "(double)c ="<<(double)c/*������operator double()����:�ȼ��ڡ�c.( operator double����)��*/
        << endl; //��� 1.2
    /*ע��ǿ������ת��һ�㲻�ı䱻ת���Ķ����ֵ,ֻ��������ֻ���� ������ȡ/ת��ĳЩ(��Ա����)ֵ*/
    /*��ʱ��c�����ʼ���Ǹ�c*/
  	double n = 2 + c; //�ȼ��� double n=2(+c.operator double()
    /*n��double���͵���;double �����ñ��ʽ���Ҳ��ֵĲ�����ֵ������һ��,LHS��double,��RHS�ĸ�ֵҲӦ�ñ��double(ǡ��,Complex��Ķ���c���Ե���operator double()��������ת�����õ�double���͵�ֵ,��2���*/
    cout <<"n="<<n<<endl;	//��� 3.2
    double n1;
    n1 = 2+(double)c;
    cout <<"n1="<< n1<<endl;//��� 3.2
    double n2;
    n2 = double (2 + c);//��ʱ�����Ž�����2��Complex����c���,����double��Ա����������,ʹ��RHS��ֵΪdouble����.
    cout <<"n2="<< n2<<endl;
    int n3;
    n3 = double(2 + c);/*��������int������Ϊ��ֵ������double(2+c),���ǻ����ȴ�������c�е�operator double����(��<=>c.operator double()+2<=>(double)c+2;
                       ����,operator double()��һ����Ա������������*/
    cout << "n3=" << n3 << endl;
    int n4;
    n4 = n2;/*���������Ƹ���������ʧС������.*/
    cout << "n4=" << n4 << endl;
}
/*
* 
����ǿ������ת�������ʱ��(����ͷ/��������)��Ҫָ������ֵ���ͣ�
��Ϊ����ֵ������ȷ���ģ������Ǹ��������������ͣ����������double��

���غ��Ч���ǡ���double��c"���͵ȼ��ڡ�c.operator double��������
���˶�double����������أ����ó���double���͵ı��������ĵط���
���������һ��Complex���͵Ķ�����ô�ö����ϵ�operator double��Ա�����ͻᱻ���ã�
Ȼ��ȡ�䷵��ֵ(Complex������real��Ա)ʹ�á�
��������Ϊ�����С�c�����λ��������ֵ���һ��double���͵ı��������Ļ������������ܹ����͵�ͨ(LHS��RHS����һ��,��Ϊdouble��,�������)��
��Complex������������double�������
������о͵ȼ��ڣ�double n = 2 + c.operator double������*/
