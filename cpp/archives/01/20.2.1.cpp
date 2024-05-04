//program 20.2.1.cpp typeid��type_info�÷�ʾ��
//(�������޸���http://www.cplusplus.com/reference/std/typeinfo/type_info/)
#include <iostream>
#include <typeinfo> //Ҫʹ��typeinfo����Ҫ��ͷ�ļ�
using namespace std;
struct Base { };    //�Ƕ�̬����
struct Derived : Base { };
struct Poly_Base {virtual void Func(){ } }; //��̬����
struct Poly_Derived: Poly_Base { };
int main() 
{
  //��������
  long i;  int * p = NULL;
  cout << "1) int is: " << typeid(int).name() << endl; //��� 1) int is: int
  cout << "2) i is: " << typeid(i).name() << endl; //��� 2) i is: long
  cout << "3) p is: " <<  typeid(p).name() << endl; //��� 3) p is: int *
  cout << "4) *p is: " <<  typeid(*p).name() << endl ; //��� 4) *p is: int
  //�Ƕ�̬����
  Derived derived;
  Base* pbase = &derived;
  cout << "5) derived is: " << typeid(derived).name() << endl; 
        //��� 5) derived is: struct Derived
  cout << "6) *pbase is: " << typeid(*pbase).name() << endl; 
        //��� 6) *pbase is: struct Base
  cout << "7) " << (typeid(derived)==typeid(*pbase) ) << endl; //��� 7) 0
  // ��̬����
  Poly_Derived polyderived;
  Poly_Base* ppolybase = &polyderived;
  cout << "8) polyderived is: " << typeid(polyderived).name() << endl;
        //��� 8) polyderived is: struct Poly_Derived
  cout << "9) *ppolybase is: " << typeid(*ppolybase).name() << endl;
        //��� 9) *ppolybase is: struct Poly_Derived
  cout << "10) " << (typeid(polyderived)!=typeid(*ppolybase) ) << endl; //��� 10) 0
}

