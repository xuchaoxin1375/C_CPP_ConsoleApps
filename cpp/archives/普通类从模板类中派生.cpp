#include<iostream>
using namespace std;
/*���õ�ģ����,�ͱ��붨��һ����ģ��,Ȼ��Ӳ��ܴ���ģ�尴����ʵ������ĳ��ģ����*/

template<class T>
class A
{
	T v1;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
	}
};

/*��ͨ��B �� ģ����A<int> ����*/
class B :public A<int>//ģ����A<int>
{
	int a;
public:
	B(int a_ = 0) :a(a_) { cout << "constructor was called !" << endl; }
	void set(int a_)
	{
		a = a_;
	}
	void print()
	{
		cout << "a=" << a << endl;
	}
};
int main()
{
	B obj(5);
	obj.print();
	obj.set(7);
	obj.print();
}