/*
* ��������Ϊ��ָ������
����������������X��ָ�룬��ô�ͻ���Ϊͨ�������ʵľ�Ӧ������X�ĳ�Ա��
��:���������������ĸ����ָ�룬��ô�ͻ���Ϊͨ�������ʵģ���Ӧ�����ĸ���ĳ�Ա��
*/
#include < iostream >
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A::Print" << endl;
	}
};/*�����֮����;����*/

class B :public A
{
public:
	void Print()
	{
		cout << "B::Print" << endl;
	}
};

int main()
{
	A a;
	B b;


	A* pa = &a;
	B* pb = &b;

	pa->Print();
	pa = pb;
	pa->Print();


	return 0;
}
