#include<iostream>
using namespace std;

/*��ͨ��A*/
class A
{
protected:
	int v1;
	double v2;
public:
	void print()
	{
		cout << "v1=" << v1 << endl;
		cout << "v2=" << v2 << endl;
	}
	void setA(int v1_, double v2_)
	{
		v1 = v1_; v2 = v2_;
	}
};

template<class T>
class B :public A
{
	/*��ǰ�ӻ���A�̳й������г�Ա*/
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
	obj.setA(7, 7.677);
	obj.setB('N');
	obj.A::print();
	obj.print();
	return 0;
}