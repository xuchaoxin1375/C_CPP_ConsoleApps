//program 12.1.3.3.cpp  ���ƹ��캯�����ں����β�v
#include <iostream>
using namespace std;
class A 
{
   public:
   A() { };
   A( A & a) { 
   	  cout << "Copy constructor called" <<endl;
   }		
};
void Func(A a)
{
}
int main(){
	A a;
	Func(a);
	return 0;
}

