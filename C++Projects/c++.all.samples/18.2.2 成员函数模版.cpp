//program 18.2.2.cpp  ��Ա����ģ��
#include <iostream>
using namespace std;

/*����ģ������T
��ģ��A:*/
template <class T> //���п���û�еĻ��Ͳ�����ģ����
class A/*��ģ����*/
{
	T x;
public:
	A(T x_ = 1) :x(x_)
	{
		cout << "constructor was called" << endl;
		cout << "x=" << x << endl;
	}
	/*�õ�ģ������T2�ĳ�Ա����ģ��(����ǰ,��Ҫ����ʵ�����ſ�,��֮Ϊģ��)*/
	template<class T2>  /*����ר������ģ����Ϊ��Ա����ģ�嶨��һ���µ�ģ������T2*/
	void Func(T2 t) { cout << t << endl; } //��Ա����ģ��
};
int main()
{
	A<int> a;
	//A a;
	a.Func('K'); //��Ա����ģ�� Func��ʵ����(ģ������T2��char���)
	return 0;
}
