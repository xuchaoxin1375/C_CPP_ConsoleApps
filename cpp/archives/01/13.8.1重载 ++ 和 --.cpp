//program 13.8.1.cpp, ���� ++ �� --
#include <iostream>
using namespace std;
class CDemo {
  private :
	int n;
  public:
	CDemo(int i=0):n(i) { }//constructor
	CDemo operator++();      //����ǰ����ʽ
	CDemo operator++( int );   //���ں�����ʽ

     operator int ( ) { return n; }//overload_operator_int
     friend CDemo operator--(CDemo & );
     friend CDemo operator--(CDemo & ,int);    
};
CDemo CDemo::operator++()
{//ǰ�� ++
	n ++;
	return * this;
}
CDemo CDemo::operator++( int k )
{ //���� ++
	/*���÷�ʽ�����غ����У�Ҫ������һ���ֲ�����tmp;��������ɻ��������캯��(�����Ǹ��ƹ��������ã���Ҫ�ķ�ʱ�䡣*/
	CDemo tmp(*this); //��¼�޸�ǰ�Ķ���(���ƹ��캯���Ĳ����Ƕ��������(���������Ҳ�Ǽ��ݵ�,�ں������ڲ����ǻ��Ϊ����)
	n ++;/*Ϊ������,д��n+=1����(����nֻ�ǻ�����������++Ҳͦ��*/
	return tmp; //����  �޸�ǰ�� ����
}
CDemo operator--(CDemo & d) 
{//ǰ��--
 	  d.n--;
	  return d; 	  
}
CDemo operator--(CDemo & d,int) 
{//����--
 	 CDemo tmp(d);
	 d.n --;
	 return tmp;  
}    
int main()
{
	CDemo d(5);
	cout << "d==" << d << ",";
	cout <<"(d++) ==" <<(d++ ) << ",";  //�ȼ��� d.operator++(0);���ص�������ǰ��ֵ;
	cout << "d=="<<d << ",";
	cout << endl;
	cout <<"++d==" <<(++d) << ",";   //�ȼ��� d.operator++();
	cout << "d="<<d << endl;
	cout << "(d--)="<<(d-- ) << ",";  //�ȼ��� operator-(d,0);
	cout << "d=" << d << ",";
	cout << "--d=="<<(--d) << ",";   //�ȼ��� operator-(d);
	cout << "d=" << d << endl;
	return 0;
}

/*�����򽫡�++������Ϊ��Ա������
����--������Ϊȫ�ֺ�����
��ʵ������Ϊ��Ա��������,���ｫ��--������Ϊȫ�ֺ���ֻ��Ϊ��˵��������ô�����ѡ�

���ú�����ʽ�����غ���ʱ�������Ǹ�û�õ�int�βΣ��������Զ���0��Ϊʵ�Ρ�
��d++���ȼ��ڡ�d.operator ++��0������

�Ա�ǰ�á�++���ͺ��á�++�������أ����Է��֣�
���á�++����ִ��Ч�ʱ�ǰ�õĵ͡���Ϊ���÷�ʽ�����غ����У�Ҫ������һ���ֲ�����tmp��
����������ɻ��������캯�����ã���Ҫ�ķ�ʱ�䡣ͬ�����á�--����ִ��Ч��Ҳ��ǰ�õĵ͡�
���еı������У���VisualStudio2010�������û�к�����ʽ�����أ���ô������ʽ�ģ��������Լ����ʽҲ������ǰ����ʽ����
�����еı������У���Dev C++���������к�����ʽ�����أ���ô������ʽ�ı��ʽ�ͻ�������*/