//program 15.1.1.cpp��̬��Ͷ�̬�Ĺ���
/*���û�����������ж��е�ͬ����ͬ��������麯�� �����,�Ƿ��϶�̬��������.*/
/*��̬���������ĸ���ĳ�Ա��������������ʱ����ȷ���ģ�����ʱ����ȷ����
��˶�̬�ĺ���������˾����Ϊ�ǡ���̬���ࡱ�ģ�����ͨ�ĺ���������䱻��Ϊ�ǡ���̬���ࡱ�ġ�

����Print���麯��������pa�ǻ���A��ָ�룬����ʱҲ����ȷ�����õ����ĸ����Print();(���ܹ���̬���������ڱ����ʱ���ȷ����ָ��pa�������Ǹ����Print();
���������е� ��Ӧ���ʱ,paָ������ĸ���Ķ��󣬱����õľ����ĸ����Print(����ָ��Ķ����������������������Ǹ����Print();
���磬����ִ�е���26��ʱ��paָ����ǻ������a,�Ǿ͵��õ��ǻ����е�Print();*/
#include < iostream >
using namespace std;
class A
{
public:
	virtual void Print()
	{
		cout << "A::Print" << endl;
	}
};/*�����֮����;����*/

class B :public A
{
public:
	virtual void Print()
	{
		cout << "B::Print" << endl;
	}
};
class D :public A
{
public:
	virtual void Print() { cout << "D::Print" << endl; }
};
class E :public B
{
	virtual void Print() { cout << "E::Print" << endl; }
};

int main()
{
	A a;
	B b;
	D d;
	E e;
	A* pa = &a;
	B* pb = &b;

	pa->Print();
	pa = pb;
	pa->Print();
	pa = &d;
	pa->Print();
	pa = &e;
	pa->Print();
	return 0;
}

//��̬,a.Print()������,���:A::Print pa = pb;
//����ָ��paָ�����������b pa-> Print();
//b.Print()������,���:B::Print pa =&d;
//����ָ��paָ�����������d pa-> Print();
//��̬,d.Print()������,���:D::Print pa =&e;
//����ָ��paָ�����������d pa-> Print();
//��̬,e.Print()������,���:E::Print return 0;
