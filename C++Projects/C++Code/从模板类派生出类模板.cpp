#include<iostream>
using namespace std;
//��ģ������������ģ��
/*��ģ��A*/
template <class T1 ,class T2 >
class A
{
protected:
	T1 v1;
	T2 v2;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
		cout << "v2=" << v2 << endl;
	}
	void setA(T1 v1_,T2 v2_)
	{
		v1 = v1_; v2 = v2_;
	}
};

template<class T>
class B :public A<int, double>//A<int,double>�Ǿ����ģ����;��ģ��B�ӻ���A<int,double>������������
{
	/*��ǰ��A<int,double>����̳й������г�Ա*/
	T v;
public:
	void print()
	{
		cout << "v=" << v << endl;
	}

	void setB(T v_)
	{
		v = v_;
	}
};
int main()
{
	B<char> obj;
	/*��ʱ�������Ѿ���������ģ����:B<char>�����Ļ���A<int,double>*/
	obj.setA(7, 7.77);
	obj.setB('N');
	obj.A<int, double>::print();
	obj.print();
	return 0;
}