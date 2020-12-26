//program 20.3.1.cpp auto_ptrʾ��1
#include <iostream>
#include <memory>
using namespace std;
class A 
{
public:
	int i;
	A(int n):i(n) { };
	~A() { cout << i << " " << "destructed" << endl; }
};
int main() 
{
	auto_ptr<A> ptr(new A(2)); // new�����Ķ�̬�����ָ�룬����ptr�й�
   cout << ptr->i << endl;    // ��� 2
	ptr->i = 100;              //��̬����� i ��Ա������Ϊ 100
   	A a(*ptr);                 // * ptr����ǰ�� new �Ķ�̬����
	cout << a.i << endl;       //��� 100
	a.i = 20;  
	return 0;
}

