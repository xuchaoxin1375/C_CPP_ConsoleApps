//program 14.5.1.cpp ������������µĹ��캯������������
#include <iostream>
using namespace std;
class A {
	public:
		int n;
		A(int i):n(i)  {  cout << "A " << n << " constructed" << endl;}
		~A() {	cout << "A " << n << " destructed" << endl;	}
};
class B:public A
{
	public:
		B(int i):A(i) { cout << "B constructed" << endl;}
		~B() {	cout << "B destructed" << endl;	}

};
/*��������:*/
class C:public B {
public:
	C() :B(2)/*2����B��Ĺ��캯��,B�Ĺ��캯���ٽ�2����A��Ĺ��캯��,��A���еĳ�Ա����n��ʼ��=2*/
	{
		cout << "B constructed" << endl;
	}
	~C() {	cout << "C destructed" << endl;	}
};
int main()
{
	C Obj; 
	return 0;
}
