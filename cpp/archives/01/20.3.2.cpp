//program 20.3.2.cpp auto_ptrʾ��2
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
	auto_ptr<A> ptr1(new A(2)); //A(2)��ptr1�йܣ�
	auto_ptr<A> ptr2(ptr1);     //A(2)����ptr2�йܣ�ptr1ʲô�����й� 
	auto_ptr<A> ptr3;
	ptr3 = ptr2;             //A(2)����ptr3�йܣ� ptr2ʲô�����й�
	cout << ptr3->i << endl; //��� 2
	A * p = ptr3.release();  // p ָ�� A(2)��ptr3�����A(2)�й�  
	ptr1.reset(p);           //ptr1�����й� A(2)
	cout << ptr1->i << endl; //��� 2
	ptr1.reset(new A(3));    // delete ��A(2), �й�A(3)����� 2 destructed
	cout << "end" << endl;
	return 0; //���������ptr1����ʱ����delete ��A(3)
}

