//program 18.5.4.cpp ��ģ����Ϊ��ģ�����Ԫ
#include <iostream>
using namespace std;
template <class T>
class A
{
	public:
		void Func( const T & p)
		{
			cout << p.v;
		}
};
template <class T>
class B
{
	private :
		T v;
	public:
		B(T n):v(n) { }
	template <class T2>
	friend class A;  //����ģ��A����Ϊ��Ԫ
};
int main()
{
	B<int> b(5);
	A< B<int> > a; //��B<int>�滻Aģ���е�T
	a.Func (b);
	return 0;
}
