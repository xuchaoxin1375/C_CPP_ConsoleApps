//program 18.5.4.cpp ��ģ����Ϊ��ģ�����Ԫ
/*��...����Ϊ��ǰ�����Ԫ,��ô��Ҫ��������(��/��Ա����/ȫ�ֺ���(�����ǵ�ģ��))����˷��ʵ�ǰ���˽�г�Ա����Ȩ;
Ҫôͨ������(���������ߵĶ���Ϊ����)����ʽ����,Ҫôͬ����Ա����ķ�ʽ�����ʳ�Ա�����˽�г�Ա.*/
#include <iostream>
using namespace std;
/*��ģ��A*/
template <class T>
class A
{
	T a;//���T��һ���Զ�����(�ǻ�������),��ôA����Ϊһ�������
	public:
		A(T a_=0) :a(a_)
		{
			cout << "A::constructor was called!"<<endl;
		}
		void Func( const T & p)
		{
			cout << "p.v=" << p.v << endl;
		}
};
/*��ģ��B*/
template <class T>
class B
{
	private :
		T v;
	public:
		B(T n):v(n) 
		{
			cout << "B::constructor was called !" << endl;
		}
	/*//����ģ��A����Ϊ��Ԫ*/
	template <class T2>
	friend class A;  
};//ģ����A(ʵ��������ģ�����еĺ��������������B���Ա�������˷�����Ȩ);
int main()
{
	B<int> obj_b(5);

	A<float> obj_a1(3.14);
	A< B<int> > obj_a2(4); /*��B<int>�滻Aģ���е�T,�Ա�A����"��Ԫ��ϵ"������ģ��B��ĳ��ʵ������ģ����Ķ���(��B<int>����double/float֮����������Ϳ�;�ڱ������У�A<B<int>>�࣬����B<int >�����Ԫ��
					  ���������A���Ѿ��Ƿ����,A�ĳ�Աa�ѱ�� ��Ա����,��������B<int>,�����B<int>�Ĺ��캯���Գ�ʼ��a��Ա*/
	/*������Ԫ������*/
	obj_a2.Func (obj_b);//Func����A�ĺ���,���Է���B���(��Ա����)��˽�г�Ա;������Է��ʵ�B<int> ���͵Ķ���obj_b
	return 0;
}
