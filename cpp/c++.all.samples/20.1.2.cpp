//program 20.1.2.cpp reinterpret_castʾ��
#include <iostream>
using namespace std;
class A
{ 
  public:
	 int i;	
	 int j;
	 A(int n):i(n),j(n) { }
};
int main() 
{ 
	  A a(100);
	  int & r = reinterpret_cast<int&>(a); //ǿ���� r ���� a 
	  r = 200;  //�� a.i ����� 200 
	  cout << a.i << "," << a.j << endl;  // ��� 200,100 
	  int n = 300;
	  A * pa = reinterpret_cast<A*> ( & n); //ǿ���� pa ָ�� n 
	  pa->i = 400;	 // n ��� 400 
 	  pa->j = 500;  //������䲻��ȫ���ܿ��ܵ��³������
	  cout << n << endl;  // ��� 400
	  long long la = 0x12345678abcdLL; 
	  pa = reinterpret_cast<A*>(la); // la̫����ֻȡ��32λ0x5678abcd������pa 
	  unsigned int u = reinterpret_cast<unsigned int>(pa); //pa������ؿ�����u 
	  cout << hex << u << endl;  //��� 5678abcd
	  typedef void (* PF1) (int);
	  typedef int (* PF2) (int,char *);  
	  PF1 pf1;	  PF2 pf2;
	  pf2 = reinterpret_cast<PF2>(pf1); //������ͬ���͵ĺ���ָ��֮����Ի���ת�� 
}  

