
//program 18.5.3.cpp  ��Ҳ���Խ� ����ģ������Ϊ��Ԫ
#include <iostream>
using namespace std;

class A
{
	int v;
public:
	A(int n) :v(n)
	{
		cout << "A:: theconstructor was called!" << endl;
	}

	template <class T>
	friend void Print(const T& p);//ȫ�ֺ���ģ��Print<T>ʵ����������ģ�庯���Ϳ��Է���A����������˽�г�Ա;
};
/*ȫ�ֺ���ģ��Print(������ĳ����Ķ���)*/
template <class T>
void Print(const T& p)
{
	cout <<"p.v="<< p.v<<endl;
}

int main()
{
	A a(4);
	/*����ȫ�ֺ���ģ����ʵ������ģ�庯��:�˴��ĺ���ģ���ʵ����ͨ������a��ʽʵ������ģ�庯��Print<const A& p>*/
	Print(a);
	return 0;
}

