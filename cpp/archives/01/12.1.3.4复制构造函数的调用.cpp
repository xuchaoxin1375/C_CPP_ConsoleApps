//program 12.1.3.4.cpp  ���ƹ��캯�����ں������ض���
#include <iostream>
using namespace std;

class A 
{
   public:
   int v;
   /*��ͨ���캯��(���ڳ�ʼ������)*/
   A(int n) { v = n; };

   /*���ƹ��캯��:*/
   A( const A & a) { 
  	  v = a.v;
   	  cout << "Copy constructor called" <<endl;
   }		
};
A Func()
{
   A a(4);/*���ù��캯����ʼ������a,����ֱ�Ӹ��ڶ���a����,��������������,����������ú���,��ʵҲ��ȷ�����˺���,�����������Ǻ�������ͬ�Ĺ��캯��,���ﺯ����û��д(A),�����ֲ���һ�������ϵĵ��ú���*/
   return a;/*���ձ�׼C++�Ļ�,����ø��ƹ��캯��*/
}
int main(){
	cout << Func().v << endl;
	return 0;
}

