#include<iostream>>
using namespace std;
class A
{
public:
	virtual void Print()
	{
		cout << "A::Print" << endl;
	}
};

class B :public A
{
public:
	virtual void Print()
	{
		cout << "B::Print" << endl;
	}
};

void Print(A& r)//�β�ʹ��A�ܹ�ͬʱ���ݴ���Ļ���A�Ͷ���(������),Ҳ�ܹ����ݴ����������(������)
{
	r.Print();
}

int mian()
{
	A a;
	B b;
	Print(a);
	Print(b);
	return 0;
}