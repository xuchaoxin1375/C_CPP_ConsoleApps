//program 13.6.1.cpp  ���� << �� >>
/*�ٶ� c��Complex������Ķ���
����ϣ��
��д��cout<< c�����������ԡ�a+bi������ʽ���c��ֵ��

��д"cin>> c���������ܴӼ��̽��ܡ�a+bi����ʽ�����룬
���c.real=a ; c.imag=b; 
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex 
{
	  double real,imag;	   
public:
      Complex( double r=0, double i=0):real(r),imag(i){ }; //initial_construcotr
      friend ostream & operator<<( ostream & os,const Complex & c);//friend_overload_operator_<<
      friend istream & operator>>( istream & is,Complex & c);      //friend_overload_operator_>>
};//class Complex{};
/*ȫ�������������.*/
/*����iostream�е�ostream��*/
ostream & operator<<( ostream & os,const Complex & c)
{
    /*os������cout,����ostream��Ķ���;����os�β�����������cout�����*/
	os << c.real << "+" << c.imag << "i"; //��"a+bi"����ʽ��� 
	return os;
} 
istream & operator>>( istream & is,Complex & c)
{
    string s;
    is >> s;  //��"a+bi"��Ϊ�ַ�������, "a+bi" �м䲻���пո�(a,b���ܶ��Ƕ�λ��)
    /*��������s���ַ���*/
    int pos = s.find("+",0); /*string���find()���Һ���,����"+"��λ��*/

    string sTmp = s.substr(0,pos); //���������ʵ�����ַ��� 
    c.real = atof(sTmp.c_str());//atof�⺯���ܽ�const char*ָ��ָ�������ת���� float 

    sTmp = s.substr(pos+1, s.length()-pos-2);   //����������鲿���ַ���
    c.imag = atof(sTmp.c_str());
	return is;
}
int main()
{
  	Complex c;
  	int n; 
  	cin >> c >> n; /*����һ��������һ��ʵ��:13.2+133.4i 87*/
  	cout << c << "," << n;
  	return 0;
}
/*��Ϊû�а취�޸�ostream���istream�࣬����ֻ�ܽ���<<���͡�>>������Ϊȫ�ֺ�������ʽ��
����������������Ҫ����Complex���˽�г�Ա�����Complex�ඨ���н���������Ϊ��Ԫ����cout<< c���ᱻ���ͳ�operator<<(cout,c)��"��ô��дoperator<<����ʱ���������������Ͳ���ȷ����
����OSֻ����ostream�����ã���������ostream������Ϊostream�ĸ��ƹ��캯����˽�еģ�û�а취����ostream��������
operator<<<�����ķ���ֵ������Ϊostream&�����ҷ���os�����ܹ�ʵ�֡�< <��������ʹ�ã��硰cout << c<<5����
��cout<< <c������operator<<��OS���õľ���cout

��cin���븴��ʱ����Ӧ�����˱����ǡ�a+ bi���ĸ�ʽ�������м䲻���пո������롰13.2+33.4i������is>> s����
����һ���ַ������������Ҫ���ַ����е�ʵ��a���鲿b�������������İ취�����ҳ�����+�������������Ӵ���Ȼ�������ִ�ת���ɸ�������
�����˱�׼�⺯��atof �����ַ���ת��Ϊ���������ú���ԭ���ǣ�float atof��const char*������cstdlibͷ�ļ���������*/
